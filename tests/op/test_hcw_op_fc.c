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
 * Author: Wo-Ki
 */

#include "test_op.h"

#include "../operator/prototype/fc_param.h"

int float_mismatch(float* current, float* reference, int size)
{
    for (int i = 0; i < size; i++)
    {
        float tmp = fabs(current[i]) - fabs(reference[i]);
        fprintf(stderr, "index:%d, a:%f, b:%f\n", i, current[i], reference[i]);
        if (fabs(tmp) > 0.5)
        {
            fprintf(stderr, "test failed, index:%d, a:%f, b:%f\n", i, current[i], reference[i]);
            return -1;
        }
    }
    fprintf(stderr, "test pass\n");

    return 0;
}

int create_test_fc_node(graph_t graph, const char* input_name, const char* node_name, int data_type, int layout, int n, int c, int h, int w)
{
    (void)layout;
    (void)n;
    (void)c;
    (void)h;
    (void)w;

    /* create the test node */
    struct node* test_node = (struct node*)create_graph_node(graph, node_name, "FullyConnected");

    tensor_t input_tensor = get_graph_tensor(graph, input_name);

    if (NULL == input_tensor)
    {
        fprintf(stderr, "create test node failed.\n");
        return -1;
    }

    /* create the sub node to product another input tensors which the test node is needed, such as weight/bias/slope tensor. */
    /* weight */
    node_t weight_node = create_graph_node(graph, "weight", "Const");
    tensor_t weight_tensor = create_graph_tensor(graph, "weight", TENGINE_DT_INT8);
    set_node_output_tensor(weight_node, 0, weight_tensor, TENSOR_TYPE_CONST);
    int weight_dims[2] = {86, 16}; // channel num
    set_tensor_shape(weight_tensor, weight_dims, 2);

    /* bias */
    node_t bias_node = create_graph_node(graph, "bias", "Const");
    tensor_t bias_tensor = create_graph_tensor(graph, "bias", TENGINE_DT_INT32);
    set_node_output_tensor(bias_node, 0, bias_tensor, TENSOR_TYPE_CONST);
    int bias_dims[1] = {86};  // channel num
    set_tensor_shape(bias_tensor, bias_dims, 1);

    /* input tensors of test node */
    set_node_input_tensor(test_node, 0, input_tensor);
    set_node_input_tensor(test_node, 1, weight_tensor);
    set_node_input_tensor(test_node, 2, bias_tensor);

    /* output tensors of test node */
    tensor_t output_tensor = create_graph_tensor(graph, node_name, data_type);
    set_node_output_tensor(test_node, 0, output_tensor, TENSOR_TYPE_VAR);

    /* set params */
    struct fc_param* param = (struct fc_param*)(struct node*)test_node->op.param_mem;

    param->num_output = 86;

    return 0;
}



int test_hcw_op_fc_main()
{
    /* quant params */
    /*
     * scale = (max(abs(min), abs(max))) / 127
     * zero_point = 0
     * float32 = int8 * scale
     */
    float input_scale = 0.03937f;
    float weight_scales[86] = {};
    float output_scale = 0.2007874f;
    int input_zero_point = 0;
    int weight_zero_point[2] = {0, 0};
    int output_zero_point = 0;

    /* float32 data */
    //    float reference_out[] = {75,75,};
    float reference_out[86] = {};

    //    float input_data[3] = {1, 2, 1};

    int8_t weight_data[86*16] = {
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0, 1,   0,   1, -1, 0, -1, 1, 0, 2,0,0,0,0,0,0,0,
        };

    int32_t bias_data[86] = {0};

    /* int8 data */
    /* int8 = clip(round(float32 / scale), -127, 127) */
    int8_t input_i8_data[16] = {25, 40, 25, 25, 40, 25, 25, 40, 25, 40,0,0,0,0,0,0};


    int n = 1, c = 16, h = 1, w = 1;
    const char* test_node_name = "fc";
    int data_type = TENGINE_DT_INT8;
    int layout = TENGINE_LAYOUT_NCHW;

    // init
    int ret = test_graph_init();
    if (0 != ret)
        fprintf(stderr, "Tengine init failed.\n");

    // create
    struct graph* ir_graph = (struct graph*)create_hcw_test_graph(test_node_name, data_type, layout, n, c, h, w, &create_test_fc_node,4);
    if (NULL == ir_graph)
        return -1;

    //    set_log_level(LOG_INFO);
    //    dump_graph(ir_graph);

    // set quantize params
    struct tensor* input_tensor = (struct tensor*)get_graph_tensor(ir_graph, "input_node");
    struct tensor* weight_tensor = (struct tensor*)get_graph_tensor(ir_graph, "weight");
    struct tensor* bias_tensor = (struct tensor*)get_graph_tensor(ir_graph, "bias");
    struct tensor* output_tensor = (struct tensor*)get_graph_tensor(ir_graph, "fc");

    tensor_t weight_tesnor = get_graph_input_tensor(ir_graph, 1, 0);
    set_tensor_quant_param(input_tensor, &input_scale, &input_zero_point, 1);
    set_tensor_quant_param(weight_tensor, weight_scales, &weight_zero_point, 2);
    set_tensor_quant_param(output_tensor, &output_scale, &output_zero_point, 1);

    // set input data
    set_tensor_buffer(input_tensor, input_i8_data, 16 * sizeof(int8_t));

    // set weight data
    set_tensor_buffer(weight_tensor, weight_data, 1376 * sizeof(int8_t));

    // set bias data
    set_tensor_buffer(bias_tensor, bias_data,86 * sizeof(int32_t));
    ret = test_graph_run(ir_graph);
    if (0 != ret)
    {
        fprintf(stderr, "Run graph error. ERRNO: %d.\n", ret);
        test_graph_release(ir_graph);
        return -1;
    }
    //    printf("Re run...");
    //    ret = test_graph_run(ir_graph);
    //    if (0 != ret)
    //    {
    //        fprintf(stderr, "Run graph error. ERRNO: %d.\n", ret);
    //        test_graph_release(ir_graph);
    //        return -1;
    //    }

    /* get output and dequant int8 to fp32 */
    int output_size = output_tensor->elem_num;
    printf("output_size:%d\n",output_size );
    int8_t* output_int8 = (int8_t*)output_tensor->data;

    //    std::vector<float> output_fp32(output_size);
    float* output_fp32 = (float*)malloc(output_size * sizeof(float));

    printf("output_int8[i]:\n");
    for (int i = 0; i < output_size; i++)
        //        output_fp32[i] = (float)output_int8[i] * output_scale;
        {
        output_fp32[i] = (float)output_int8[i];
        printf("%d ",output_int8[i] );
        }

    /* check the result */
    ret = float_mismatch(output_fp32, reference_out, output_size);
    exit(-1);

    if (ret == 0)
        fprintf(stderr, "test pass.\n");
    else
        fprintf(stderr, "test failed.\n");
    // exit
    test_graph_release(ir_graph);

    return ret;
}
