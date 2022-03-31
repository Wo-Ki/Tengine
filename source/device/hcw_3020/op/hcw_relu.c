#include "operator/op.h"
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

#define _P2V(addr)	(0x9000000000000000 | ((u64)(addr)))	/* physical address to virtual address */

#define     SetReg(_x,_y)       do{ \
(*( u32*)(_P2V(_x))) = (_y);\
}while(0)

#define     ReadReg(_x,_y)       do{ \
(_y) = *( u32*)(_P2V(_x)); \
}while(0)

extern void extract_feature_from_tensor_hcw(const char* comment, const char* layer_name, const struct tensor* tensor);
extern int setActivation(u32 huge_data_times_3, u32 activation_input_last, u32 activation_input, u32 activation_output_last,
                         u32 activation_output, u32 activation_model, u32 activation_bit, u32 activation_res_int,
                         u32 inputAddr1_H, u32 inputAddr1_L, u32 outputAddr_H, u32 outputAddr_L,
                         u32 Resp_Type, u32 Batch_mark, u32 Batch_finish);



int HCWReluRun(struct node* ir_node)
    {
    printf("HCWReluRun\n");

    struct graph* ir_graph = ir_node->graph;

    struct tensor* input_tensor = get_ir_graph_tensor(ir_graph, ir_node->input_tensors[0]);
    struct tensor* output_tensor = get_ir_graph_tensor(ir_graph, ir_node->output_tensors[0]);

    #ifdef HCW_DEBUG_PRINT
    printf("input_tensor->elem_num:%d, %d %d %d %d %d\n",input_tensor->elem_num, input_tensor->dims[0],input_tensor->dims[1],input_tensor->dims[2],input_tensor->dims[3],input_tensor->dim_num);
    printf("output_tensor->elem_num:%d, %d %d %d %d %d\n",output_tensor->elem_num, output_tensor->dims[0],output_tensor->dims[1],output_tensor->dims[2],output_tensor->dims[3],output_tensor->dim_num);
#endif
    s16* input_data_s16 = (s16*)malloc(sizeof(s16)*input_tensor->elem_num);
    s16* output_data_s16 = (s16*)malloc(sizeof(s16)*output_tensor->elem_num);
    int8_t* output_int8 = (int8_t*)malloc(sizeof(int8_t)*output_tensor->elem_num);

    //int8 to int16
    int8_t* input_tensor_int8 = (int8_t*)input_tensor->data;
    printf("relu input:");
    for(int i=0;i<(input_tensor->elem_num);i++){
        //    	printf("%d ",input_tensor_int8[i]);
        input_data_s16[i] = (s16)input_tensor_int8[i];
    }

    u64 input_tensor_phy = hrKmToPhys(input_data_s16);
    u64 output_data_phy = hrKmToPhys(output_data_s16);

    if (RegEnable())
    {
        setDeviceParam(0,0,0,0,0,1,0,0,0,1,0,0);
        setSlaveMode();
        //    		extract_feature_from_tensor_hcw(input_tensor->name, "test", input_tensor);
        u32 input_tensor_phy_hi = input_tensor_phy>>32;
        u32 input_tensor_phy_lo = input_tensor_phy;
        u32 output_data_phy_hi = output_data_phy>>32;
        u32 output_data_phy_lo =output_data_phy;

        setActivation(0, input_tensor->elem_num, input_tensor->elem_num, output_tensor->elem_num, output_tensor->elem_num,
                      1, 0,0,
                      input_tensor_phy_hi,input_tensor_phy_lo,output_data_phy_hi,output_data_phy_lo,
                      RESP_TYPE, 0, 0);

    }
    printf("Relu config done!\n");
    cal_resp_proc(RESP_TYPE);
    printf("Relu done \n");
#ifdef HCW_DEBUG_PRINT
    printf("output_tensor->elem_num:%d\n", output_tensor->elem_num);
#endif
    printf("output data:\n");
    for(int i=0;i<output_tensor->elem_num;i++){
        output_int8[i] = (int8_t)output_data_s16[i];
        printf("%d/%d ", output_data_s16[i],output_int8[i]);
    }
    printf("\n");
    output_tensor->data = output_int8;


    //    free(input_data_s16);
    }
