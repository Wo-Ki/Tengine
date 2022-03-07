#include "odla_executor.hpp"

extern "C" {
#include "operator/op.h"
#include "convolution_param.h"
}

#define batch             1 //batch
#define trunc_mac         0
#define trunc_sum_out_par 0
#define trunc_add         0
#define trunc_bias        0
#define activ_mode1       0 // 激活函数类型：0：直通；1：relu；2：sigmoid；3：tanh
#define Resp_Type         1 //0：查询方式; 1：中断模式

void HCWEngine::FullyConnectionFunc(struct node* ir_node)
{
    struct graph* ir_graph = ir_node->graph;
    struct subgraph* subgraph = get_ir_graph_subgraph(ir_graph, ir_node->subgraph_idx);

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* weight_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);
    struct tensor* bias_tensor;
    if (2 < ir_node -> input_num)
        bias_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[2]);
    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);

    if (RegEnable())
    {
        setFC(
            subgraph -> input_num,
            subgraph -> output_num,
            batch,
            0,
            trun_add,
            trunc_mac,
            activ_mode1,
            0, 0,
            trunc_bias,
            0,
            0, input_tensor -> data, 0, weight_tensor -> data, 0, bias_tensor -> data,
            0, output_tensor -> data,
            Resp_Type, 0, 0
        );
    }
    printf("Fc config done! \n");
    cal_resp_proc(Resp_Type);
    printf("Fc done %d/16	 \n");
}

/*
int setFC(u32 fc_L, u32 fc_Nu, u32 fc_batch, u32 fc_softmax,
          u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 activ_bit1, u32 activ_res_bit1,
          u32 trunc_bias, u32 trunc_sum_out_par,
//          u64 inputAddr1, u64 inputAddr2, u64 inputAddr4,
          u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr4_H, u32 inputAddr4_L,
//          u64 outputAddr,
          u32 outputAddr_H, u32 outputAddr_L,
          u32 RespType, u32 BatchMark, u32 LastConfig) // 看起来LastConfig 约等于 batch_finish
*/