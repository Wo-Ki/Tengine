#include "odla_executor.hpp"

extern "C" {
#include "operator/op.h"
#include "convolution_param.h"
}

#define batch             1 //batch
#define trunc_mac         0
#define trunc_sum_out_par 0
#define Resp_Type         1 //0：查询方式; 1：中断模式

void HCWEngine::ConvolutionFunc(struct node* ir_node)
{
    struct graph* ir_graph = ir_node->graph;
    struct conv_param* param = (struct conv_param*)ir_node->op.param_mem;

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* conv_weight = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);
    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);

    if (RegEnable())
    {
        setConv_small(input_tensor->dim[2], input_tensor->dim[3], output_tensor->dim[2], output_tensor->dim[3], param->kernel_h, param->kernel_w, output_tensor->dim[1], param->input_channel, param->stride_h, param->pad_h0,
                      batch, 3, 0, 0, trunc_mac, trunc_sum_out_par,
                      1, 0, 0,
                      0, input_tensor->data, 0, conv_weight->data, 0, 0,
                      0, 0, 0, output_tensor->data,
                      Resp_Type, 0, 0
        );
    }
    printf("Conv config done! \n");
    cal_resp_proc(Resp_Type);
    printf("Conv done %d/16	 \n");
}

//int setConv_small(u32 n_i_r, u32 n_i_c, u32 n_o_r, u32 n_o_c, u32 f_r, u32 f_c, u32 kernel_num, u32 c, u32 s, u32 p_o,
//                  u32 batch, u32 zero_flag, u32 flag_out, u32 state, u32 trunc_mac, u32 trunc_sum_out_par,
//                  u32 activ_model, u32 activ_bit1, u32 activ_res_bit1,
//                  u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr3_H, u32 inputAddr3_L,
//                  u32 inputAddr4_H, u32 inputAddr4_L, u32 outputAddr_H, u32 outputAddr_L,
//                  u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)