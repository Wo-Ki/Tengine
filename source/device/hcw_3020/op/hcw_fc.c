#include "operator/op.h"
#include "fc_param.h"
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
#define TRUNC_ADD 0
#define  TRUNC_BIAS 0

#define _P2V(addr)	(0x9000000000000000 | ((u64)(addr)))	/* physical address to virtual address */

#define     SetReg(_x,_y)       do{ \
(*( u32*)(_P2V(_x))) = (_y);\
}while(0)

#define     ReadReg(_x,_y)       do{ \
(_y) = *( u32*)(_P2V(_x)); \
}while(0)

extern void extract_feature_from_tensor_hcw(const char* comment, const char* layer_name, const struct tensor* tensor);
extern int setFC(  u32 fc_L, u32 fc_Nu, u32 fc_batch, u32 fc_softmax,
                   u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 activ_bit1, u32 activ_res_bit1,
                   u32 trunc_bias, u32 trunc_sum_out_par,
                   u64 inputAddr1, u64 inputAddr2, u64 inputAddr3,u64 inputAddr4,
                   u64 outputAddr, u32 RespType, u32 BatchMark, u32 LastConfig);


int HCWFcFunc(struct node* ir_node)
    {
    struct graph* ir_graph = ir_node->graph;
    struct conv_param* param = (struct conv_param*)ir_node->op.param_mem;

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* fc_weight = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);
    struct tensor* fc_bias = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[2]);
    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);

#ifdef HCW_DEBUG_PRINT
    printf("input_tensor->elem_num,output_tensor->elem_num:%d %d\n", input_tensor->elem_num,output_tensor->elem_num);
    printf("input_tensor->elem_num:%d, %d %d %d %d %d\n",input_tensor->elem_num, input_tensor->dims[0],input_tensor->dims[1],input_tensor->dims[2],input_tensor->dims[3],input_tensor->dim_num);
    printf("fc_weight->elem_num:%d, %d %d %d %d %d\n",fc_weight->elem_num, fc_weight->dims[0],fc_weight->dims[1],fc_weight->dims[2],fc_weight->dims[3],fc_weight->dim_num);
    printf("fc_bias->elem_num:%d, %d %d %d %d %d\n",fc_bias->elem_num, fc_bias->dims[0],fc_bias->dims[1],fc_bias->dims[2],fc_bias->dims[3],fc_bias->dim_num);
    printf("output_tensor->elem_num:%d, %d %d %d %d %d\n",output_tensor->elem_num, output_tensor->dims[0],output_tensor->dims[1],output_tensor->dims[2],output_tensor->dims[3],output_tensor->dim_num);
#endif
    //	int8_t* output_int8 = (int8_t*)malloc(output_tensor->elem_num*2);
    int8_t output_int8[1024];
    printf("output_int8: 0x%x\n", output_int8);

    s16* input_data_s16 = (s16 *)malloc(input_tensor->elem_num*2);
    printf("input_data_s16: 0x%x\n", input_data_s16);

    s16* weight_data_s16 = (s16*)malloc(fc_weight->elem_num*2);
    //    s16 weight_data_s16[1024*16];
    printf("weight_data_s16: 0x%x\n", weight_data_s16);

    s16* bias_data_s16 = (s16*)malloc(fc_bias->elem_num*2);
    //    s16 bias_data_s16[1024*2];
    printf("bias_data_s16: 0x%x\n", bias_data_s16);

    s16* output_data_s16 = (s16*)malloc(output_tensor->elem_num*2);
    //    s16 output_data_s16[1024*2];
    printf("output_data_s16: 0x%x\n", output_data_s16);

    //int8 to int16
    printf("fc input:\n");
    printf("data_type elem_size:%d %d\n",input_tensor->data_type, input_tensor->elem_size);
    int8_t* input_tensor_int8 = (int8_t*)input_tensor->data;
    for(int i=0;i<input_tensor->elem_num;i++){
        printf("%d ", *(input_tensor_int8+i));
        //    	input_data_s16[i] =(s16) input_tensor_int8[i];
    }
    printf("\n");
    //int8 to int16
    int8_t* weight_data_int8 = (int8_t*)fc_weight->data;
    for(int i=0;i<fc_weight->elem_num;i++){
        //    	printf("%d ",weight_data_int8[i]);
        weight_data_s16[i] = (s16)weight_data_int8[i];
    }
    printf("\n");

    //int32 to int16
    printf("fc bias:\n");
    int32_t* bias_data_int32 = (int32_t*)fc_bias->data;
    for(int i=0;i<fc_bias->elem_num;i++){
        printf("%d ",bias_data_int32[i]);
        int32_t bias_tmp = bias_data_int32[i];
        if (bias_tmp > 32767)
            bias_tmp = 32767;
        else if (bias_tmp < -32767)
            bias_tmp = -32767;
        bias_data_s16[i] = (s16)bias_tmp;
    }
    printf("\n");

    u64 input_data_phy = hrKmToPhys(input_data_s16);
    printf("input_data_phy: 0x%x\n", input_data_phy);

    u64 fc_weight_phy = hrKmToPhys(weight_data_s16);
    printf("fc_weight_phy: 0x%x\n", fc_weight_phy);

    u64 fc_bias_phy = hrKmToPhys(bias_data_s16);
    printf("fc_bias_phy: 0x%x\n", fc_bias_phy);

    u64 output_data_phy = hrKmToPhys(output_data_s16);
    printf("output_data_phy: 0x%x\n", output_data_phy);

    if (RegEnable())
    {
        setDeviceParam(0,0,0,0,0,1,0,0,0,1,0,0);
        setSlaveMode();
        setFC(input_tensor->elem_num,output_tensor->elem_num,BATCH,0,
              TRUNC_ADD,TRUNC_MAC,0,0,0,
              TRUNC_BIAS,0,
              input_data_phy,fc_weight_phy,0,fc_bias_phy,
              output_data_phy, RESP_TYPE,0,0
              );

    }

    printf("FC config done!\n");
    cal_resp_proc(RESP_TYPE);
    printf("FC done \n");


    // int16 to int8
    printf("fc output: \n");
    //	int8_t* output_tensor_int8 = (int8_t*)output_tensor->data;
    for(int i=0;i<output_tensor->elem_num;i++){
        printf("%d ", output_data_s16[i]);
        int16_t tmp = output_data_s16[i];
        if (tmp > 127)
            tmp = 127;
        else if (tmp < -127)
            tmp = -127;
        output_int8[i] = (int8_t)tmp;
        //		output_tensor_int8[i] =  (int8_t)tmp;
    }
    output_tensor->data = output_int8;
    printf("FC Over!\n");

    //	  exit(-1);

    //    free(input_data_s16);
    //    free(weight_data_s16);
    //    free(bias_data_s16);
    //    free(output_data_s16);

    }

    //int setFC(  u32 fc_L, u32 fc_Nu, u32 fc_batch, u32 fc_softmax,
    //		u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 activ_bit1, u32 activ_res_bit1,
    //		 u32 trunc_bias, u32 trunc_sum_out_par,
    //		 u64 inputAddr1, u64 inputAddr2, u64 inputAddr3,u64 inputAddr4,
    //		 u64 outputAddr, u32 RespType, u32 BatchMark, u32 LastConfig)
