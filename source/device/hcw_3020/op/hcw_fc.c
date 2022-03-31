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

int HCWFcPreRun(struct node* ir_node)
    {
    struct graph* ir_graph = ir_node->graph;
    struct tensor* fc_weight = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);
    struct tensor* fc_bias = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[2]);
    s16* weight_data_s16 = (s16*)malloc(sizeof(s16)*fc_weight->elem_num*2);
    s16* bias_data_s16 = (s16*)malloc(sizeof(s16)*fc_bias->elem_num*2);
    //int8 to int16
    int8_t* weight_data_int8 = (int8_t*)fc_weight->data;
    for(int i=0;i<fc_weight->elem_num;i++){
        weight_data_s16[i] = (s16)weight_data_int8[i];
    }

    //int32 to int16
    int32_t* bias_data_int32 = (int32_t*)fc_bias->data;
    for(int i=0;i<fc_bias->elem_num;i++){
        int32_t bias_tmp = bias_data_int32[i];
        if (bias_tmp > 32767)
            bias_tmp = 32767;
        else if (bias_tmp < -32767)
            bias_tmp = -32767;
        bias_data_s16[i] = (s16)bias_tmp;
    }
    fc_weight->data = weight_data_s16;
    fc_bias->data = bias_data_s16;
    }
    int HCWFcRun(struct node* ir_node)
        {
    struct graph* ir_graph = ir_node->graph;

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* fc_weight = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[1]);
    struct tensor* fc_bias = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[2]);
    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);

#ifdef HCW_DEBUG_PRINT
    printf("input_tensor->elem_num,output_tensor->elem_num:%d %d\n", input_tensor->elem_num,output_tensor->elem_num);
    printf("input_tensor->elem_num:%d, %d %d %d %d %d\n",input_tensor->elem_num, input_tensor->dims[0],input_tensor->dims[1],input_tensor->dims[2],input_tensor->dims[3],input_tensor->dim_num);
    printf("fc_weight->elem_num:%d, %d %d %d %d %d\n",fc_weight->elem_num, fc_weight->dims[0],fc_weight->dims[1],fc_weight->dims[2],fc_weight->dims[3],fc_weight->dim_num);
    printf("fc_bias->elem_num:%d, %d %d %d %d %d\n",fc_bias->elem_num, fc_bias->dims[0],fc_bias->dims[1],fc_bias->dims[2],fc_bias->dims[3],fc_bias->dim_num);
    printf("fc output_tensor->elem_num:%d, %d %d %d %d %d\n",output_tensor->elem_num, output_tensor->dims[0],output_tensor->dims[1],output_tensor->dims[2],output_tensor->dims[3],output_tensor->dim_num);
#endif
    s16* input_data_s16 = (s16 *)malloc(sizeof(s16)*input_tensor->elem_num);
    s16* output_data_s16 = (s16*)malloc(sizeof(s16)*output_tensor->elem_num);
    int8_t* output_int8 = (int8_t*)malloc(sizeof(int8_t)*output_tensor->elem_num);

    float input_scale = input_tensor->scale;
    float output_scale = output_tensor->scale;
    float* weight_scales = fc_weight->scale_list;
    float* requant_scales = (float*)malloc(output_tensor->elem_num * sizeof(float));

    //int8 to int16
#ifdef HCW_DEBUG_PRINT
printf("fc input:\n");
printf("data_type "
       "elem_size:%d %d\n",input_tensor->data_type, input_tensor->elem_size);
#endif
int8_t* input_tensor_int8 = (int8_t*)input_tensor->data;
for(int i=0;i<input_tensor->elem_num;i++){
    input_data_s16[i] =(s16)input_tensor_int8[i];
    //        printf("%d ",input_data_s16[i]);
}
u64 input_data_phy = hrKmToPhys(input_data_s16);
u64 fc_weight_phy = hrKmToPhys(fc_weight->data);
u64 fc_bias_phy = hrKmToPhys(fc_bias->data);
u64 output_data_phy = hrKmToPhys(output_data_s16);

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
#ifdef HCW_DEBUG_PRINT
printf("FC config done!\n");
#endif
cal_resp_proc(RESP_TYPE);
#ifdef HCW_DEBUG_PRINT
printf("FC done \n");
printf("fc input_scale, input_scale:%f %f\n",input_scale,output_scale );
printf("fc output: \n");
#endif

for(int i=0;i<output_tensor->elem_num;i++){
    float requant_scale =(input_scale * weight_scales[i]) / output_scale;
    int16_t tmp = (int16_t)(output_data_s16[i]*requant_scale);
    //		printf("%d/%f/%d ", output_data_s16[i],weight_scales[i],requant_scale,tmp);
    if (tmp > 127)
        tmp = 127;
    else if (tmp < -127)
        tmp = -127;
    output_int8[i] = (int8_t)tmp;
}
output_tensor->data = output_int8;

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
