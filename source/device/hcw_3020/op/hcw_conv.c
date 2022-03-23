#include "operator/op.h"
#include "convolution_param.h"
#include <stdio.h>

#include "graph/tensor.h"
#include "graph/node.h"
#include "graph/graph.h"
#include "graph/subgraph.h"
#include "module/module.h"
#include "utility/vector.h"
#include "utility/log.h"
#include <sys/types.h>
#include "../hcw_define.h"

#define HEIGHT_FLAG 0 //å¤§å°ç¹è®¡ç®è¡¨ç¤º
#define MODE        0 //0ï¼äºç»´è¾å¥;1ï¼ä¸ç»´è¾å¥
#define RESP_TYPE   0 //0ï¼æ¥è¯¢æ¹å¼; 1ï¼ä¸­æ­æ¨¡å¼
#define BATCH 1
#define TRUNC_MAC 0
#define TRUNC_SUM_OUT_PAR 0

#define _P2V(addr)	(0x9000000000000000 | ((u64)(addr)))	/* physical address to virtual address */

#define     SetReg(_x,_y)       do{ \
(*( u32*)(_P2V(_x))) = (_y);\
}while(0)

#define     ReadReg(_x,_y)       do{ \
(_y) = *( u32*)(_P2V(_x)); \
}while(0)

extern void extract_feature_from_tensor_hcw(const char* comment, const char* layer_name, const struct tensor* tensor);
extern int setConv_small(u32 n_i_r,u32 n_i_c,u32 n_o_r,u32 n_o_c,u32 f_r,u32 f_c,u32 kernel_num,u32 c,u32 s,u32 p_o,
                         u32 batch,u32 zero_flag,u32 flag_out,u32 state,u32 trunc_mac,u32 trunc_sum_out_par,
                         u32 activ_model,u32 activ_bit1,u32 activ_res_bit1,
                         u32 inputAddr1_H,u32 inputAddr1_L,u32 inputAddr2_H,u32 inputAddr2_L,u32 inputAddr3_H,u32 inputAddr3_L,
                         u32 inputAddr4_H,u32 inputAddr4_L,u32 outputAddr_H,u32 outputAddr_L,
                         u32 Resp_Type,u32 Batch_mark,u32 Batch_finish);



int HCWConvFunc(struct node* ir_node)
    {

    struct graph* ir_graph = ir_node->graph;
    struct conv_param* param = (struct conv_param*)ir_node->op.param_mem;

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* conv_weight = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);
    struct tensor* conv_bias = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[2]);

    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);

    s16* input_data_s16 = (s16*)malloc(input_tensor->elem_num);
    s16* weight_data_s16 = (s16*)malloc(conv_weight->elem_num+conv_bias->elem_num*16); // *16æ¯ä¸ºäºè¡¥0åå¤
    //    s16* output_data_s16 = (s16*)malloc(output_tensor->elem_num);
    s16 output_data_s16[1024*128];

    int8_t* output_int8 = (int8_t*)malloc(output_tensor->elem_num);

    //    s16 input_data_s16[1024*16];
    //    s16 weight_data_s16[1024*16];
    //
    //    s16 output_data_s16[1024*16];

#ifdef HCW_DEBUG_PRINT
printf("input_tensor->elem_num:%d\n", input_tensor->elem_num);
printf("conv_weight->elem_num:%d\n", conv_weight->elem_num);
printf("conv_bias->elem_num:%d\n", conv_bias->elem_num);
printf("output_tensor->elem_num:%d\n", output_tensor->elem_num);
#endif
//int8 to int16
int8_t* input_tensor_int8 = (int8_t*)input_tensor->data;
for(int i=0;i<input_tensor->elem_num;i++){
    input_data_s16[i] = (s16)input_tensor_int8[i];
}
int8_t* conv_weight_int8 = (int8_t*)conv_weight->data;
int32_t* conv_bias_int32 = (int32_t*)conv_bias->data;

