#include "../hcw_executor.hpp"
extern "C" {
#include "operator/op.h"
#include "pooling_param.h"
}

#define height_flag 0 //大小点计算表示
#define mode        0 //0：二维输入;1：一维输入
#define Resp_Type   1 //0：查询方式; 1：中断模式

void HCWEngine::PoolingFunc(struct node* ir_node)
{
    struct graph* ir_graph = ir_node->graph;
    struct pool_param* param = (struct pool_param*)ir_node->op.param_mem;

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);
    uint16_t output_size = calc_output_size(input_tensor->dim[2], aram->kernel_h, param->stride_h, param->pad_h0, 3);
    int16_t* output_data = (int16_t*)malloc(output_size);
    if (param->pool_method == 0)
    { // max pool
        if (RegEnable())
        {
            setPool(1, height_flag, mode, param->kernel_h, param->stride_h, input_tensor->dim[1], param->pad_h0, input_tensor->dim[2],
                    0, 0,
                    0, input_tensor->data, 0, 0, 0,
                    0, 0, 0, 0, output_data,
                    Resp_Type, 0, 0);
        }
        printf("POOL1 config done! %d/16	\n",pp+1);
        cal_resp_proc(Resp_Type);
        printf("POOL1 done %d/16	 \n",pp+1);
        output_tensor->data = output_data;

    }
    else
    {
        fprintf(stderr, "PoolingFun Error: Only support Max Pool,exit...");
        return;
    }
}

//int setPool(u32 max_or_avg, u32 height_flag, u32 mode, u32 F, u32 S, u32 channel, u32 zero, u32 N,
//            u32 add_trunc, u32 mul_trunc,
//            u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr3_H,
//            u32 inputAddr3_L, u32 inputAddr4_H, u32 inputAddr4_L, u32 outputAddr_H, u32 outputAddr_L,
//            u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
