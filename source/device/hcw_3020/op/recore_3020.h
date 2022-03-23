//*********************************************
//**********************************************
//
//
//

#ifndef __RECORE3020_H__
#define __RECORE3020_H__

//#define API_PARAM_TEST

#ifndef __cplusplus
//#define     BOOL    int
//#define     TRUE    1
//#define     FALSE   0
#endif

#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include "mydef.h"
typedef boolean BOOL;
//typedef     unsigned short          uint16;
//typedef     unsigned char           uint8;
//typedef     int                     int32;
//typedef     unsigned int            u32;
//typedef     unsigned long long int  u64;
//#define     int32       int
//#define     u32      unsigned int
//#define     u64      unsigned long int

#define     BANK_SIZE			    0x00004000 //wqh 0812

#define	    ADDR_LOW                        0x0
#define     ADDR_HIGH                       0xffffffffff

#define     RASP_BASE_ADDR1                 0x1f070000
#define     RASP_BASE_ADDR2                 0x1f070000
#define     RASP_BASE_ADDR3                 0x1f070000
#define     RASP_BASE_ADDR4                 0x1f070000


unsigned int RASP_BASE_ADDR = RASP_BASE_ADDR1;

#define     DEVICE_CON                      RASP_BASE_ADDR + 0x00000000
//#define     BASE_ADDRH         			    RASP_BASE_ADDR + 0x00000004
//#define     BASE_ADDRL         			    RASP_BASE_ADDR + 0x00000008

#define     OP1_INPUT_ADDR3H                RASP_BASE_ADDR + 0x0000000c
#define     OP1_INPUT_ADDR3L                RASP_BASE_ADDR + 0x00000010
#define     OP1_INPUT_LEN3                  RASP_BASE_ADDR + 0x00000014
#define     OP1_INPUT_ADDR4H   	            RASP_BASE_ADDR + 0x00000018
#define     OP1_INPUT_ADDR4L   	            RASP_BASE_ADDR + 0x0000001c
#define     OP1_INPUT_LEN4                  RASP_BASE_ADDR + 0x00000020
#define     OP1_INPUT_ADDR5H   	            RASP_BASE_ADDR + 0x00000024
#define     OP1_INPUT_ADDR5L   	            RASP_BASE_ADDR + 0x00000028
#define     OP1_INPUT_LEN5     	            RASP_BASE_ADDR + 0x0000002c
#define     OP1_HUGE_DATA_DDR_TIMES2        RASP_BASE_ADDR + 0x00000030
#define     OP1_OTHER_PARAH2                RASP_BASE_ADDR + 0x00000034
#define     OP1_OTHER_PARAL2                RASP_BASE_ADDR + 0x00000038
#define     OP1_INPUT_ADDR1H                RASP_BASE_ADDR + 0x0000003c
#define     OP1_INPUT_ADDR1L                RASP_BASE_ADDR + 0x00000040
#define     OP1_INPUT_LEN1                  RASP_BASE_ADDR + 0x00000044
#define     OP1_INPUT_ADDR2H   	            RASP_BASE_ADDR + 0x00000048
#define     OP1_INPUT_ADDR2L   	            RASP_BASE_ADDR + 0x0000004c
#define     OP1_INPUT_LEN2                  RASP_BASE_ADDR + 0x00000050
#define     OP1_OUTPUT_ADDRH   	            RASP_BASE_ADDR + 0x00000054
#define     OP1_OUTPUT_ADDRL   	            RASP_BASE_ADDR + 0x00000058
#define     OP1_OUTPUT_LEN     	            RASP_BASE_ADDR + 0x0000005c
#define     OP1_HUGE_DATA_DDR_TIMES         RASP_BASE_ADDR + 0x00000060
#define     OP1_MATRIX_CONFIG               RASP_BASE_ADDR + 0x00000064
#define     OP1_OTHER_PARAH                 RASP_BASE_ADDR + 0x00000068
#define     OP1_OTHER_PARAL                 RASP_BASE_ADDR + 0x0000006c
#define     OP1_PARA_CONFIG                 RASP_BASE_ADDR + 0x00000070

