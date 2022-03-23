/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2021, Institute of Computing Technology
 * Author: Wo-Ki
 */

#include "hcw_device.h"

#include "hcw_limit.h"
#include "hcw_device.h"

#include <stdio.h>

int hcw_describe(struct device* device, struct vector* allowed_ops, struct vector* blocked_ops, struct vector* precision)
    {
    (void)device;

    //    for (int op_type : hcw_supported_ops)
    //    {
    //        push_vector_data(allowed_ops, &op_type);
    //    }
    for(int  i=0;i<sizeof(hcw_supported_ops)/sizeof(hcw_supported_ops[0]);i++){
        push_vector_data(allowed_ops, &hcw_supported_ops[i]);
    }
    for (int i = 0; i < OP_BUILTIN_LAST; i++)
    {
        boolean in_list = FALSE;

        //        for (const auto& type : hcw_supported_ops)
        //        {
        //            if (type == i)
        //            {
        //                in_list = true;
        //                break;
        //            }
        //        }
        for(int  j=0;j<sizeof(hcw_supported_ops)/sizeof(hcw_supported_ops[0]);j++){
            if(hcw_supported_ops[j]==i){
                //        		printf("wk j==i j:%d\n",hcw_supported_ops[j]);
                in_list = TRUE;
                break;
            }
        }
        if (in_list==FALSE)
        {
            //    		printf("wk j==i i:%d\n",i);

            push_vector_data(blocked_ops, &i);
        }
    }

    // only supprt int8/int16
    int precision_var = TENGINE_DT_INT8;
    push_vector_data(precision, &precision_var);

    return 0;
    }


    int hcw_evaluation(struct device* device, struct subgraph* sub_graph, struct vector* evolution_tensors, struct vector* evolution_nodes)
        {
    // nothing to do
    (void)device;
    (void)sub_graph;
    (void)evolution_tensors;
    (void)evolution_nodes;

    return 0;
        }


        int hcw_allocate(struct device* device, struct subgraph* sub_graph)
            {
    if (NULL == device)
    {
        return -1;
    }

    /* set the correct input wait count: INPUT tensor is always ready */
    sub_graph->input_wait_count = 0;

    for (int i = 0; i < sub_graph->input_num; i++)
    {
        struct tensor* tensor = get_ir_graph_tensor(sub_graph->graph, sub_graph->input_tensor_list[i]);

        if (tensor->tensor_type == TENSOR_TYPE_VAR)
            sub_graph->input_wait_count++;
    }

    return 0;
            }


            int hcw_release(struct device* device, struct subgraph* sub_graph)
                {
    (void)sub_graph;

    return 0;
                }


                int hcw_split_graph(struct graph* ir_graph)
                    {
    printf("wk hcw_split_graph\n");
    struct device* cur_dev = ir_graph->attribute->context->device;

    if (0 != strcmp(HCW_DEV_NAME, cur_dev->name))
    {
        return -1;
    }

    struct vector* allowed_ops = create_vector(sizeof(int), NULL);
    struct vector* blocked_ops = create_vector(sizeof(int), NULL);
    struct vector* precision = create_vector(sizeof(int), NULL);

    cur_dev->allocator->describe(cur_dev, allowed_ops, blocked_ops, precision);

    split_graph_node_to_sub_graph(ir_graph, allowed_ops, blocked_ops, precision);
    //    for(int i=0;i<allowed_ops->elem_num;i++){
    //        printf("wk allowed_ops: %d\n",*(int *)get_vector_data(allowed_ops, i));
    //
    //    }
    //    for(int i=0;i<blocked_ops->elem_num;i++){
    //        printf("wk blocked_ops: %d\n",*(int *)get_vector_data(blocked_ops, i));
    //
    //    }
    release_vector(allowed_ops);
    release_vector(blocked_ops);
    release_vector(precision);

    //
    generate_sub_graph_io(ir_graph);
    add_sub_graph_to_ir_graph(ir_graph);

    // add node sub graph id
    for (int i = 0; i < (uint16_t)get_vector_num(ir_graph->subgraph_list); i++)
    {

        struct subgraph* sub_graph = *(struct subgraph**)get_vector_data(ir_graph->subgraph_list, i);
        sub_graph->index = i;
        printf("wk sub_graph name:%s\n", sub_graph->device->name);

        for (uint16_t j = 0; j < sub_graph->node_num; j++)
        {
            uint16_t node_id = sub_graph->node_list[j];
            struct node* ir_node = get_ir_graph_node(ir_graph, node_id);
            printf("wk ir_node name:%s, %d\n", ir_node->name, ir_node->op.type);

            ir_node->subgraph_idx = sub_graph->index;
        }
    }

    return 0;
                    }



                    static struct interface hcw_interface = {
    .init           = hcw_dev_init,
    .pre_run        = hcw_dev_prerun,
    .run            = hcw_dev_run,
    .post_run       = hcw_dev_postrun,
    .async_run      = NULL,
    .async_wait     = NULL,
    .release_graph  = NULL,
    .release_device = hcw_dev_release,
    };


static struct allocator hcw_allocator = {
    .describe       = hcw_describe,
    .evaluation     = hcw_evaluation,
    .allocate       = hcw_allocate,
    .release        = hcw_release,
    };


static struct optimizer hcw_optimizer = {
    .split_graph    = hcw_split_graph,
    .optimize_graph = NULL,
    };



static struct hcw_device hcw_dev = {
    .base = {
        .name       = HCW_DEV_NAME,
        .interface  = &hcw_interface,
        .allocator  = &hcw_allocator,
        .optimizer  = &hcw_optimizer,
        .scheduler  = NULL,
        .privacy    = NULL,
        },
        };


int register_hcw_device(void)
{
    int ret = register_device_t(&hcw_dev.base);
    if (0 != ret)
    {
        printf("Tengine plugin %s register failed.\n", hcw_dev.base.name);
        return -1;
    }

    printf("Tengine plugin device %s is registered.\n", hcw_dev.base.name);
    return 0;
}


int unregister_hcw_device(void)
{
    int ret = unregister_device_t(&hcw_dev.base);
    if (0 != ret)
    {
        TLOG_INFO("Tengine plugin %s unregister failed.\n", hcw_dev.base.name);
        return ret;
    }

    TLOG_INFO("Tengine plugin device %s is unregistered.\n", hcw_dev.base.name);

    return 0;
}

