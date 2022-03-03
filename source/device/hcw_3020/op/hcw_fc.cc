#include "odla_executor.hpp"

extern "C" {
#include "operator/op.h"
#include "convolution_param.h"
}

#define batch             1 //batch
#define trunc_mac         0
#define trunc_sum_out_par 0
#define Resp_Type         1 //0：查询方式; 1：中断模式

void HCWEngine::FullyConnectionFunc(struct node* ir_node)
{
    struct graph* ir_graph = ir_node->graph;
    struct subgraph* subgraph = get_ir_graph_subgraph(ir_graph, ir_node->subgraph_idx);

    struct tensor* weight_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);

    if (RegEnable())
    {
        setFC(

        );
    }
    printf("Conv config done! \n");
    cal_resp_proc(Resp_Type);
    printf("Conv done %d/16	 \n");
}

int setFC(u32 fc_L, u32 fc_Nu, u32 fc_batch, u32 fc_softmax,
          u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 activ_bit1, u32 activ_res_bit1,
          u32 trunc_bias, u32 trunc_sum_out_par,
          u64 inputAddr1, u64 inputAddr2, u64 inputAddr3, u64 inputAddr4,
          u64 outputAddr, u32 RespType, u32 BatchMark, u32 LastConfig)