#define     OP2_INPUT_ADDR3H                RASP_BASE_ADDR + 0x00000074 
#define     OP2_INPUT_ADDR3L                RASP_BASE_ADDR + 0x00000078
#define     OP2_INPUT_LEN3                  RASP_BASE_ADDR + 0x0000007c
#define     OP2_INPUT_ADDR4H   	            RASP_BASE_ADDR + 0x00000080
#define     OP2_INPUT_ADDR4L   	            RASP_BASE_ADDR + 0x00000084
#define     OP2_INPUT_LEN4                  RASP_BASE_ADDR + 0x00000088
#define     OP2_INPUT_ADDR5H   	            RASP_BASE_ADDR + 0x0000008c
#define     OP2_INPUT_ADDR5L   	            RASP_BASE_ADDR + 0x00000090
#define     OP2_INPUT_LEN5     	            RASP_BASE_ADDR + 0x00000094
#define     OP2_HUGE_DATA_DDR_TIMES2        RASP_BASE_ADDR + 0x00000098
#define     OP2_OTHER_PARAH2                RASP_BASE_ADDR + 0x0000009c
#define     OP2_OTHER_PARAL2                RASP_BASE_ADDR + 0x000000a0
#define     OP2_INPUT_ADDR1H                RASP_BASE_ADDR + 0x000000a4
#define     OP2_INPUT_ADDR1L                RASP_BASE_ADDR + 0x000000a8
#define     OP2_INPUT_LEN1                  RASP_BASE_ADDR + 0x000000ac
#define     OP2_INPUT_ADDR2H   	            RASP_BASE_ADDR + 0x000000b0
#define     OP2_INPUT_ADDR2L   	            RASP_BASE_ADDR + 0x000000b4
#define     OP2_INPUT_LEN2                  RASP_BASE_ADDR + 0x000000b8
#define     OP2_OUTPUT_ADDRH   	            RASP_BASE_ADDR + 0x000000bc
#define     OP2_OUTPUT_ADDRL   	            RASP_BASE_ADDR + 0x000000c0
#define     OP2_OUTPUT_LEN     	            RASP_BASE_ADDR + 0x000000c4
#define     OP2_HUGE_DATA_DDR_TIMES         RASP_BASE_ADDR + 0x000000c8
#define     OP2_MATRIX_CONFIG               RASP_BASE_ADDR + 0x000000cc
#define     OP2_OTHER_PARAH                 RASP_BASE_ADDR + 0x000000d0
#define     OP2_OTHER_PARAL                 RASP_BASE_ADDR + 0x000000d4
#define     OP2_PARA_CONFIG                 RASP_BASE_ADDR + 0x000000d8

