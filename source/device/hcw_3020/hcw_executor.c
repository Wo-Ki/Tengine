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

#include "hcw_executor.h"
#include "graph/tensor.h"
#include "graph/node.h"
#include "graph/graph.h"
#include "graph/subgraph.h"
#include "device/device.h"
#include <stdio.h>

#define _P2V(addr)	(0x9000000000000000 | ((u64)(addr)))	/* physical address to virtual address */

#define     SetReg(_x,_y)       do{ \
(*(volatile u32*)(_P2V(_x))) = (_y);\
}while(0)

#define     ReadReg(_x,_y)       do{ \
(_y) = *(volatile u32*)(_P2V(_x)); \
}while(0)


extern int HCWPoolingFunc(struct node* ir_node);
extern void choose_no(u32 num);
extern void extract_feature_from_tensor_hcw(const char* comment, const char* layer_name, const struct tensor* tensor);

int hcw_dev_init(struct device* dev)
    {
    printf("wk hcw_dev_init\n");
    //	choose_no(0);

    SetReg(0x1f0c0018, 0xa5accede);
    SetReg(0x1f0c0004, 0xee);

    //    sleep(1);
    (void)dev;
    return 0;
    }

    int hcw_dev_prerun(struct device* dev, struct subgraph* subgraph, void* options)
        {
    printf("wk hcw_dev_prerun\n");

    return 0;
        }

        int hcw_dev_run(struct device* dev, struct subgraph* subgraph)
            {
    fprintf(stdout, "wk HCWEngineRun\n");
    struct graph* ir_graph = subgraph->graph;
    /* Input */
    for (uint8_t i = 0; i < subgraph->input_num; i++)
    {
        int ir_tensor_idx = subgraph->input_tensor_list[i];
        struct tensor* ir_tensor = get_ir_graph_tensor(ir_graph, ir_tensor_idx);

        //        fprintf(stdout, "wk HCWEngineRun:input %s\n", ir_tensor->name);
        //        fprintf(stdout, "wk HCWEngineRun:ir_tensor_idx %d\n", ir_tensor_idx);
        char filename[30];
        //		sprintf(filename, "subgraph_%d_tensor_in_", subgraph->index);
        extract_feature_from_tensor_hcw(ir_tensor->name, filename, ir_tensor);
    }

    for (int i = 0; i < subgraph->node_num; i++)
    {
        uint16_t node_id = subgraph->node_list[i];
        struct node* ir_node = get_ir_graph_node(ir_graph, node_id);
        fprintf(stdout, "wk HCWEngineRun:ir_node name: %s\n", ir_node->name);

        if (ir_node->op.type == OP_POOL){
            fprintf(stdout,"wk OP_POOL\n");
            HCWPoolingFunc(ir_node);
        }
        else if(ir_node->op.type == OP_CONV){
            fprintf(stdout,"wk OP_Conv\n");
            HCWConvFunc(ir_node);
        }
        else if(ir_node->op.type == OP_FC){
            fprintf(stdout,"wk OP_FC\n");
            HCWFcFunc(ir_node);
        }
        else if(ir_node->op.type == OP_RELU){
            fprintf(stdout,"wk OP_RELU\n");
            HCWReluFunc(ir_node);

        }
        else
            fprintf(stdout,"wk Unknown OP\n");
    }

    /* Output */
    for (uint8_t i = 0; i < subgraph->output_num; i++)
    {
        int ir_tensor_idx = subgraph->output_tensor_list[i];
        struct tensor* ir_tensor = get_ir_graph_tensor(ir_graph, ir_tensor_idx);
        fprintf(stdout, "wk HCWEngineRun:output %s\n", ir_tensor->name);
    }

    return 0;
            }

            int hcw_dev_postrun(struct device* dev, struct subgraph* subgraph)
                {
    return 0;
                }

                int hcw_dev_release(struct device* dev)
                    {
    (void)dev;
    return 0;
                    }