int idx=0,bias_idx=0;
for(int i=0;i<conv_weight->elem_num;i++){
    //    	printf("i=%d:%d ",i, conv_weight_int8[i]);
    weight_data_s16[idx++] = (s16)conv_weight_int8[i];
    if((i+1) % (param->kernel_w*param->kernel_h*param->input_channel) == 0){
        //    		printf("\nparam->kernel_w*param->kernel_h*param->input_channel: %d %d %d %d\n",param->kernel_w*param->kernel_h*param->input_channel,param->input_channel,param->output_channel,conv_weight->dims[1]);
        int32_t bias_tmp = conv_bias_int32[bias_idx++];
        if (bias_tmp > 32767)
            bias_tmp = 32767;
        else if (bias_tmp < -32767)
            bias_tmp = -32767;
        weight_data_s16[idx++] = (s16)bias_tmp;
        printf("bias_idx-1,bias:%d %d\n" ,bias_idx-1,conv_bias_int32[bias_idx-1]);
        int now_count=idx;
        for(int k =0;k<16-now_count%16;k++)weight_data_s16[idx++] = 0;
    }
}
// TODO
//    printf("Conv:\n");
//    for(int i=0;i<(conv_weight->elem_num+conv_bias->elem_num*16);i++){
//    	printf("%d ",weight_data_s16[i]);
//    	if((i+1)%8==0) printf("\n");
//    }
//    exit(-1);
//    printf("\n");
//    printf("wk:conv_weight->elem_num,idx,bias_idx:%d %d %d\n ",conv_weight->elem_num,idx,bias_idx);

u64 input_tensor_phy = hrKmToPhys(input_data_s16);
u64 weight_data_phy = hrKmToPhys(weight_data_s16);
u64 output_data_phy = hrKmToPhys(output_data_s16);
printf("input_tensor_phy,weight_data_phy,output_data_phy: 0x%x  0x%x 0x%x\n",input_tensor_phy,weight_data_phy ,output_data_phy);
if (RegEnable())
{
    setDeviceParam(0,0,0,0,0,1,0,0,0,1,0,0);
    setSlaveMode();
    //    		extract_feature_from_tensor_hcw(input_tensor->name, "test", input_tensor);
    u32 input_tensor_phy_hi =input_tensor_phy>>32;
    u32 input_tensor_phy_lo = input_tensor_phy;
    u32 weight_data_phy_hi = weight_data_phy>>32;
    u32 weight_data_phy_lo = weight_data_phy;
    u32 output_data_phy_hi = output_data_phy>>32;
    u32 output_data_phy_lo = output_data_phy;
    printf("0x%x  0x%x 0x%x  0x%x 0x%x  0x%x\n",input_tensor_phy_hi, input_tensor_phy_lo,weight_data_phy_hi,weight_data_phy_lo,output_data_phy_hi,output_data_phy_lo);
    printf("%d %d %d %d %d %d %d %d %d %d \n",(u32)input_tensor->dims[2], (u32)input_tensor->dims[3], (u32)output_tensor->dims[2], (u32)output_tensor->dims[3],(u32)param->kernel_h, (u32)param->kernel_w, (u32)output_tensor->dims[1], (u32)param->input_channel, (u32)param->stride_h, (u32)param->pad_h0);
    setConv_small((u32)input_tensor->dims[2], (u32)input_tensor->dims[3], (u32)output_tensor->dims[2], (u32)output_tensor->dims[3],(u32)param->kernel_h, (u32)param->kernel_w, (u32)output_tensor->dims[1], (u32)param->input_channel, (u32)param->stride_h, (u32)param->pad_h0,
                  BATCH, 3, 0, 0, TRUNC_MAC, TRUNC_SUM_OUT_PAR,
                  1, 0, 0,
                  input_tensor_phy_hi, input_tensor_phy_lo, weight_data_phy_hi, weight_data_phy_lo, 0, 0,
                  0, 0, output_data_phy_hi, output_data_phy_lo,
                  RESP_TYPE, 0, 0
                  );

}

printf("Conv config done!\n");
cal_resp_proc(RESP_TYPE);
printf("Conv done \n");


//    int8_t* output_tensor_int8 = (int8_t*)output_tensor->data;
printf("output_data_s16:\n");
for(int i=0;i<output_tensor->elem_num;i++){
    //		printf("%d ",output_data_s16[i]);
    int16_t tmp = output_data_s16[i];
    if (tmp > 127)
        tmp = 127;
    else if (tmp < -127)
        tmp = -127;
    output_int8[i] = (int8_t)tmp;
    //		printf("output_int8:%d ",output_int8[i]);
    //	    output_tensor_int8[i] = tmp;
}
output_tensor->data = output_int8;


//    free(input_data_s16);
    }

    //int setConv_small(u32 n_i_r, u32 n_i_c, u32 n_o_r, u32 n_o_c, u32 f_r, u32 f_c, u32 kernel_num, u32 c, u32 s, u32 p_o,
    //                  u32 batch, u32 zero_flag, u32 flag_out, u32 state, u32 trunc_mac, u32 trunc_sum_out_par,
    //                  u32 activ_model, u32 activ_bit1, u32 activ_res_bit1,
    //                  u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr3_H, u32 inputAddr3_L,
    //                  u32 inputAddr4_H, u32 inputAddr4_L, u32 outputAddr_H, u32 outputAddr_L,
    //                  u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