#define     OP3_INPUT_ADDR3H                RASP_BASE_ADDR + 0x000000dc 
#define     OP3_INPUT_ADDR3L                RASP_BASE_ADDR + 0x000000e0
#define     OP3_INPUT_LEN3                  RASP_BASE_ADDR + 0x000000e4
#define     OP3_INPUT_ADDR4H   	            RASP_BASE_ADDR + 0x000000e8
#define     OP3_INPUT_ADDR4L   	            RASP_BASE_ADDR + 0x000000ec
#define     OP3_INPUT_LEN4                  RASP_BASE_ADDR + 0x000000f0
#define     OP3_INPUT_ADDR5H   	            RASP_BASE_ADDR + 0x000000f4
#define     OP3_INPUT_ADDR5L   	            RASP_BASE_ADDR + 0x000000f8
#define     OP3_INPUT_LEN5     	            RASP_BASE_ADDR + 0x000000fc
#define     OP3_HUGE_DATA_DDR_TIMES2        RASP_BASE_ADDR + 0x00000100
#define     OP3_OTHER_PARAH2                RASP_BASE_ADDR + 0x00000104
#define     OP3_OTHER_PARAL2                RASP_BASE_ADDR + 0x00000108
#define     OP3_INPUT_ADDR1H                RASP_BASE_ADDR + 0x0000010C
#define     OP3_INPUT_ADDR1L                RASP_BASE_ADDR + 0x00000110
#define     OP3_INPUT_LEN1                  RASP_BASE_ADDR + 0x00000114
#define     OP3_INPUT_ADDR2H                RASP_BASE_ADDR + 0x00000118
#define     OP3_INPUT_ADDR2L                RASP_BASE_ADDR + 0x0000011C
#define     OP3_INPUT_LEN2                  RASP_BASE_ADDR + 0x00000120
#define     OP3_OUTPUT_ADDRH                RASP_BASE_ADDR + 0x00000124
#define     OP3_OUTPUT_ADDRL                RASP_BASE_ADDR + 0x00000128
#define     OP3_OUTPUT_LEN                  RASP_BASE_ADDR + 0x0000012c
#define     OP3_HUGE_DATA_DDR_TIMES         RASP_BASE_ADDR + 0x00000130
#define     OP3_MATRIX_CONFIG               RASP_BASE_ADDR + 0x00000134
#define     OP3_OTHER_PARAH                 RASP_BASE_ADDR + 0x00000138
#define     OP3_OTHER_PARAL                 RASP_BASE_ADDR + 0x0000013c
#define     OP3_PARA_CONFIG                 RASP_BASE_ADDR + 0x00000140

#define     OP4_INPUT_ADDR3H                RASP_BASE_ADDR + 0x00000144 
#define     OP4_INPUT_ADDR3L                RASP_BASE_ADDR + 0x00000148
#define     OP4_INPUT_LEN3                  RASP_BASE_ADDR + 0x0000014c
#define     OP4_INPUT_ADDR4H   	            RASP_BASE_ADDR + 0x00000150
#define     OP4_INPUT_ADDR4L   	            RASP_BASE_ADDR + 0x00000154
#define     OP4_INPUT_LEN4                  RASP_BASE_ADDR + 0x00000158
#define     OP4_INPUT_ADDR5H   	            RASP_BASE_ADDR + 0x0000015c
#define     OP4_INPUT_ADDR5L   	            RASP_BASE_ADDR + 0x00000160
#define     OP4_INPUT_LEN5     	            RASP_BASE_ADDR + 0x00000164
#define     OP4_HUGE_DATA_DDR_TIMES2        RASP_BASE_ADDR + 0x00000168
#define     OP4_OTHER_PARAH2                RASP_BASE_ADDR + 0x0000016c
#define     OP4_OTHER_PARAL2                RASP_BASE_ADDR + 0x00000170
#define     OP4_INPUT_ADDR1H                RASP_BASE_ADDR + 0x00000174
#define     OP4_INPUT_ADDR1L                RASP_BASE_ADDR + 0x00000178
#define     OP4_INPUT_LEN1                  RASP_BASE_ADDR + 0x0000017C
#define     OP4_INPUT_ADDR2H                RASP_BASE_ADDR + 0x00000180
#define     OP4_INPUT_ADDR2L                RASP_BASE_ADDR + 0x00000184
#define     OP4_INPUT_LEN2                  RASP_BASE_ADDR + 0x00000188
#define     OP4_OUTPUT_ADDRH                RASP_BASE_ADDR + 0x0000018C
#define     OP4_OUTPUT_ADDRL                RASP_BASE_ADDR + 0x00000170
#define     OP4_OUTPUT_LEN                  RASP_BASE_ADDR + 0x00000174
#define     OP4_HUGE_DATA_DDR_TIMES         RASP_BASE_ADDR + 0x00000178
#define     OP4_MATRIX_CONFIG               RASP_BASE_ADDR + 0x0000017c
#define     OP4_OTHER_PARAH                 RASP_BASE_ADDR + 0x000001a0
#define     OP4_OTHER_PARAL                 RASP_BASE_ADDR + 0x000001a4
#define     OP4_PARA_CONFIG                 RASP_BASE_ADDR + 0x000001a8
                                                                      
#define     STATUS_CON                      RASP_BASE_ADDR + 0x000001ac

#define     INTR_STATE                      RASP_BASE_ADDR + 0x000001b0
#define     INTR_PMUL1                      RASP_BASE_ADDR + 0x000001b4
#define     INTR_PMUL2                      RASP_BASE_ADDR + 0x000001b8
#define     INTR_RMUL1                      RASP_BASE_ADDR + 0x000001bc
#define     INTR_RMUL2                      RASP_BASE_ADDR + 0x000001c0
#define     INTR_PADD1                      RASP_BASE_ADDR + 0x000001c4
#define     INTR_PADD2                      RASP_BASE_ADDR + 0x000001c8
#define     INTR_PADD3                      RASP_BASE_ADDR + 0x000001cc
#define     INTR_PADD4                      RASP_BASE_ADDR + 0x000001d0
#define     INTR_PADD5                      RASP_BASE_ADDR + 0x000001d4
#define     INTR_RADD1                      RASP_BASE_ADDR + 0x000001d8
#define     INTR_RADD2                      RASP_BASE_ADDR + 0x000001dc
#define     INTR_EXP1                       RASP_BASE_ADDR + 0x000001e0
#define     INTR_EXP2                       RASP_BASE_ADDR + 0x000001e4
#define     INTR_FIXM                       RASP_BASE_ADDR + 0x000001e8
#define     INTR_DIV                        RASP_BASE_ADDR + 0x000001ec
#define     INTR_TRANS                      RASP_BASE_ADDR + 0x000001f0
#define     INTR_COMP1                      RASP_BASE_ADDR + 0x000001f4
#define     INTR_COMP2                      RASP_BASE_ADDR + 0x000001f8
#define     INTR_COMP3                      RASP_BASE_ADDR + 0x000001fc
#define     INTR_COMP4                      RASP_BASE_ADDR + 0x00000200

#define     CALCULATE_T1                    RASP_BASE_ADDR + 0x00000260
#define     CALCULATE_T2                    RASP_BASE_ADDR + 0x00000264
#define     CALCULATE_T3                    RASP_BASE_ADDR + 0x00000268
#define     CALCULATE_T4                    RASP_BASE_ADDR + 0x0000026c
#define     CALCULATE_T5                    RASP_BASE_ADDR + 0x00000270
#define     CALCULATE_T6                    RASP_BASE_ADDR + 0x00000274
#define     CALCULATE_T7                    RASP_BASE_ADDR + 0x00000278
#define     CALCULATE_T8                    RASP_BASE_ADDR + 0x0000027c

#define     MASTER_ADDRH                    RASP_BASE_ADDR + 0x00000280
#define     MASTER_ADDRL                    RASP_BASE_ADDR + 0x00000284

//#define     END_REG                         RASP_BASE_ADDR + 0x00000200

//#define     FFT_ID          0x01
//#define     MAT_MUL_ID      0x02
//#define     MAT_COV_ID      0x03
//#define     PLU_FIR_ID      0x04
//#define     PLU_DOP_ID      0x05
//#define     REAL_DOP_ID     0x06
//#define     SELF_CORR_ID    0x07
//#define     CROSS_CORR_ID   0x08
//#define     REAL_FIR_ID     0x09
//#define     MAT_ADD_ID      0x0a
//#define     MAT_DOT_ID      0x0b
//#define     MAT_CONJ_ID     0x0c
//#define     MAT_INV_ID      0x0d
//#define     DIV_ID          0x12
//#define     MOD_ID          0x13
//#define     FIX_ID          0x14
//#define     MAT_TRANS_ID    0x15
//#define     SYMM_FIR_ID     0x16
//#define     INNER_PROD_ID   0x18
//#define     SORT_ID         0x19
//#define     SINC_ID         0x1a
//#define     CEXP_ID         0x1b
//#define     SINCOS_ID       0x1c
//#define     CREC_ID         0x1d
//#define     SQRT_ID         0x1e
//#define     SQRTREC_ID      0x1f

#define     COMP(x, low, high)        ((x) >= (low) && (x) <= (high))
////////////////////////////////////////////////
#ifdef API_PARAM_TEST
#include <stdio.h>
#define VNAME(name) (#name)
#define     SetReg(_x, _y)      do{ \
printf("%20s : 0x%08x\n",VNAME(_x), (_y));   \
}while(0)

#define     ReadReg(_x, _y)     NULL

#else
/*
#define     SetReg(_x,_y)       (*(volatile u32*)(_x)) = ((_y) << 24)|(((_y) << 8) & 0xff0000)|(((_y) >> 8) & 0xff00)|(((_y) >> 24) & 0xff)
#define     ReadReg(_x,_y)    do{   \
    (_y) = *(volatile u32*)(_x); \
    (_y) = ((_y) << 24)|(((_y) << 8) & 0xff0000)|(((_y) >> 8) & 0xff00)|(((_y) >> 24) & 0xff);\
}while(0)
*/
//#define     SetReg(_x,_y)       do{ \
//    (*(volatile u32*)(_x)) = (_y);\
//}while(0)
//
//#define     ReadReg(_x,_y)       do{ \
//    (_y) = *(volatile u32*)(_x); \
//}while(0)
	
#define _P2V(addr)	(0x9000000000000000 | ((u64)(addr)))	/* physical address to virtual address */

#define     SetReg(_x,_y)       do{ \
(*(volatile u32*)(_P2V(_x))) = (_y);\
}while(0)

#define     ReadReg(_x,_y)       do{ \
(_y) = *(volatile u32*)(_P2V(_x)); \
}while(0)

#define     GetDdrVal(_x,_y)       do{ \
(_y) = *(volatile u32*)(_x); \
}while(0)


#endif


typedef struct CalParam{
    u32  cal_type;
    u64  input_addr1;
    u64  input_addr2;
    u64  input_addr3;
    u64  input_addr4;
    u64  output_addr;
	
    u64  input_addr5;
    u32  input_len5;
    u32  param[4];
    u32  param2[4];
    u32  resp_type;
    u32  batch_mark;
    u32  last_config;
    u32  test_break;
}CalParam;


/*
struct ConfigReg{
    u32 INPUT_ADDR1H    		     ;
    u32 INPUT_ADDR1L    		     ;
    u32 INPUT_LEN1      		     ;
    u32 INPUT_ADDR2H   			 ;
    u32 INPUT_ADDR2L   			 ;
    u32 INPUT_LEN2			     ;
    u32 OUTPUT_ADDRH   			 ;
    u32 OUTPUT_ADDRL   	         ;
    u32 OUTPUT_LEN     			 ;
    u32 HUGE_DATA_DDR_TIMES       ;
    u32 MATRIX_CONFIG    		 ;
    u32 OTHER_PARAH               ;
    u32 OTHER_PARAL               ;
    u32 PARA_CONFIG               ;


};
*/
u32 INPUT_ADDR3H              ;
u32 INPUT_ADDR3L              ;
u32 INPUT_LEN3                ;
u32 INPUT_ADDR4H   	         ;
u32 INPUT_ADDR4L   	         ;
u32 INPUT_LEN4                ;
u32 INPUT_ADDR5H   	         ;
u32 INPUT_ADDR5L   	         ;
u32 INPUT_LEN5     	         ;
u32 HUGE_DATA_DDR_TIMES2      ;
u32 OTHER_PARAH2              ;
u32 OTHER_PARAL2              ;
u32 INPUT_ADDR1H    	         ;
u32 INPUT_ADDR1L    	         ;
u32 INPUT_LEN1      		     ;
u32 INPUT_ADDR2H   			 ;
u32 INPUT_ADDR2L   			 ;
u32 INPUT_LEN2			     ;
u32 OUTPUT_ADDRH   			 ;
u32 OUTPUT_ADDRL   	         ;
u32 OUTPUT_LEN     			 ;
u32 HUGE_DATA_DDR_TIMES       ;
u32 MATRIX_CONFIG    		 ;
u32 OTHER_PARAH               ;
u32 OTHER_PARAL               ;
u32 PARA_CONFIG               ;

int Intr_rasp;
//typedef struct ConfigReg *ConfigPtr;

//enum BOOL{FALSE, TRUE};


BOOL RegEnable(void);
int setDeviceParam(u32 Ip_sheru, u32 Dsp_tch_finish, u32 Dsp_treq, u32 Abnorm_zero, u32 Mode, u32 Slave_start, u32 Master_Start, u32 Test, u32 Int_Zero, u32 Dev_Avail, u32 Mask,/* u32 Mode_alg, */u32 Master_p_len);
void setMasterMode(void);
void setSlaveMode(void);
int setIpSheru(u32 Ip_sheru);
int setDspTchFinish(u32 Dsp_tch_finish);
int setDspTreq(u32 Dsp_treq);
int setAbnormZero(u32 Abnorm_zero);
int setTest(u32 Test);
int setIntZero(u32 Int_Zero);
int setMask(u32 Mask);

//int setMatrixAddSub( u32 batch_en, u32 conju_mode_en, u32 single_point_n, u32 matrix_num, u32 add_flag, u32 batch_num, u64 inputAddr1, u64 inputAddr2, u64 inputAddr3,u64 inputAddr4,u64 inputAddr5, u64 outputAddr, u32 RespType, u32 BatchMark, u32 Batchfinish);//@xj 20210130
//int setMatrixDotMul(u32 batch_en, u32 conju_mode_en, u32 single_point_n, u32 matrix_num, u32 add_flag, u32 batch_num, u64 inputAddr1, u64 inputAddr2, u64 inputAddr3,u64 inputAddr4,u64 inputAddr5, u64 outputAddr, u32 RespType, u32 BatchMark, u32 Batchfinish);//@xj 20210130

//int setFC(  u32 fc_L, u32 fc_Nu, u32 fc_batch, u32 fc_softmax, u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 activ_bit1, u32 activ_res_bit1,u32 trunc_bias,u32 trunc_sum_out_par,u64 inputAddr1, u64 inputAddr2, u64 inputAddr3,u64 outputAddr, u32 RespType, u32 BatchMark, u32 LastConfig);
/*******************************************************************************************************************************/
BOOL SramAvail(void);
u32 InqStatus(void);
BOOL InqRTestfinish(void);
BOOL InqRResponse(void);
BOOL InqRDone(void);
BOOL InqRInte(void);
u32 InqRCalcType(void);
BOOL InqRInteErr(void);
BOOL InqRLastResp(void);
u32 InqInt(void);
u32 InqIntECC(void);
u32 InqIntIpnum(void);
u32 InqIntIptype(void);
u32 InqIntErrtype(void);
u32 InqIntDiv(void);
u32 InqIntRMul1(void);
u32 InqIntRMul2(void);
u32 InqIntPMul1(void);
u32 InqIntPMul2(void);
u32 InqIntPAdd1(void);
u32 InqIntPAdd2(void);
u32 InqIntPAdd3(void);
u32 InqIntPAdd4(void);
u32 InqIntPAdd5(void);
u32 InqIntRAdd1(void);
u32 InqIntRAdd2(void);
u32 InqIntExp1(void);
u32 InqIntExp2(void);
u32 InqIntTrans(void);
u32 InqIntComp1(void);
u32 InqIntComp2(void);
u32 InqIntComp3(void);
u32 InqIntComp4(void);
u32 InqIntFixRMul(void);
int getCalculationParam(CalParam* cal_param);
void choose_no(u32 num);

#endif

