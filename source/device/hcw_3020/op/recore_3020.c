//#include "mydef.h"
//#include "debug.h"
//#include "my_types.h"
//#include "sys.h"
//#include "common.h"
//#include "pic.h"
//#include "io.h"
//#include "hw_addr.h"
//#include "debug.h"

#include "recore_3020.h"

#define RASP_INTE (0x0000000000000001ull << 41)

void choose_no(u32 num)
{
    switch (num)
    {
    case 0: RASP_BASE_ADDR = RASP_BASE_ADDR1; break;
    case 1: RASP_BASE_ADDR = RASP_BASE_ADDR2; break;
    case 2: RASP_BASE_ADDR = RASP_BASE_ADDR3; break;
    case 3: RASP_BASE_ADDR = RASP_BASE_ADDR4; break;
    default:
        break;
    }
}
BOOL RegEnable(void)
{
    //	printk("regenable  input !!! \r\n");
    u32 config;

    ReadReg(OP1_PARA_CONFIG, config);
    printk("op1 config = 0x%x !!! \r\n", config);
    //    DBPRINT("OP1_PARA_CONFIG = 0x%x,PARA_CONFIG = 0x%x\r\n",OP1_PARA_CONFIG,PARA_CONFIG);
    if ((config & 0x00000004) == 0x0)
    {
        //        DBPRINT("op1 op1 op1 op1 op1 op1 !!! \r\n");
        INPUT_ADDR3H = OP1_INPUT_ADDR3H;                 //DBPRINT("1 \r\n");
        INPUT_ADDR3L = OP1_INPUT_ADDR3L;                 //DBPRINT("2 \r\n");
        INPUT_LEN3 = OP1_INPUT_LEN3;                     //DBPRINT("3 \r\n");
        INPUT_ADDR4H = OP1_INPUT_ADDR4H;                 //DBPRINT("4 \r\n");
        INPUT_ADDR4L = OP1_INPUT_ADDR4L;                 //DBPRINT("5 \r\n");
        INPUT_LEN4 = OP1_INPUT_LEN4;                     //DBPRINT("6 \r\n");
        INPUT_ADDR5H = OP1_INPUT_ADDR5H;                 //DBPRINT("7 \r\n");
        INPUT_ADDR5L = OP1_INPUT_ADDR5L;                 //DBPRINT("8 \r\n");
        INPUT_LEN5 = OP1_INPUT_LEN5;                     //DBPRINT("9 \r\n");
        HUGE_DATA_DDR_TIMES2 = OP1_HUGE_DATA_DDR_TIMES2; //DBPRINT("10 \r\n");
        OTHER_PARAH2 = OP1_OTHER_PARAH2;                 //DBPRINT("11 \r\n");
        OTHER_PARAL2 = OP1_OTHER_PARAL2;                 //DBPRINT("12 \r\n");
        INPUT_ADDR1H = OP1_INPUT_ADDR1H;                 //DBPRINT("13 \r\n");
        INPUT_ADDR1L = OP1_INPUT_ADDR1L;                 //DBPRINT("14 \r\n");
        INPUT_LEN1 = OP1_INPUT_LEN1;                     //DBPRINT("15 \r\n");
        INPUT_ADDR2H = OP1_INPUT_ADDR2H;                 //DBPRINT("16 \r\n");
        INPUT_ADDR2L = OP1_INPUT_ADDR2L;                 //DBPRINT("17 \r\n");
        INPUT_LEN2 = OP1_INPUT_LEN2;                     //DBPRINT("18 \r\n");
        OUTPUT_ADDRH = OP1_OUTPUT_ADDRH;                 //DBPRINT("19 \r\n");
        OUTPUT_ADDRL = OP1_OUTPUT_ADDRL;                 //DBPRINT("20 \r\n");
        OUTPUT_LEN = OP1_OUTPUT_LEN;                     //DBPRINT("21 \r\n");
        HUGE_DATA_DDR_TIMES = OP1_HUGE_DATA_DDR_TIMES;   //DBPRINT("22 \r\n");
        MATRIX_CONFIG = OP1_MATRIX_CONFIG;               //DBPRINT("23 \r\n");
        OTHER_PARAH = OP1_OTHER_PARAH;                   //DBPRINT("24 \r\n");
        OTHER_PARAL = OP1_OTHER_PARAL;                   //DBPRINT("25 \r\n");
        PARA_CONFIG = OP1_PARA_CONFIG;                   //DBPRINT("26 \r\n");

        printf("config register 1!!! \r\n");
        return TRUE;
    }

    ReadReg(OP2_PARA_CONFIG, config);
    printf("op2 config = 0x%x !!! \r\n", config);
    //    DBPRINT("OP2_PARA_CONFIG = 0x%x,PARA_CONFIG = 0x%x\r\n",OP2_PARA_CONFIG,PARA_CONFIG);
    if ((config & 0x00000004) == 0x0)
    {
        INPUT_ADDR3H = OP2_INPUT_ADDR3H;                 //DBPRINT("1 \r\n");
        INPUT_ADDR3L = OP2_INPUT_ADDR3L;                 //DBPRINT("2 \r\n");
        INPUT_LEN3 = OP2_INPUT_LEN3;                     //DBPRINT("3 \r\n");
        INPUT_ADDR4H = OP2_INPUT_ADDR4H;                 //DBPRINT("4 \r\n");
        INPUT_ADDR4L = OP2_INPUT_ADDR4L;                 //DBPRINT("5 \r\n");
        INPUT_LEN4 = OP2_INPUT_LEN4;                     //DBPRINT("6 \r\n");
        INPUT_ADDR5H = OP2_INPUT_ADDR5H;                 //DBPRINT("7 \r\n");
        INPUT_ADDR5L = OP2_INPUT_ADDR5L;                 //DBPRINT("8 \r\n");
        INPUT_LEN5 = OP2_INPUT_LEN5;                     //DBPRINT("9 \r\n");
        HUGE_DATA_DDR_TIMES2 = OP2_HUGE_DATA_DDR_TIMES2; //DBPRINT("10 \r\n");
        OTHER_PARAH2 = OP2_OTHER_PARAH2;                 //DBPRINT("11 \r\n");
        OTHER_PARAL2 = OP2_OTHER_PARAL2;                 //DBPRINT("12 \r\n");
        INPUT_ADDR1H = OP2_INPUT_ADDR1H;                 //DBPRINT("13 \r\n");
        INPUT_ADDR1L = OP2_INPUT_ADDR1L;                 //DBPRINT("14 \r\n");
        INPUT_LEN1 = OP2_INPUT_LEN1;                     //DBPRINT("15 \r\n");
        INPUT_ADDR2H = OP2_INPUT_ADDR2H;                 //DBPRINT("16 \r\n");
        INPUT_ADDR2L = OP2_INPUT_ADDR2L;                 //DBPRINT("17 \r\n");
        INPUT_LEN2 = OP2_INPUT_LEN2;                     //DBPRINT("18 \r\n");
        OUTPUT_ADDRH = OP2_OUTPUT_ADDRH;                 //DBPRINT("19 \r\n");
        OUTPUT_ADDRL = OP2_OUTPUT_ADDRL;                 //DBPRINT("20 \r\n");
        OUTPUT_LEN = OP2_OUTPUT_LEN;                     //DBPRINT("21 \r\n");
        HUGE_DATA_DDR_TIMES = OP2_HUGE_DATA_DDR_TIMES;   //DBPRINT("22 \r\n");
        MATRIX_CONFIG = OP2_MATRIX_CONFIG;               //DBPRINT("23 \r\n");
        OTHER_PARAH = OP2_OTHER_PARAH;                   //DBPRINT("24 \r\n");
        OTHER_PARAL = OP2_OTHER_PARAL;                   //DBPRINT("25 \r\n");
        PARA_CONFIG = OP2_PARA_CONFIG;                   //DBPRINT("26 \r\n");

        printf("config register 2!!! \r\n");
        return TRUE;
    }
    ReadReg(OP3_PARA_CONFIG, config);
    printf("op3 config = 0x%x !!! \r\n", config);
    printf("OP3_PARA_CONFIG = 0x%x,PARA_CONFIG = 0x%x\r\n", OP3_PARA_CONFIG, PARA_CONFIG);
    if ((config & 0x00000004) == 0x0)
    {
        INPUT_ADDR3H = OP3_INPUT_ADDR3H;                 //DBPRINT("1 \r\n");
        INPUT_ADDR3L = OP3_INPUT_ADDR3L;                 //DBPRINT("2 \r\n");
        INPUT_LEN3 = OP3_INPUT_LEN3;                     //DBPRINT("3 \r\n");
        INPUT_ADDR4H = OP3_INPUT_ADDR4H;                 //DBPRINT("4 \r\n");
        INPUT_ADDR4L = OP3_INPUT_ADDR4L;                 //DBPRINT("5 \r\n");
        INPUT_LEN4 = OP3_INPUT_LEN4;                     //DBPRINT("6 \r\n");
        INPUT_ADDR5H = OP3_INPUT_ADDR5H;                 //DBPRINT("7 \r\n");
        INPUT_ADDR5L = OP3_INPUT_ADDR5L;                 //DBPRINT("8 \r\n");
        INPUT_LEN5 = OP3_INPUT_LEN5;                     //DBPRINT("9 \r\n");
        HUGE_DATA_DDR_TIMES2 = OP3_HUGE_DATA_DDR_TIMES2; //DBPRINT("10 \r\n");
        OTHER_PARAH2 = OP3_OTHER_PARAH2;                 //DBPRINT("11 \r\n");
        OTHER_PARAL2 = OP3_OTHER_PARAL2;                 //DBPRINT("12 \r\n");
        INPUT_ADDR1H = OP3_INPUT_ADDR1H;                 //DBPRINT("13 \r\n");
        INPUT_ADDR1L = OP3_INPUT_ADDR1L;                 //DBPRINT("14 \r\n");
        INPUT_LEN1 = OP3_INPUT_LEN1;                     //DBPRINT("15 \r\n");
        INPUT_ADDR2H = OP3_INPUT_ADDR2H;                 //DBPRINT("16 \r\n");
        INPUT_ADDR2L = OP3_INPUT_ADDR2L;                 //DBPRINT("17 \r\n");
        INPUT_LEN2 = OP3_INPUT_LEN2;                     //DBPRINT("18 \r\n");
        OUTPUT_ADDRH = OP3_OUTPUT_ADDRH;                 //DBPRINT("19 \r\n");
        OUTPUT_ADDRL = OP3_OUTPUT_ADDRL;                 //DBPRINT("20 \r\n");
        OUTPUT_LEN = OP3_OUTPUT_LEN;                     //DBPRINT("21 \r\n");
        HUGE_DATA_DDR_TIMES = OP3_HUGE_DATA_DDR_TIMES;   //DBPRINT("22 \r\n");
        MATRIX_CONFIG = OP3_MATRIX_CONFIG;               //DBPRINT("23 \r\n");
        OTHER_PARAH = OP3_OTHER_PARAH;                   //DBPRINT("24 \r\n");
        OTHER_PARAL = OP3_OTHER_PARAL;                   //DBPRINT("25 \r\n");
        PARA_CONFIG = OP3_PARA_CONFIG;                   //DBPRINT("26 \r\n");

        printf("config register 3!!! \r\n");
        return TRUE;
    }
    ReadReg(OP4_PARA_CONFIG, config);
    if ((config & 0x00000004) == 0x0)
    {
        INPUT_ADDR3H = OP4_INPUT_ADDR3H;                 //DBPRINT("1 \r\n");
        INPUT_ADDR3L = OP4_INPUT_ADDR3L;                 //DBPRINT("2 \r\n");
        INPUT_LEN3 = OP4_INPUT_LEN3;                     //DBPRINT("3 \r\n");
        INPUT_ADDR4H = OP4_INPUT_ADDR4H;                 //DBPRINT("4 \r\n");
        INPUT_ADDR4L = OP4_INPUT_ADDR4L;                 //DBPRINT("5 \r\n");
        INPUT_LEN4 = OP4_INPUT_LEN4;                     //DBPRINT("6 \r\n");
        INPUT_ADDR5H = OP4_INPUT_ADDR5H;                 //DBPRINT("7 \r\n");
        INPUT_ADDR5L = OP4_INPUT_ADDR5L;                 //DBPRINT("8 \r\n");
        INPUT_LEN5 = OP4_INPUT_LEN5;                     //DBPRINT("9 \r\n");
        HUGE_DATA_DDR_TIMES2 = OP4_HUGE_DATA_DDR_TIMES2; //DBPRINT("10 \r\n");
        OTHER_PARAH2 = OP4_OTHER_PARAH2;                 //DBPRINT("11 \r\n");
        OTHER_PARAL2 = OP4_OTHER_PARAL2;                 //DBPRINT("12 \r\n");
        INPUT_ADDR1H = OP4_INPUT_ADDR1H;                 //DBPRINT("13 \r\n");
        INPUT_ADDR1L = OP4_INPUT_ADDR1L;                 //DBPRINT("14 \r\n");
        INPUT_LEN1 = OP4_INPUT_LEN1;                     //DBPRINT("15 \r\n");
        INPUT_ADDR2H = OP4_INPUT_ADDR2H;                 //DBPRINT("16 \r\n");
        INPUT_ADDR2L = OP4_INPUT_ADDR2L;                 //DBPRINT("17 \r\n");
        INPUT_LEN2 = OP4_INPUT_LEN2;                     //DBPRINT("18 \r\n");
        OUTPUT_ADDRH = OP4_OUTPUT_ADDRH;                 //DBPRINT("19 \r\n");
        OUTPUT_ADDRL = OP4_OUTPUT_ADDRL;                 //DBPRINT("20 \r\n");
        OUTPUT_LEN = OP4_OUTPUT_LEN;                     //DBPRINT("21 \r\n");
        HUGE_DATA_DDR_TIMES = OP4_HUGE_DATA_DDR_TIMES;   //DBPRINT("22 \r\n");
        MATRIX_CONFIG = OP4_MATRIX_CONFIG;               //DBPRINT("23 \r\n");
        OTHER_PARAH = OP4_OTHER_PARAH;                   //DBPRINT("24 \r\n");
        OTHER_PARAL = OP4_OTHER_PARAL;                   //DBPRINT("25 \r\n");
        PARA_CONFIG = OP4_PARA_CONFIG;                   //DBPRINT("26 \r\n");

        printf("config register 4!!! \r\n");
        return TRUE;
    }
    return FALSE;
}

//
int setDeviceParam(u32 Ip_sheru, u32 Dsp_tch_finish, u32 Dsp_treq, u32 Abnorm_zero, u32 Mode, u32 Slave_start, u32 Master_Start, u32 Test, u32 Int_Zero, u32 Dev_Avail, u32 Mask, /* u32 Mode_alg, */ u32 Master_p_len)
{
    u32 deviceparam;
    if (!COMP(Ip_sheru, 0, 3))
    {
        return -1;
    }
    if (!COMP(Dsp_tch_finish, 0, 1))
    {
        return -1;
    }
    if (!COMP(Dsp_treq, 0, 1))
    {
        return -1;
    }
    if (!COMP(Abnorm_zero, 0, 1))
    {
        return -1;
    }
    if (!COMP(Mode, 0, 1))
    {
        return -1;
    }
    if (!COMP(Slave_start, 0, 1))
    {
        return -1;
    }
    if (!COMP(Master_Start, 0, 1))
    {
        return -1;
    }
    if (!COMP(Test, 0, 1))
    {
        return -1;
    }
    if (!COMP(Int_Zero, 0, 1))
    {
        return -1;
    }
    if (!COMP(Dev_Avail, 0, 1))
    {
        return -1;
    }
    if (!COMP(Mask, 0, 0x7F))
    {
        return -1;
    }
    //if(!COMP(Mode_alg,0,1)){
    //    return -1;
    //}
    if (!COMP(Master_p_len, 0, 0xF))
    {
        return -1;
    }
    deviceparam = (Mask << 17) | (Ip_sheru << 15) | (Dsp_tch_finish << 14) | (Dsp_treq << 13) | (Abnorm_zero << 12) | (Mode << 11) | (Slave_start << 10) | (Master_Start << 9) | (Test << 8) | (Int_Zero << 7) | (Master_p_len << 3) | (Dev_Avail << 2) /* | (Mode_alg << 1)*/;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

void setMasterMode(void)
{
    u32 deviceparam;
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFF1FB;
    deviceparam |= 0xA04;
    SetReg(DEVICE_CON, deviceparam);
}

void setSlaveMode(void)
{
    u32 deviceparam;
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFF1FB;
    deviceparam |= 0x404;
    SetReg(DEVICE_CON, deviceparam);
}

int setIpSheru(u32 Ip_sheru)
{
    u32 deviceparam;
    if (!COMP(Ip_sheru, 0, 3))
    {
        return -1;
    }
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFE7FFF;
    deviceparam |= (Ip_sheru << 15) & 0x18000;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

int setDspTreq(u32 Dsp_treq)
{
    u32 deviceparam;
    if (!COMP(Dsp_treq, 0, 1))
    {
        return -1;
    }
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFDFFF;
    deviceparam |= ((Dsp_treq << 13) & 0x2000) | 0x4;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

int setAbnormZero(u32 Abnorm_zero)
{
    u32 deviceparam;
    if (!COMP(Abnorm_zero, 0, 1))
    {
        return -1;
    }
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFEFFF;
    deviceparam |= (Abnorm_zero << 12) & 0x1000;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

int setTest(u32 Test)
{
    u32 deviceparam;
    if (!COMP(Test, 0, 1))
    {
        return -1;
    }
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFFEFF;
    deviceparam |= (Test << 8) & 0x100;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

int setIntZero(u32 Int_Zero)
{
    u32 deviceparam;
    if (!COMP(Int_Zero, 0, 1))
    {
        return -1;
    }
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFFF7F;
    deviceparam |= (Int_Zero << 7) & 0x80;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

int setMask(u32 Mask)
{
    if (!COMP(Mask, 0, 0x7F))
    {
        return -1;
    }
    u32 deviceparam;
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0x1FFFF;
    deviceparam |= (Mask << 17) | 0x4;
    SetReg(DEVICE_CON, deviceparam);
    return 0;
}

int setModeAlg(u32 Mode_alg)
{
    if (!COMP(Mode_alg, 0, 1))
    {
        return -1;
    }
    u32 deviceparam;
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFFFFD;
    deviceparam |= (Mode_alg << 1);
    SetReg(DEVICE_CON, deviceparam);
}

int setMasterPLen(u32 Master_p_len)
{
    if (!COMP(Master_p_len, 0, 0xF))
    {
        return -1;
    }
    u32 deviceparam;
    ReadReg(DEVICE_CON, deviceparam);
    deviceparam &= 0xFFFFFF87;
    deviceparam |= (Master_p_len << 3);
    SetReg(DEVICE_CON, deviceparam);
}

//@xj 20210130
int setMatrixAddSub(u32 batch_en, u32 conju_mode_en, u32 single_point_n, u32 matrix_num, u32 add_flag, u32 batch_num, u64 inputAddr1, u64 inputAddr2, u64 inputAddr3, u64 inputAddr4, u64 inputAddr5, u64 outputAddr, u32 RespType, u32 BatchMark, u32 Batchfinish)
{
    int i;

    u32 inputAddr1_H;
    u32 inputAddr1_L;
    u32 inputAddr2_H;
    u32 inputAddr2_L;
    u32 inputAddr3_H;
    u32 inputAddr3_L;
    u32 inputAddr4_H;
    u32 inputAddr4_L;
    u32 inputAddr5_H;
    u32 inputAddr5_L;
    u32 outputAddr_H;
    u32 outputAddr_L;

    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 config;

    u32 matrix_num_small;
    u32 input_len1;
    u32 input_len2;
    u32 output_len;
    u32 huge_ddr_times;
    u32 other_paramh;
    u32 other_paraml;
    ///////////////////////////////

    inputAddr1_H = (u32)(inputAddr1 >> 32);
    inputAddr1_L = (u32)inputAddr1;
    inputAddr2_H = (u32)(inputAddr2 >> 32);
    inputAddr2_L = (u32)inputAddr2;
    inputAddr3_H = (u32)(inputAddr3 >> 32);
    inputAddr3_L = (u32)inputAddr3;
    inputAddr4_H = (u32)(inputAddr4 >> 32);
    inputAddr4_L = (u32)inputAddr4;
    inputAddr5_H = (u32)(inputAddr5 >> 32);
    inputAddr5_L = (u32)inputAddr5;
    outputAddr_H = (u32)(outputAddr >> 32);
    outputAddr_L = (u32)outputAddr;

    if ((!COMP(inputAddr1, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr2, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr3, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr4, ADDR_LOW, ADDR_HIGH)) || (!COMP(outputAddr, ADDR_LOW, ADDR_HIGH)))
    {
        printf("ERROR -1\n");
        return -1;
    }
    if (!COMP(matrix_num, 1, 1024 * 1024))
    {
        printf("ERROR -2: only support matrix num between 1~1M\n");
        return -2;
    }
    if (!COMP(add_flag, 0, 1))
    {
        printf("ERROR -3: add_flag should be 0 or 1\n");
        return -3;
    }
    if (!COMP(batch_en, 0, 1))
    {
        printf("ERROR -4: batch_en should be 0 or 1\n");
        return -4;
    }
    if (!COMP(single_point_n, 0, 1))
    {
        printf("ERROR -5: single_point_n should be 0 or 1\n");
        return -5;
    }
    if (!COMP(batch_num, 0, 64 * 1024))
    {
        printf("ERROR -6: only support batch num between 1~64K\n");
        return -6;
    }
    if (!COMP(RespType, 0, 1))
    {
        printf("ERROR -7\n");
        return -7;
    }
    if (!COMP(BatchMark, 0, 1))
    {
        printf("ERROR -8\n");
        return -8;
    }
    if (!COMP(Batchfinish, 0, 1))
    {
        printf("ERROR -9\n");
        return -9;
    }

    Call_Type = 10; //01010
    Config_avail = 1;
    Mode_alg = 0;
    config = (Call_Type << 8) | ((RespType & 0x1) << 7) | (BatchMark << 6) | (Batchfinish << 5) | (Config_avail << 2) | (Mode_alg << 1);

    if (matrix_num % 0x10000 == 0)
    { //64k
        matrix_num_small = 0x10000;
    }
    else
    {
        matrix_num_small = matrix_num % 0x10000;
    }

    input_len1 = matrix_num_small * 8;

    if ((single_point_n == 0) && (batch_en == 0))
    {
        input_len2 = 8;
    }
    else if ((single_point_n == 0) && (batch_en == 1))
    {
        input_len2 = (matrix_num_small / batch_num) * 8;
    }
    else
    {
        input_len2 = matrix_num_small * 8;
    }

    output_len = input_len1;

    if (matrix_num <= 0x10000)
    { //64k
        huge_ddr_times = 0;
    }
    else
    {
        huge_ddr_times = (matrix_num - 1) / 0x10000 + 1;
    }

    other_paramh = (batch_en << 20) | (conju_mode_en << 19) | (single_point_n << 18) | (matrix_num_small << 1) | add_flag;
    other_paraml = batch_num;

    SetReg(INPUT_ADDR3H, inputAddr3_H);
    SetReg(INPUT_ADDR3L, inputAddr3_L);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, 0);
    SetReg(INPUT_ADDR5H, inputAddr5_H);
    SetReg(INPUT_ADDR5L, inputAddr5_L);
    SetReg(INPUT_LEN5, 0);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, 0);
    SetReg(OTHER_PARAL2, 0);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, input_len1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, input_len2);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, output_len);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, 0);
    SetReg(OTHER_PARAH, other_paramh);
    SetReg(OTHER_PARAL, other_paraml);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif

    return 0;
}

//@xj 20210130
int setMatrixDotMul(u32 batch_en, u32 conju_mode_en, u32 single_point_n, u32 matrix_num, u32 add_flag, u32 batch_num, u64 inputAddr1, u64 inputAddr2, u64 inputAddr3, u64 inputAddr4, u64 inputAddr5, u64 outputAddr, u32 RespType, u32 BatchMark, u32 Batchfinish)
{
    int i;

    u32 inputAddr1_H;
    u32 inputAddr1_L;
    u32 inputAddr2_H;
    u32 inputAddr2_L;
    u32 inputAddr3_H;
    u32 inputAddr3_L;
    u32 inputAddr4_H;
    u32 inputAddr4_L;
    u32 inputAddr5_H;
    u32 inputAddr5_L;
    u32 outputAddr_H;
    u32 outputAddr_L;

    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 config;

    u32 matrix_num_small;
    u32 input_len1;
    u32 input_len2;
    u32 output_len;
    u32 huge_ddr_times;
    u32 other_paramh;
    u32 other_paraml;
    ///////////////////////////////

    inputAddr1_H = (u32)(inputAddr1 >> 32);
    inputAddr1_L = (u32)inputAddr1;
    inputAddr2_H = (u32)(inputAddr2 >> 32);
    inputAddr2_L = (u32)inputAddr2;
    inputAddr3_H = (u32)(inputAddr3 >> 32);
    inputAddr3_L = (u32)inputAddr3;
    inputAddr4_H = (u32)(inputAddr4 >> 32);
    inputAddr4_L = (u32)inputAddr4;
    inputAddr5_H = (u32)(inputAddr5 >> 32);
    inputAddr5_L = (u32)inputAddr5;
    outputAddr_H = (u32)(outputAddr >> 32);
    outputAddr_L = (u32)outputAddr;

    if ((!COMP(inputAddr1, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr2, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr3, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr4, ADDR_LOW, ADDR_HIGH)) || (!COMP(outputAddr, ADDR_LOW, ADDR_HIGH)))
    {
        printf("ERROR -1\n");
        return -1;
    }
    if (!COMP(matrix_num, 1, 1024 * 1024))
    {
        printf("ERROR -2: only support matrix num between 1~1M\n");
        return -2;
    }
    if (!COMP(conju_mode_en, 0, 1))
    {
        printf("ERROR -3: conju_mode_en should be 0 or 1\n");
        return -3;
    }
    if (!COMP(batch_en, 0, 1))
    {
        printf("ERROR -4: batch_en should be 0 or 1\n");
        return -4;
    }
    if (!COMP(single_point_n, 0, 1))
    {
        printf("ERROR -5: single_point_n should be 0 or 1\n");
        return -5;
    }
    if (!COMP(batch_num, 0, 64 * 1024))
    {
        printf("ERROR -6: only support batch num between 1~64K\n");
        return -6;
    }
    if (!COMP(RespType, 0, 1))
    {
        printf("ERROR -7\n");
        return -7;
    }
    if (!COMP(BatchMark, 0, 1))
    {
        printf("ERROR -8\n");
        return -8;
    }
    if (!COMP(Batchfinish, 0, 1))
    {
        printf("ERROR -9\n");
        return -9;
    }

    Call_Type = 11; //01011
    Config_avail = 1;
    Mode_alg = 0;
    config = (Call_Type << 8) | ((RespType & 0x1) << 7) | (BatchMark << 6) | (Batchfinish << 5) | (Config_avail << 2) | (Mode_alg << 1);

    if (matrix_num % 0x10000 == 0)
    { //64k
        matrix_num_small = 0x10000;
    }
    else
    {
        matrix_num_small = matrix_num % 0x10000;
    }

    input_len1 = matrix_num_small * 8;

    if ((single_point_n == 0) && (batch_en == 0))
    {
        input_len2 = 8;
    }
    else if ((single_point_n == 0) && (batch_en == 1))
    {
        input_len2 = (matrix_num_small / batch_num) * 8;
    }
    else
    {
        input_len2 = matrix_num_small * 8;
    }

    output_len = input_len1;

    if (matrix_num <= 0x10000)
    { //64k
        huge_ddr_times = 0;
    }
    else
    {
        huge_ddr_times = (matrix_num - 1) / 0x10000 + 1;
    }

    other_paramh = (batch_en << 20) | (conju_mode_en << 19) | (single_point_n << 18) | (matrix_num_small << 1) | add_flag;
    other_paraml = batch_num;

    SetReg(INPUT_ADDR3H, inputAddr3_H);
    SetReg(INPUT_ADDR3L, inputAddr3_L);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, 0);
    SetReg(INPUT_ADDR5H, inputAddr5_H);
    SetReg(INPUT_ADDR5L, inputAddr5_L);
    SetReg(INPUT_LEN5, 0);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, 0);
    SetReg(OTHER_PARAL2, 0);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, input_len1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, input_len2);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, output_len);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, 0);
    SetReg(OTHER_PARAH, other_paramh);
    SetReg(OTHER_PARAL, other_paraml);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif

    return 0;
}

int setPluralFIR(u32 firnum, u32 stepnum,
                 u64 inputAddr1, u64 inputAddr2, u64 inputAddr3, u64 inputAddr4, u64 outputAddr,
                 u32 RespType, u32 BatchMark, u32 LastConfig)
{
    int i;
    u32 inputAddr1_H;
    u32 inputAddr1_L;
    u32 inputAddr2_H;
    u32 inputAddr2_L;
    u32 inputAddr3_H;
    u32 inputAddr3_L;
    u32 inputAddr4_H;
    u32 inputAddr4_L;
    u32 outputAddr_H;
    u32 outputAddr_L;
    u32 other_para_H;
    u32 other_para_L;

    u32 input_len1;
    u32 input_len2;
    u32 output_len;
    u32 huge_ddr_times;

    u32 config;

    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;

    if ((!COMP(inputAddr1, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr2, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr3, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr4, ADDR_LOW, ADDR_HIGH)) || (!COMP(outputAddr, ADDR_LOW, ADDR_HIGH)))
    {
        return -1;
    }
    if (!COMP(firnum, 8, 8 * 1024))
    {
        printf("ERROR! plural fir only supports num 8 to 8k!\n");
        return -2;
    }
    if (!COMP(stepnum, 8, 128))
    {
        printf("ERROR! plural fir only supports step 8 to 128!\n");
        return -3;
    }
    if (!COMP(RespType, 0, 1))
    {
        return -7;
    }
    if (!COMP(BatchMark, 0, 1))
    {
        return -8;
    }
    if (!COMP(LastConfig, 0, 1))
    {
        return -9;
    }

    inputAddr1_H = (u32)(inputAddr1 >> 32);
    inputAddr1_L = (u32)inputAddr1;

    inputAddr2_H = (u32)(inputAddr2 >> 32);
    inputAddr2_L = (u32)inputAddr2;

    inputAddr3_H = (u32)(inputAddr3 >> 32);
    inputAddr3_L = (u32)inputAddr3;

    inputAddr4_H = (u32)(inputAddr4 >> 32);
    inputAddr4_L = (u32)inputAddr4;

    outputAddr_H = (u32)(outputAddr >> 32);
    outputAddr_L = (u32)outputAddr;

    //huge_ddr_times = (firnum-1)/(32*1024);
    huge_ddr_times = 0;

    if (huge_ddr_times == 0)
    {
        input_len1 = firnum * 8;
        input_len2 = stepnum * 8;
        output_len = (firnum + stepnum - 1) * 8;
    }
    else if (huge_ddr_times != 0)
    {
        input_len1 = (firnum - 32 * 1024 * huge_ddr_times + stepnum - 1) * 8;
        input_len2 = (stepnum * 8);
        output_len = ((firnum + stepnum - 1) - 32 * 1024 * huge_ddr_times) * 8;
        huge_ddr_times = huge_ddr_times + 1;
    }

    Call_Type = 4; //00100
    Config_avail = 1;
    Mode_alg = 0;
    config = (Call_Type << 8) | ((RespType & 0x1) << 7) | (BatchMark << 6) | (LastConfig << 5) | (Config_avail << 2) | (Mode_alg << 1);

    other_para_H = (firnum << 8) | stepnum;
    other_para_L = 0;

    SetReg(INPUT_ADDR3H, inputAddr3_H);
    SetReg(INPUT_ADDR3L, inputAddr3_L);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, 0);
    SetReg(INPUT_ADDR5H, 0);
    SetReg(INPUT_ADDR5L, 0);
    SetReg(INPUT_LEN5, 0);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, 0);
    SetReg(OTHER_PARAL2, 0);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, input_len1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, input_len2);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, output_len);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, 0);
    SetReg(OTHER_PARAH, other_para_H);
    SetReg(OTHER_PARAL, other_para_L);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

int setFC(u32 fc_L, u32 fc_Nu, u32 fc_batch, u32 fc_softmax,
          u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 activ_bit1, u32 activ_res_bit1,
          u32 trunc_bias, u32 trunc_sum_out_par,
          u64 inputAddr1, u64 inputAddr2, u64 inputAddr3, u64 inputAddr4,
          u64 outputAddr, u32 RespType, u32 BatchMark, u32 LastConfig)
{
    int i;
    u32 input_addr1h;
    u32 input_addr1l;
    u32 input_len1;
    u32 input_addr2h;
    u32 input_addr2l;
    u32 input_len2;
    u32 input_addr3h;
    u32 input_addr3l;

    u32 input_addr4h; //ck 220111 add
    u32 input_addr4l; //ck 220111 add

    u32 input_len3;
    u32 output_addrh;
    u32 output_addrl;
    u32 output_len;
    u32 hugeData;
    u32 other_paramh;
    u32 other_paraml;
    u32 other_paramll;
    u32 other_paramhh;
    u32 matrix_config;
    u32 config;
    u32 fc_num_in_last;
    u32 fc_num_out_last;
    u32 fc_num_in_last_H;
    u32 fc_num_in_last_L;

    u64 other_para1;
    u64 other_para2;

    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;

    if ((!COMP(inputAddr1, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr2, ADDR_LOW, ADDR_HIGH)) || (!COMP(inputAddr4, ADDR_LOW, ADDR_HIGH)) || (!COMP(outputAddr, ADDR_LOW, ADDR_HIGH)))
    {
        return -1;
    }

    if (!COMP(RespType, 0, 1))
    {
        return -7;
    }
    if (!COMP(BatchMark, 0, 1))
    {
        return -8;
    }
    if (!COMP(LastConfig, 0, 1))
    {
        return -9;
    }
    fc_num_in_last = fc_L;
    fc_num_out_last = fc_Nu;

    input_addr1h = (u32)(inputAddr1 >> 32);
    input_addr1l = (u32)inputAddr1;
    input_len1 = (((fc_L - 1) / 16) + 1) * 16 * fc_batch * 2;

    input_addr2h = (u32)(inputAddr2 >> 32);
    input_addr2l = (u32)inputAddr2;
    input_len2 = (((fc_L - 1) / 16) + 1) * 16 * fc_Nu * 2;

    input_addr4h = (u32)(inputAddr4 >> 32);
    input_addr4l = (u32)inputAddr4;
    input_len3 = (((fc_Nu - 1) / 16) + 1) * 16 * 2;

    output_addrh = (u32)(outputAddr >> 32);
    output_addrl = (u32)outputAddr;
    output_len = (((fc_Nu - 1) / 16) + 1) * 16 * fc_batch * 2;

    fc_num_in_last_H = (u32)(fc_num_in_last >> 9);
    fc_num_in_last_L = fc_num_in_last % 512;

    //other_para1 = fc_L | (fc_Nu << 16) | (fc_batch << 32) | (fc_softmax << 38) | (fc_num_in_last_L << 55);
    //other_para2 = fc_num_in_last_H | (fc_num_out_last<< 17) | (trunc_add << 33) | (trunc_mac << 38) | (activ_mode1 << 43) | (activ_bit1 << 46) | (activ_res_bit1 << 50);
    hugeData = 0;

    other_paramh = fc_batch | (fc_softmax << (38 - 32)) | (fc_num_in_last_L << (55 - 32));
    other_paraml = fc_L | (fc_Nu << 16);
    other_paramll = fc_num_in_last_H | (fc_num_out_last << 17);
    other_paramhh = (trunc_add << (33 - 32)) | (trunc_mac << (38 - 32)) | (activ_mode1 << (43 - 32)) | (activ_bit1 << (46 - 32)) | (activ_res_bit1 << (50 - 32));
    matrix_config = trunc_sum_out_par | (trunc_bias << 5);

    Call_Type = 33; //10001
    Config_avail = 1;
    Mode_alg = 1;
    config = (Call_Type << 8) | ((RespType & 0x1) << 7) | (BatchMark << 6) | (LastConfig << 5) | (Config_avail << 2) | (Mode_alg << 1);

    SetReg(INPUT_ADDR3H, 0);
    SetReg(INPUT_ADDR3L, 0);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, input_addr4h);
    SetReg(INPUT_ADDR4L, input_addr4l);
    SetReg(INPUT_LEN4, input_len3);
    SetReg(INPUT_ADDR5H, 0);
    SetReg(INPUT_ADDR5L, 0);
    SetReg(INPUT_LEN5, 0);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, other_paramhh);
    SetReg(OTHER_PARAL2, other_paramll);
    SetReg(INPUT_ADDR1H, input_addr1h);
    SetReg(INPUT_ADDR1L, input_addr1l);
    SetReg(INPUT_LEN1, input_len1);
    SetReg(INPUT_ADDR2H, input_addr2h);
    SetReg(INPUT_ADDR2L, input_addr2l);
    SetReg(INPUT_LEN2, input_len2);
    SetReg(OUTPUT_ADDRH, output_addrh);
    SetReg(OUTPUT_ADDRL, output_addrl);
    SetReg(OUTPUT_LEN, output_len);
    SetReg(HUGE_DATA_DDR_TIMES, hugeData);
    SetReg(MATRIX_CONFIG, matrix_config); //@swq 210615
    SetReg(OTHER_PARAH, other_paramh);
    SetReg(OTHER_PARAL, other_paraml);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

int setActivation(u32 huge_data_times_3, u32 activation_input_last, u32 activation_input, u32 activation_output_last,
                  u32 activation_output, u32 activation_model, u32 activation_bit, u32 activation_res_int,
                  u32 inputAddr1_H, u32 inputAddr1_L, u32 outputAddr_H, u32 outputAddr_L,
                  u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
{
    int i;
    u32 input_len1;
    u32 output_len;
    u32 other_paramh;
    u32 other_paraml;
    u32 other_paramll;
    u32 other_paramhh;
    u32 config;

    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 hugeData;

    input_len1 = (activation_input * huge_data_times_3 + activation_input_last) * 2;
    output_len = (activation_input * huge_data_times_3 + activation_input_last) * 2;
    hugeData = huge_data_times_3;

    other_paramhh = 0;                                                                                                              //wrq 210618
    other_paraml = activation_input_last | (activation_input << 20);                                                                //wrq 210618
    other_paramh = (activation_output << 28) | (activation_input >> 12) | (activation_output_last << 8);                            //wrq 210618
    other_paramll = (u32)(activation_output >> 4) | (activation_model << 16) | (activation_bit << 19) | (activation_res_int << 23); //wrq 210618

    Call_Type = 35; //10011
    Config_avail = 1;
    Mode_alg = 1;
    config = (Call_Type << 8) | (Config_avail << 2) | (Mode_alg << 1);

    SetReg(INPUT_ADDR3H, 0);
    SetReg(INPUT_ADDR3L, 0);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, 0);
    SetReg(INPUT_ADDR4L, 0);
    SetReg(INPUT_LEN4, 0);
    SetReg(INPUT_ADDR5H, 0);
    SetReg(INPUT_ADDR5L, 0);
    SetReg(INPUT_LEN5, 0);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, other_paramhh);
    SetReg(OTHER_PARAL2, other_paramll);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, input_len1);
    SetReg(INPUT_ADDR2H, 0);
    SetReg(INPUT_ADDR2L, 0);
    SetReg(INPUT_LEN2, 0);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, output_len);
    SetReg(HUGE_DATA_DDR_TIMES, hugeData);
    SetReg(MATRIX_CONFIG, 0);
    SetReg(OTHER_PARAH, other_paramh);
    SetReg(OTHER_PARAL, other_paraml);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

int setRNN_small(u32 rnn_input, u32 rnn_hidden_total, u32 rnn_hidden_first, u32 rnn_hidden_last,
                 u32 rnn_step_total, u32 rnn_step_first, u32 rnn_step_last, u32 rnn_batch, u32 rnn_cal_len,
                 u32 trunc_add, u32 trunc_mac, u32 activ_mode1, u32 rnn_hidden_step, u32 rnn_input_step,
                 u32 activation_int_bit1, u32 activation_res_int_bit1, u32 trunc_bias,
                 u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L,
                 u32 inputAddr3_H, u32 inputAddr3_L, u32 inputAddr4_H, u32 inputAddr4_L, u32 outputAddr_H,
                 u32 outputAddr_L, u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
{
    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 config;

    u32 other_para_HH;
    u32 other_para_LL;
    u32 other_para_H;
    u32 other_para_L;

    u32 matrix_config;
    u32 input_len5;
    u32 inputLen1;
    u32 inputLen2;
    u32 inputLen4;
    u32 outputLen;
    u32 huge_ddr_times;

    Call_Type = 36; //10100
    Config_avail = 1;
    Mode_alg = 1;
    config = (Call_Type << 8) | (Config_avail << 2) | (Mode_alg << 1);

    other_para_HH = (rnn_cal_len >> 7) | (trunc_add << 16) | (trunc_mac << 21) | (activ_mode1 << 26);
    other_para_LL = (rnn_step_first >> 1) | (rnn_step_last << 9) | (rnn_batch << 19) | ((rnn_cal_len % (1 << 7)) << 25);
    other_para_H = (rnn_hidden_first >> 5) | (rnn_hidden_last << 8) | (rnn_step_total << 21) | ((rnn_step_first % (1 << 1)) << 31);
    other_para_L = rnn_input | (rnn_hidden_total << 14) | ((rnn_hidden_first % (1 << 5)) << 27);

    matrix_config = activation_int_bit1 | (activation_res_int_bit1 << 4) | (trunc_bias << 8);
    input_len5 = rnn_input_step | (rnn_hidden_step << 10);

    inputLen1 = (((rnn_input * rnn_step_total - 1) / 16) + 1) * 16 * rnn_batch * 2;          //è´è´£äººèªè¡è¡¥å
    inputLen2 = (((rnn_input + rnn_hidden_total - 1) / 16) + 1) * 16 * rnn_hidden_total * 2; //è´è´£äººèªè¡è¡¥å
    inputLen4 = ((rnn_hidden_total - 1) / 16 + 1) * 16 * 2;                                  //è´è´£äººèªè¡è¡¥å
    outputLen = (((rnn_hidden_total * rnn_step_total - 1) / 16) + 1) * 16 * rnn_batch * 2;   //è´è´£äººèªè¡è¡¥å
    huge_ddr_times = 0;                                                                      //è´è´£äººèªè¡è¡¥å

    SetReg(INPUT_ADDR3H, inputAddr3_H);
    SetReg(INPUT_ADDR3L, inputAddr3_L);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, inputLen4);
    SetReg(INPUT_ADDR5H, 0);
    SetReg(INPUT_ADDR5L, 0);
    SetReg(INPUT_LEN5, input_len5);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, other_para_HH);
    SetReg(OTHER_PARAL2, other_para_LL);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, inputLen1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, inputLen2);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, outputLen);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, matrix_config);
    SetReg(OTHER_PARAH, other_para_H);
    SetReg(OTHER_PARAL, other_para_L);
    SetReg(PARA_CONFIG, config);
#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

int setConv_small(u32 n_i_r, u32 n_i_c, u32 n_o_r, u32 n_o_c, u32 f_r, u32 f_c, u32 kernel_num, u32 c, u32 s, u32 p_o,
                  u32 batch, u32 zero_flag, u32 flag_out, u32 state, u32 trunc_mac, u32 trunc_sum_out_par,
                  u32 activ_model, u32 activ_bit1, u32 activ_res_bit1,
                  u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr3_H, u32 inputAddr3_L,
                  u32 inputAddr4_H, u32 inputAddr4_L, u32 outputAddr_H, u32 outputAddr_L,
                  u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
{
    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 config;
    u32 conv_state;
    u32 conv_flag_out;
    u32 conv_row;
    u32 conv_row_last;
    u32 conv_kernel_num;
    u32 conv_kernel_num_last;
    u32 conv_kernel_num_last_L;
    u32 conv_kernel_num_last_H;
    u32 conv_feature_in;
    u32 conv_feature_in_last;
    u32 conv_feature_in_last_L;
    u32 conv_feature_in_last_H;
    u32 conv_feature_out;
    u32 conv_feature_out_last;
    u32 conv_feature_out_last_L;
    u32 conv_feature_out_last_H;
    u32 conv_kernel_size;
    u32 conv_feature_dma_first;
    u32 conv_feature_dma_medium;
    u32 conv_feature_dma_last;
    u32 conv_zero_flag;
    u32 conv_f;
    u32 conv_f_r;
    u32 conv_n_in;
    u32 conv_n_out;
    u32 conv_s;
    u32 conv_p_o;
    u32 conv_X;
    u32 conv_c;
    u32 conv_batch;
    u32 input_size;
    u32 kernel_size;
    u32 output_size;
    u32 other_para_HH;
    u32 other_para_LL;
    u32 other_para_H;
    u32 other_para_L;
    u32 matrix_config;
    u32 input_len5;
    u32 input_addr5_H;
    u32 input_addr5_L;
    u32 inputLen1;
    u32 outputLen;
    u32 inputLen2;
    u32 huge_ddr_times;

    conv_state = state;
    conv_flag_out = flag_out;
    conv_row = 0;
    conv_row_last = n_o_r - 1;
    conv_kernel_num = 0;
    conv_kernel_num_last = kernel_num;
    conv_kernel_num_last_L = conv_kernel_num_last % (1 << 1);        //other_param[31]
    conv_kernel_num_last_H = (conv_kernel_num_last >> 1) % (1 << 9); //other_param[40:32]

    conv_feature_in = 0;
    conv_feature_in_last = n_i_c * n_i_r;
    conv_feature_in_last_L = conv_feature_in_last % (1 << 9);        //other_param[63:55]
    conv_feature_in_last_H = (conv_feature_in_last >> 9) % (1 << 5); //other_param[68:64]

    conv_feature_out = 0;
    conv_feature_out_last = n_o_r * n_o_c;
    conv_feature_out_last_L = conv_feature_out_last % (1 << 13);        //other_param[95:83]
    conv_feature_out_last_H = (conv_feature_out_last >> 13) % (1 << 1); //other_param[96]
    printf("conv_feature_out_last %d	\n", conv_feature_out_last);
    printf("conv_feature_out_last %x	\n", conv_feature_out_last);
    printf("conv_feature_out_last_L %d		\n", conv_feature_out_last_L);

    conv_kernel_size = f_c * f_r * c + 1;
    conv_feature_dma_first = (n_o_r + 2 * p_o) * (n_o_c + 2 * p_o) * kernel_num;
    conv_feature_dma_medium = n_i_c * n_i_r * c;
    conv_feature_dma_last = 0;
    conv_zero_flag = zero_flag;
    conv_f = f_c;
    conv_f_r = f_r;
    conv_n_in = n_i_c;
    conv_n_out = n_o_c;
    conv_s = s;
    conv_p_o = p_o;
    conv_X = n_o_r - 1;
    conv_c = c;
    conv_batch = batch;
    input_size = n_i_c * n_i_r * c;
    kernel_size = f_c * f_r * c + 1;
    output_size = (n_o_r + 2 * p_o) * (n_o_c + 2 * p_o) * kernel_num;

    other_para_HH = conv_feature_out_last_H | (conv_kernel_size << (97 - 96)) | (conv_feature_dma_first << (111 - 96)) | (conv_zero_flag << (125 - 96));
    other_para_LL = conv_feature_in_last_H | (conv_feature_out << (69 - 64)) | (conv_feature_out_last_L << (83 - 64));
    other_para_H = conv_kernel_num_last_H | (conv_feature_in << (41 - 32)) | (conv_feature_in_last_L << (55 - 32));
    other_para_L = conv_state | (conv_flag_out << 2) | (conv_row << 3) | (conv_row_last << 12) | (conv_kernel_num << 21) | (conv_kernel_num_last_L << 31);

    matrix_config = (conv_feature_dma_medium << 0) | (conv_feature_dma_last << 14) | (conv_f << 28);
    input_len5 = (conv_n_in << 0) | (conv_n_out << 9) | (conv_s << 18) | (conv_p_o << 21) | (trunc_mac << 24) | (activ_model << 29);
    input_addr5_H = (conv_X << 0) | (conv_c << 9) | (activ_res_bit1 << 19) | (trunc_sum_out_par << 23) | (activ_bit1 << 28);
    input_addr5_L = (conv_f_r << 0) | (conv_batch << 4);

    if (batch == 1)
    {
        inputLen1 = input_size * 2;
        outputLen = output_size * 2;
    }
    else
    {
        inputLen1 = (((input_size - 1) / 16) + 1) * 16 * conv_batch * 2;  //è´è´£äººèªè¡è¡¥å
        outputLen = (((output_size - 1) / 16) + 1) * 16 * conv_batch * 2; //è´è´£äººèªè¡è¡¥å
    }
    if (conv_kernel_num_last == 1)
    {
        inputLen2 = kernel_size * 2;
    }
    else
    {
        inputLen2 = (((kernel_size - 1) / 16) + 1) * 16 * conv_kernel_num_last * 2; //è´è´£äººèªè¡è¡¥å
    }
    huge_ddr_times = 0; //å°ç¹æ°æåµï¼è¯¥å¼æä¸º0

    Call_Type = 34; //100010
    Config_avail = 1;
    Mode_alg = 1;
    config = (Call_Type << 8) | (Resp_Type << 7) | (Config_avail << 2) | (Mode_alg << 1); //ck 220108 add | (Resp_Type << 7)

    SetReg(INPUT_ADDR3H, inputAddr3_H);
    SetReg(INPUT_ADDR3L, inputAddr3_L);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, 0);
    SetReg(INPUT_ADDR5H, input_addr5_H);
    SetReg(INPUT_ADDR5L, input_addr5_L);
    SetReg(INPUT_LEN5, input_len5);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, other_para_HH);
    SetReg(OTHER_PARAL2, other_para_LL);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, inputLen1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, inputLen2);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, outputLen);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, matrix_config);
    SetReg(OTHER_PARAH, other_para_H);
    SetReg(OTHER_PARAL, other_para_L);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

int setPool(u32 max_or_avg, u32 height_flag, u32 mode, u32 F, u32 S, u32 channel, u32 zero, u32 N,
            u32 add_trunc, u32 mul_trunc,
            u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr3_H,
            u32 inputAddr3_L, u32 inputAddr4_H, u32 inputAddr4_L, u32 outputAddr_H, u32 outputAddr_L,
            u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
{
    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 config;
    u32 height;
    u32 L;
    u32 M;
    u32 L_M;
    u32 L_M_padding;
    u32 height_k;
    u32 height_last;
    u32 M_last;
    u32 L_M_last;
    u32 L_M_last_padding;
    u32 other_para_L;
    u32 other_para_H;
    u32 other_para_L2;
    u32 other_para_H2;
    u32 huge_ddr_times;
    u32 maxtrix_addr_acc;
    u32 inputLen5;
    u32 inputAddr5_H;
    u32 inputLen1;
    u32 outputLen;
    u32 param_cfg;
    u32 inputAddr5_L;

    if (mode == 0)
        inputLen1 = (((N * N - 1) / 16) + 1) * 16 * channel * 2;
    else
        inputLen1 = (((N - 1) / 16) + 1) * 16 * channel * 2;

    if (mode == 0)
        outputLen = ((((((N - F) / S) + 2 * zero + 1) * (((N - F) / S) + 2 * zero + 1) - 1) / 16) + 1) * 16 * channel * 2;
    else
        outputLen = ((((((N - F) / S) + zero + 1) - 1) / 16) + 1) * 16 * channel * 2;

    height = N;
    L = ((N - F) / S) + 1;
    M = ((height - F) / S) + 1;
    L_M = (((N - F) / S) + 1) * (((N - F) / S) + 1);
    L_M_padding = ((((N - F) / S) + 1) + 2 * zero) * ((((N - F) / S) + 1) + 2 * zero);

    height_k = 0; //å°ç¹ä¸ç¨
    height_last = 0;
    M_last = 0;
    L_M_last = 0;
    L_M_last_padding = 0;

    other_para_L = (channel << 24) | (height << 16) | (zero << 8) | N;
    other_para_H = (mul_trunc << 13) | (add_trunc << 8) | (max_or_avg << 7) | (height_flag << 6) | (mode << 5) | (F << 2) | S;

    other_para_H2 = (M << 24) | (L << 16);
    other_para_L2 = 0; //wxy 210615

    huge_ddr_times = 0; //è´è´£äººèªè¡è¡¥å

    maxtrix_addr_acc = (L_M << 16) | (M_last << 8) | height_last;
    inputLen5 = (height_k << 16) | L_M_last;
    inputAddr5_H = (L_M_last_padding << 16) | L_M_padding;
    inputAddr5_L = 0; //wxy 210615

    Call_Type = 32; //10010 swq 210615
    Config_avail = 1;
    Mode_alg = 1;
    config = (Call_Type << 8) | (Config_avail << 2) | (Mode_alg << 1);

    param_cfg = (Mode_alg << 1) | (Config_avail << 2) | (Batch_finish << 5) | (Batch_mark << 6) | (Resp_Type << 7) | (Call_Type << 8);

    SetReg(INPUT_ADDR3H, inputAddr3_H);
    SetReg(INPUT_ADDR3L, inputAddr3_L);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, 0);
    SetReg(INPUT_ADDR5H, inputAddr5_H);
    SetReg(INPUT_ADDR5L, inputAddr5_L);
    SetReg(INPUT_LEN5, inputLen5);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, other_para_H2);
    SetReg(OTHER_PARAL2, other_para_L2);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, inputLen1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, 0);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, outputLen);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, maxtrix_addr_acc);
    SetReg(OTHER_PARAH, other_para_H);
    SetReg(OTHER_PARAL, other_para_L);
    SetReg(PARA_CONFIG, param_cfg);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

int setLSTM(u32 lstm_input, u32 lstm_hidden, u32 lstm_step, u32 lstm_batch, u32 pingpong_type, u32 lstm_step_block,
            u32 lstm_last_step, u32 ht_size_div, u32 last_wt_row, u32 trunc_add, u32 trunc_mac, u32 trunc_mul_out_par,
            u32 activ_int_bit1, u32 activ_int_bit2, u32 activ_res_int_bit1, u32 activ_res_int_bit2,
            u32 input_step, u32 hidden_step, u32 activ_mode1, u32 activ_mode2, u32 trunc_add2, u32 trunc_bias,
            u32 inputAddr1_H, u32 inputAddr1_L, u32 inputAddr2_H, u32 inputAddr2_L, u32 inputAddr4_H, u32 inputAddr4_L,
            u32 outputAddr_H, u32 outputAddr_L,
            u32 Resp_Type, u32 Batch_mark, u32 Batch_finish)
{
    u32 Call_Type;
    u32 Config_avail;
    u32 Mode_alg;
    u32 config;
    u32 lstm_step_L;
    u32 lstm_step_H;
    u32 lstm_last_step_L;
    u32 lstm_last_step_H;
    u32 last_wt_row_L;
    u32 last_wt_row_H;
    u32 other_para_H2;
    u32 other_para_L2;
    u32 other_para_H;
    u32 other_para_L;
    u32 matrix_config;
    u32 inputLen5;
    u32 inputLen1;
    u32 inputLen2;
    u32 inputLen4;
    u32 outputLen;
    u32 huge_ddr_times;

    lstm_step_L = lstm_step % (1 << 5);                  // other_para[31:27]  wqh 0611
    lstm_step_H = (lstm_step >> 5) % (1 << 6);           // other_para[37:32]
    lstm_last_step_L = lstm_last_step % 4;               //other_para[63:62]
    lstm_last_step_H = (lstm_last_step >> 2) % (1 << 9); //other_para[72:64]
    last_wt_row_L = last_wt_row % (1 << 9);              //other_para[95:87]
    last_wt_row_H = (last_wt_row >> 9) % (1 << 4);       //other_para[99:96]

    other_para_H2 = last_wt_row_H | (trunc_add << (100 - 96)) | (trunc_mac << (105 - 96)) | (trunc_mul_out_par << (110 - 96)) | (activ_int_bit1 << (115 - 96)) | (activ_int_bit2 << (119 - 96)) | (activ_res_int_bit1 << (123 - 96));
    other_para_L2 = lstm_last_step_H | (ht_size_div << (74 - 64)) | (last_wt_row_L << (87 - 64));
    other_para_H = lstm_step_H | (lstm_batch << (38 - 32)) | (pingpong_type << (44 - 32)) | (lstm_step_block << (51 - 32)) | (lstm_last_step_L << (62 - 32));
    other_para_L = lstm_input | (lstm_hidden << 14) | (lstm_step_L << 27);

    matrix_config = activ_res_int_bit2 | (activ_mode1 << 4) | (activ_mode2 << 7) | (trunc_add2 << 10) | (trunc_bias << 15);
    inputLen5 = input_step | (hidden_step << 10);

    inputLen1 = (((lstm_input * lstm_step - 1) / 16) + 1) * 16 * lstm_batch * 2; //@wqh 0611
    inputLen2 = (((lstm_input + lstm_hidden - 1) / 16) + 1) * 16 * lstm_hidden * 4 * 2;
    inputLen4 = ((lstm_hidden - 1) / 16 + 1) * 16 * 4 * 2;
    outputLen = (((lstm_hidden * lstm_step - 1) / 16) + 1) * 16 * lstm_batch * 2;
    huge_ddr_times = 0; //\u8d1f\u8d23\u4eba\u81ea\u884c\u8865\u5145

    Call_Type = 37; //10101
    Config_avail = 1;
    Mode_alg = 1;
    config = (Call_Type << 8) | (Config_avail << 2) | (Mode_alg << 1);

    SetReg(INPUT_ADDR3H, 0);
    SetReg(INPUT_ADDR3L, 0);
    SetReg(INPUT_LEN3, 0);
    SetReg(INPUT_ADDR4H, inputAddr4_H);
    SetReg(INPUT_ADDR4L, inputAddr4_L);
    SetReg(INPUT_LEN4, inputLen4);
    SetReg(INPUT_ADDR5H, 0);
    SetReg(INPUT_ADDR5L, 0);
    SetReg(INPUT_LEN5, inputLen5);
    SetReg(HUGE_DATA_DDR_TIMES2, 0);
    SetReg(OTHER_PARAH2, other_para_H2);
    SetReg(OTHER_PARAL2, other_para_L2);
    SetReg(INPUT_ADDR1H, inputAddr1_H);
    SetReg(INPUT_ADDR1L, inputAddr1_L);
    SetReg(INPUT_LEN1, inputLen1);
    SetReg(INPUT_ADDR2H, inputAddr2_H);
    SetReg(INPUT_ADDR2L, inputAddr2_L);
    SetReg(INPUT_LEN2, inputLen2);
    SetReg(OUTPUT_ADDRH, outputAddr_H);
    SetReg(OUTPUT_ADDRL, outputAddr_L);
    SetReg(OUTPUT_LEN, outputLen);
    SetReg(HUGE_DATA_DDR_TIMES, huge_ddr_times);
    SetReg(MATRIX_CONFIG, matrix_config);
    SetReg(OTHER_PARAH, other_para_H);
    SetReg(OTHER_PARAL, other_para_L);
    SetReg(PARA_CONFIG, config);

#ifdef TEST_API
    for (i = 0x0; i <= 0x64; i += 4)
    {
        ReadReg(INPUT_ADDR1H + i, config);
        DBPRINT("address = 0x%x, config = 0x%x\r\n", INPUT_ADDR1H + i, config);
    }
#endif
    return 0;
}

BOOL SramAvail(void)
{
    u32 R_status;
    R_status = InqStatus();
    if ((R_status & 0x00000080) == 0x0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

u32 InqStatus(void)
{
    u32 R_status;
    ReadReg(STATUS_CON, R_status);
    return R_status;
}

BOOL InqRTestfinish(void)
{
    u32 R_status;
    R_status = InqStatus();
    if ((R_status & 0x2000) == 0x2000)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL InqRResponse(void)
{
    u32 R_status;
    R_status = InqStatus();
    if ((R_status & 0x1000) == 0x1000)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL InqRDone(void)
{
    u32 R_status;
    ReadReg(STATUS_CON, R_status);
    //	DBPRINT("R-status = 0x%x,R_status & 0x400 = 0x%x\r\n",R_status,(R_status & 0x400));
    if ((R_status & 0x400) == 0x400)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL InqRInte(void)
{
    u32 R_status;
    ReadReg(STATUS_CON, R_status);
    if ((R_status & 0x10) == 0x10)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

u32 InqRCalcType(void)
{
    u32 R_status;
    ReadReg(STATUS_CON, R_status);
    return ((R_status >> 17) & 0x1F);
}

BOOL InqRInteErr(void)
{
    u32 R_status;
    ReadReg(STATUS_CON, R_status);
    if ((R_status & 0x10000) == 0x10000)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL InqRLastResp(void)
{
    u32 R_status;
    ReadReg(STATUS_CON, R_status);
    if ((R_status & 0x8000) == 0x8000)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
//
u32 InqInt(void)
{
    u32 intr_state;
    ReadReg(INTR_STATE, intr_state);
    return intr_state;
}

u32 InqIntECC(void)
{
    u32 intr_state;
    ReadReg(INTR_STATE, intr_state);
    return ((intr_state >> 28) & 0x3);
}

u32 InqIntIpnum(void)
{
    u32 intr_state;
    ReadReg(INTR_STATE, intr_state);
    return ((intr_state >> 12) & 0xFFFF);
}

u32 InqIntIptype(void)
{
    u32 intr_state;
    ReadReg(INTR_STATE, intr_state);
    return ((intr_state >> 6) & 0x3F);
}

u32 InqIntErrtype(void)
{
    u32 intr_state;
    ReadReg(INTR_STATE, intr_state);
    return (intr_state & 0x3F);
}

u32 InqIntDiv(void)
{
    u32 intr_div;
    ReadReg(INTR_DIV, intr_div);
    return intr_div;
}

u32 InqIntRMul1(void)
{
    u32 intr_rmul;
    ReadReg(INTR_RMUL1, intr_rmul);
    return intr_rmul;
}

u32 InqIntRMul2(void)
{
    u32 intr_rmul;
    ReadReg(INTR_RMUL2, intr_rmul);
    return intr_rmul;
}

u32 InqIntPMul1(void)
{
    u32 intr_pmul;
    //ReadReg(INTR_PMUL, intr_pmul);
    return intr_pmul;
}

u32 InqIntPMul2(void)
{
    u32 intr_pmul;
    //ReadReg(INTR_PMUL, intr_pmul);
    return intr_pmul;
}

u32 InqIntPAdd1(void)
{
    u32 intr_padd;
    ReadReg(INTR_PADD1, intr_padd);
    return intr_padd;
}

u32 InqIntPAdd2(void)
{
    u32 intr_padd;
    ReadReg(INTR_PADD2, intr_padd);
    return intr_padd;
}

u32 InqIntPAdd3(void)
{
    u32 intr_padd;
    ReadReg(INTR_PADD3, intr_padd);
    return intr_padd;
}

u32 InqIntPAdd4(void)
{
    u32 intr_padd;
    ReadReg(INTR_PADD4, intr_padd);
    return intr_padd;
}

u32 InqIntPAdd5(void)
{
    u32 intr_padd;
    ReadReg(INTR_PADD4, intr_padd);
    return intr_padd;
}

u32 InqIntRAdd1(void)
{
    u32 intr_radd;
    ReadReg(INTR_RADD1, intr_radd);
    return intr_radd;
}

u32 InqIntRAdd2(void)
{
    u32 intr_radd;
    ReadReg(INTR_RADD2, intr_radd);
    return intr_radd;
}

u32 InqIntExp1(void)
{
    u32 intr_exp;
    ReadReg(INTR_EXP1, intr_exp);
    return intr_exp;
}

u32 InqIntExp2(void)
{
    u32 intr_exp;
    ReadReg(INTR_EXP2, intr_exp);
    return intr_exp;
}

u32 InqIntTrans(void)
{
    u32 intr_trans;
    ReadReg(INTR_TRANS, intr_trans);
    return intr_trans;
}

u32 InqIntComp1(void)
{
    u32 intr_comp;
    ReadReg(INTR_COMP1, intr_comp);
    return intr_comp;
}

u32 InqIntComp2(void)
{
    u32 intr_comp;
    ReadReg(INTR_COMP2, intr_comp);
    return intr_comp;
}

u32 InqIntComp3(void)
{
    u32 intr_comp;
    ReadReg(INTR_COMP3, intr_comp);
    return intr_comp;
}

u32 InqIntComp4(void)
{
    u32 intr_comp;
    ReadReg(INTR_COMP4, intr_comp);
    return intr_comp;
}

u32 InqIntFixRMul(void)
{
    u32 intr_fixm;
    ReadReg(INTR_FIXM, intr_fixm);
    return intr_fixm;
}

int setMasterAddr(u64 Master_ddr_Addr)
{
    u32 master_addrl;
    u32 master_addrh;
    if (!COMP(Master_ddr_Addr, ADDR_LOW, ADDR_HIGH))
    {
        return -1;
    }
    master_addrl = (u32)(Master_ddr_Addr);
    master_addrh = (u32)(Master_ddr_Addr >> 32);

    SetReg(MASTER_ADDRH, master_addrh);
    SetReg(MASTER_ADDRL, master_addrl);
    return 0;
}

int getCalculationParam(CalParam* cal_param)
{
    u32 reg;
    int cal_number;

    u32 input_addr1h;
    u32 input_addr1l;
    u32 input_len1;
    u32 input_addr2h;
    u32 input_addr2l;
    u32 input_len2;
    u32 output_addrh;
    u32 output_addrl;
    u32 output_len;
    u32 huge_data;
    u32 matrix_config;
    u32 other_paramh;
    u32 other_paraml;
    u32 config;
    u32 input_addr3h;
    u32 input_addr3l;
    u32 input_len3;
    u32 input_addr4h;
    u32 input_addr4l;
    u32 input_len4;
    u32 input_addr5h;
    u32 input_addr5l;
    u32 input_len5;
    u32 huge_data2;
    u32 other_paramh2;
    u32 other_paraml2;

    u32 arow;
    u32 arow_last;

    ReadReg(STATUS_CON, reg);
    cal_number = (reg & 0x60) >> 5;
    switch (cal_number)
    {
    case 0:
        ReadReg(OP1_INPUT_ADDR1H, input_addr1h);
        ReadReg(OP1_INPUT_ADDR1L, input_addr1l);
        ReadReg(OP1_INPUT_LEN1, input_len1);
        ReadReg(OP1_INPUT_ADDR2H, input_addr2h);
        ReadReg(OP1_INPUT_ADDR2L, input_addr2l);
        ReadReg(OP1_INPUT_LEN2, input_len2);
        ReadReg(OP1_OUTPUT_ADDRH, output_addrh);
        ReadReg(OP1_OUTPUT_ADDRL, output_addrl);
        ReadReg(OP1_OUTPUT_LEN, output_len);
        ReadReg(OP1_HUGE_DATA_DDR_TIMES, huge_data);
        ReadReg(OP1_MATRIX_CONFIG, matrix_config);
        ReadReg(OP1_OTHER_PARAH, other_paramh);
        ReadReg(OP1_OTHER_PARAL, other_paraml);
        ReadReg(OP1_PARA_CONFIG, config);
        ReadReg(OP1_INPUT_ADDR3H, input_addr3h);
        ReadReg(OP1_INPUT_ADDR3L, input_addr3l);
        ReadReg(OP1_INPUT_LEN3, input_len3);
        ReadReg(OP1_INPUT_ADDR4H, input_addr4h);
        ReadReg(OP1_INPUT_ADDR4L, input_addr4l);
        ReadReg(OP1_INPUT_LEN4, input_len4);
        ReadReg(OP1_INPUT_ADDR5H, input_addr5h);
        ReadReg(OP1_INPUT_ADDR5L, input_addr5l);
        ReadReg(OP1_INPUT_LEN5, input_len5);
        ReadReg(OP1_HUGE_DATA_DDR_TIMES2, huge_data2);
        ReadReg(OP1_OTHER_PARAH2, other_paramh2);
        ReadReg(OP1_OTHER_PARAL2, other_paraml2);
        break;

    case 1:
        ReadReg(OP2_INPUT_ADDR1H, input_addr1h);
        ReadReg(OP2_INPUT_ADDR1L, input_addr1l);
        ReadReg(OP2_INPUT_LEN1, input_len1);
        ReadReg(OP2_INPUT_ADDR2H, input_addr2h);
        ReadReg(OP2_INPUT_ADDR2L, input_addr2l);
        ReadReg(OP2_INPUT_LEN2, input_len2);
        ReadReg(OP2_OUTPUT_ADDRH, output_addrh);
        ReadReg(OP2_OUTPUT_ADDRL, output_addrl);
        ReadReg(OP2_OUTPUT_LEN, output_len);
        ReadReg(OP2_HUGE_DATA_DDR_TIMES, huge_data);
        ReadReg(OP2_MATRIX_CONFIG, matrix_config);
        ReadReg(OP2_OTHER_PARAH, other_paramh);
        ReadReg(OP2_OTHER_PARAL, other_paraml);
        ReadReg(OP2_PARA_CONFIG, config);
        ReadReg(OP2_PARA_CONFIG, config);
        ReadReg(OP2_INPUT_ADDR3H, input_addr3h);
        ReadReg(OP2_INPUT_ADDR3L, input_addr3l);
        ReadReg(OP2_INPUT_LEN3, input_len3);
        ReadReg(OP2_INPUT_ADDR4H, input_addr4h);
        ReadReg(OP2_INPUT_ADDR4L, input_addr4l);
        ReadReg(OP2_INPUT_LEN4, input_len4);
        ReadReg(OP2_INPUT_ADDR5H, input_addr5h);
        ReadReg(OP2_INPUT_ADDR5L, input_addr5l);
        ReadReg(OP2_INPUT_LEN5, input_len5);
        ReadReg(OP2_HUGE_DATA_DDR_TIMES2, huge_data2);
        ReadReg(OP2_OTHER_PARAH2, other_paramh2);
        ReadReg(OP2_OTHER_PARAL2, other_paraml2);
        break;

    case 2:
        ReadReg(OP3_INPUT_ADDR1H, input_addr1h);
        ReadReg(OP3_INPUT_ADDR1L, input_addr1l);
        ReadReg(OP3_INPUT_LEN1, input_len1);
        ReadReg(OP3_INPUT_ADDR2H, input_addr2h);
        ReadReg(OP3_INPUT_ADDR2L, input_addr2l);
        ReadReg(OP3_INPUT_LEN2, input_len2);
        ReadReg(OP3_OUTPUT_ADDRH, output_addrh);
        ReadReg(OP3_OUTPUT_ADDRL, output_addrl);
        ReadReg(OP3_OUTPUT_LEN, output_len);
        ReadReg(OP3_HUGE_DATA_DDR_TIMES, huge_data);
        ReadReg(OP3_MATRIX_CONFIG, matrix_config);
        ReadReg(OP3_OTHER_PARAH, other_paramh);
        ReadReg(OP3_OTHER_PARAL, other_paraml);
        ReadReg(OP3_PARA_CONFIG, config);
        ReadReg(OP3_PARA_CONFIG, config);
        ReadReg(OP3_INPUT_ADDR3H, input_addr3h);
        ReadReg(OP3_INPUT_ADDR3L, input_addr3l);
        ReadReg(OP3_INPUT_LEN3, input_len3);
        ReadReg(OP3_INPUT_ADDR4H, input_addr4h);
        ReadReg(OP3_INPUT_ADDR4L, input_addr4l);
        ReadReg(OP3_INPUT_LEN4, input_len4);
        ReadReg(OP3_INPUT_ADDR5H, input_addr5h);
        ReadReg(OP3_INPUT_ADDR5L, input_addr5l);
        ReadReg(OP3_INPUT_LEN5, input_len5);
        ReadReg(OP3_HUGE_DATA_DDR_TIMES2, huge_data2);
        ReadReg(OP3_OTHER_PARAH2, other_paramh2);
        ReadReg(OP3_OTHER_PARAL2, other_paraml2);
        break;

    case 3:
        ReadReg(OP4_INPUT_ADDR1H, input_addr1h);
        ReadReg(OP4_INPUT_ADDR1L, input_addr1l);
        ReadReg(OP4_INPUT_LEN1, input_len1);
        ReadReg(OP4_INPUT_ADDR2H, input_addr2h);
        ReadReg(OP4_INPUT_ADDR2L, input_addr2l);
        ReadReg(OP4_INPUT_LEN2, input_len2);
        ReadReg(OP4_OUTPUT_ADDRH, output_addrh);
        ReadReg(OP4_OUTPUT_ADDRL, output_addrl);
        ReadReg(OP4_OUTPUT_LEN, output_len);
        ReadReg(OP4_HUGE_DATA_DDR_TIMES, huge_data);
        ReadReg(OP4_MATRIX_CONFIG, matrix_config);
        ReadReg(OP4_OTHER_PARAH, other_paramh);
        ReadReg(OP4_OTHER_PARAL, other_paraml);
        ReadReg(OP4_PARA_CONFIG, config);
        ReadReg(OP4_PARA_CONFIG, config);
        ReadReg(OP4_INPUT_ADDR3H, input_addr3h);
        ReadReg(OP4_INPUT_ADDR3L, input_addr3l);
        ReadReg(OP4_INPUT_LEN3, input_len3);
        ReadReg(OP4_INPUT_ADDR4H, input_addr4h);
        ReadReg(OP4_INPUT_ADDR4L, input_addr4l);
        ReadReg(OP4_INPUT_LEN4, input_len4);
        ReadReg(OP4_INPUT_ADDR5H, input_addr5h);
        ReadReg(OP4_INPUT_ADDR5L, input_addr5l);
        ReadReg(OP4_INPUT_LEN5, input_len5);
        ReadReg(OP4_HUGE_DATA_DDR_TIMES2, huge_data2);
        ReadReg(OP4_OTHER_PARAH2, other_paramh2);
        ReadReg(OP4_OTHER_PARAL2, other_paraml2);
        break;

    default:
        break;
    }

    cal_param->cal_type = (config & 0x3f00) >> 8; //@swq 0331
    cal_param->input_addr1 = ((u64)input_addr1h << 32) | input_addr1l;
    cal_param->input_addr2 = ((u64)input_addr2h << 32) | input_addr2l;
    cal_param->input_addr3 = ((u64)input_addr3h << 32) | input_addr3l;
    cal_param->input_addr4 = ((u64)input_addr4h << 32) | input_addr4l;
    cal_param->output_addr = ((u64)output_addrh << 32) | output_addrl;
    cal_param->resp_type = (config & 0x80) >> 7;
    cal_param->batch_mark = (config & 0x40) >> 6;
    cal_param->last_config = (config & 0x20) >> 5;
    cal_param->test_break = (config & 0xf0000) >> 16;

    switch (cal_param->cal_type)
    {
        /*case FFT_ID:
        cal_param->param[0] = (other_paramh & 0x7fffff8) >> 3;
        cal_param->param[1] = (other_paramh & 0x6) >> 1;
        cal_param->param[2] = (other_paramh & 0x1);
        break;

    case MAT_MUL_ID:
        if(huge_data == 0){
            cal_param->param[0] = (other_paramh & 0xfff0000) >> 16;
            cal_param->param[1] = (other_paramh & 0x1fff);
            cal_param->param[2] = (output_len >> 3) / cal_param->param[0];
        }
        else if((huge_data & 0xffff) == 0){
            cal_param->param[1] = (other_paramh & 0x1fff);
            arow = (other_paramh & 0xfff000) >> 16;
            arow_last = (matrix_config & 0xffff) / cal_param->param[1];
            cal_param->param[0] = arow * ((huge_data & 0xffff0000) >> 16) + arow_last;
            cal_param->param[2] = (output_len >> 3) / arow;
        }
        else{
            cal_param->param[0] = (huge_data & 0xffff0000) >> 16;
            cal_param->param[1] = (input_len1 >> 3);
            cal_param->param[2] = (matrix_config & 0xffff0000) >> 16;
        }
        break;

    case MAT_COV_ID:
        if(huge_data == 0){
            cal_param->param[0] = (other_paramh & 0xffff0000) >> 16;
            cal_param->param[1] = (other_paramh & 0xffff);
        }
        else{
            cal_param->param[0] = (huge_data & 0xffff0000) >> 16;
            cal_param->param[1] = (other_paramh & 0xffff);
        }
        break;

    case PLU_FIR_ID:

    case REAL_FIR_ID:

    case PLU_DOP_ID:

    case REAL_DOP_ID:

    case SYMM_FIR_ID:
        cal_param->param[0] = (other_paramh & 0x3ffff00) >> 8;
        cal_param->param[1] = (other_paramh & 0xff);
        break;

    case SELF_CORR_ID:
        cal_param->param[0] = (other_paramh & 0x3ffff);
        break;

    case CROSS_CORR_ID:
        cal_param->param[0] = (other_paramh & 0x3ffff);
        cal_param->param[1] = (other_paraml & 0x3ffff);
        break;

    case MAT_ADD_ID:
        cal_param->param[0] = ((other_paramh & 0x7fffe) >> 1) + 0x8000 * huge_data;
        cal_param->param[1] = (other_paramh & 0x1);
        break;

    case MAT_DOT_ID:
        cal_param->param[0] = ((other_paramh & 0x7fffe) >> 1) + 0x8000 * huge_data;
        break;

    case MAT_CONJ_ID:
        cal_param->param[0] = (other_paramh & 0x3ffff) + 0x10000 * huge_data;
        break;

    case MAT_INV_ID:
        cal_param->param[0] = (other_paramh & 0xff);
        break;

    case DIV_ID:
        cal_param->param[0] = ((other_paramh & 0x3fffe) >> 1) + 0x10000 * huge_data;
        cal_param->param[1] = (other_paramh & 0x1);
        break;

    case MOD_ID:
        cal_param->param[0] = (other_paramh & 0x1ffff) + 0x10000 * huge_data;
        break;

    case FIX_ID:
        cal_param->param[0] = ((other_paramh & 0x7fffe) >> 1) + 0x20000 * huge_data;
        cal_param->param[1] = (other_paramh & 0x1);
        break;

    case MAT_TRANS_ID:
        cal_param->param[0] = matrix_config;
        cal_param->param[1] = input_len2;
        cal_param->param[2] = other_paraml;
        cal_param->param[3] = (other_paramh & 0x1fffffff);
        cal_param->param[4] = (other_paramh & 0x60000000) >> 29;
        break;*/

    default:
        break;
    }

    return 0;
}

void compare_rlt_offset(unsigned int len, unsigned short int step, u64 r_addr, u64 g_addr, short int offset)
{
    u32 val_r, val_g;
    //unsigned int *p0,*p1;
    printf("compare_rlt start.\n");
    int i;
    if (step == 2)
    {
        for (i = 0; i < len; i = i + offset)
        {
            val_r = phx_read_u16(0xFFFFFFFF80000000 | r_addr + i * step);
            val_g = phx_read_u16(0xFFFFFFFF80000000 | g_addr + i * step);

            if (val_r != val_g)
                printf("ERR!i=%x,1_r_d=%x,1_g_d=%x		\n", i, val_r, val_g);

            if (i == 0)
                printf("1_r_d=%x,1_g_d=%x		\n", val_r, val_g);
        }
    }
    else if (step == 4)
    {
        for (i = 0; i < len; i = i + offset)
        {
            val_r = phx_read_u32(0xFFFFFFFF80000000 | r_addr + i * step);
            val_g = phx_read_u32(0xFFFFFFFF80000000 | g_addr + i * step);

            if (val_r != val_g)
                printf("ERR!i=%x,1_r_d=%x,1_g_d=%x		\n", i, val_r, val_g);

            if (i == 0)
                printf("1_r_d=%x,1_g_d=%x		\n", val_r, val_g);
        }
    }
}

void soft_max(u64 r_addr, u64 s_addr, unsigned short batch, unsigned short int step, short int classified_num)
{
    //FC3 + RELUï¼res>=0
    int m;
    int i;
    u32 val_r;

    u32 flag;
    u32 old_val;
    flag = 0;
    old_val = 0;

    u32 batch_addr_offset;
    batch_addr_offset = classified_num * step;

    for (m = 0; m < batch; m = m + 1)
    {
        flag = 0;
        old_val = 0;
        if (step == 2)
        {
            for (i = 0; i < classified_num; i = i + 1)
            {
                val_r = phx_read_u16(0xFFFFFFFF80000000 | (r_addr + batch_addr_offset * m) + i * step);
                if (val_r > old_val)
                {
                    flag = i;
                    old_val = val_r;
                }
            }
        }
        else if (step == 4)
        {
            for (i = 0; i < classified_num; i = i + 1)
            {
                val_r = phx_read_u32(0xFFFFFFFF80000000 | (r_addr + batch_addr_offset * m) + i * step);
                if (val_r > old_val)
                {
                    flag = i;
                    old_val = val_r;
                }
            }
        }

        if (m == 0)
        {
            printf("first flag:%d\n", flag);
        }

        if (step == 2)
        {
            phx_write_u16((0xFFFFFFFF80000000 | s_addr + m * step), flag);
        }
        else if (step == 4)
        {
            phx_write_u32((0xFFFFFFFF80000000 | s_addr + m * step), flag);
        }
    }
}

void cal_resp_proc(u32 resptype)
{
    u32 val;
    u64 val_pic;

    if (resptype)
    {
        do {
            ReadReg(0x1f0701ac, val);
            printf("IntMode:rasp is running.	\n");

        } while ((val & 0x10) == 0);

        ReadReg(0x1f0701ac, val);
        printf("0x1f0701ac read : %x,end	\n", val);

        //    	 val_pic = readl( PIC_INT_STA);
        //            if(val_pic & RASP_INTE){
        //                    printf("pic RASP intr! 	\n");
        setIntZero(1);
        setIntZero(0);
        //            }
        //            else{
        //                    printf("error pic_rasp not intr!%x 	\n",(val_pic & RASP_INTE));
        //            }
        //
        //    	writel(RASP_INTE, PIC_INT_CLR);   //clear pic intr
    }
    else
    {
        while (1)
        {
            if (InqRDone())
            {
                printf("NormalMode: done!	\n");
                setIntZero(1);
                setIntZero(0);
                break;
            }
            printf("NormalMode:rasp is running.	\n");
        }
    }

    if (InqRInteErr())
    {
        printf("rasp clear abnormal err!   \n");

        setAbnormZero(1);
        setAbnormZero(0);
    }
}

u32 get_bin_size(const char* filename)
{
    u32 siz = 0;
    FILE* fp = fopen(filename, "rb");
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        siz = ftell(fp);
        fclose(fp);
    }
    else
    {
        printf("\n Can not open the filename:%s\n", filename);
        exit(-1);
    }
    printf("\nfilename=%s, size=%d\n", filename, siz);
    return siz;
}
void read_bin(const char* path, s16* buf, u32 size)
{
    FILE* infile;
    if ((infile = fopen(path, "rb")) == NULL)
    {
        printf("\n Can not open the path:%s\n", path);
        exit(-1);
    }
    fread(buf, sizeof(s16), size, infile);
    fclose(infile);
}

char* load_file_to_memory(const char* filename)
{
    FILE* fp;
    if ((fp = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Error: load file: %s\n", filename);
        return NULL;
    }
    //å°æä»¶æéç§»å°æ«å°¾
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp); //éè¿ftellå½æ°è·å¾æéå°æä»¶å¤´çåç§»å­èæ°ã
    char* str;
    //	printf("filesizeï¼%d\n", filesize);
    str = (char*)malloc(filesize); //å¨æåéstråå­
    fgets(str, filesize, fp);
    fclose(fp);
    return str;
}

int lenet_main(void)
{
    printf("Test Here:\n");

    unsigned int i;
    choose_no(0);

    u32 val, val1, val2, size;
    u64 val_pic, s1, s2, res_phy;
    u32 resptype = 0;

    int tt, pp;

    //	writel(0x0000000000000000, PIC_INT_MASK);
    //	writel(0xffffffffffffffff, PIC_INT_EN);
    //	writel(0xffffffffffffffff, PIC_INT_MODE);

    //	phx_write_u32(0x1f0c0018, 0xa5accede);
    //	phx_write_u32(0x1f0c0004, 0xee);
    SetReg(0x1f0c0018, 0xa5accede);
    SetReg(0x1f0c0004, 0xee);

    const char* filename_conv1_src_in = "./ffx0/lenet5_data/conv1_src_in.bin";
    //	char *str_conv1_src_in = load_file_to_memory(filename_conv1_src_in);
    u32 size_conv1_src_in = get_bin_size(filename_conv1_src_in);
    s16* src_conv1_src_in = (s16*)malloc(size_conv1_src_in);
    read_bin(filename_conv1_src_in, src_conv1_src_in, size_conv1_src_in);
    printf("0x%x\n", src_conv1_src_in);
    u32 k = 0;

    const char* filename_conv1_wb = "./ffx0/lenet5_data/conv1_wb.bin";
    //	char *str_conv1_wb = load_file_to_memory(filename_conv1_wb);
    size = get_bin_size(filename_conv1_wb);
    s16* src_conv1_wb = (s16*)malloc(size);
    read_bin(filename_conv1_wb, src_conv1_wb, size);
    printf("0x%x\n", src_conv1_wb);

    //	for (k=0;k<src_conv1_wb;k++){
    //		printf("%d ",src_conv1_wb[k]);
    //		if(k%30==0) printf("\n");
    //	}
    //	exit(-1);

    const char* filename_conv2_wb = "./ffx0/lenet5_data/conv2_wb.bin";
    size = get_bin_size(filename_conv2_wb);
    s16* src_conv2_wb = (s16*)malloc(size);
    read_bin(filename_conv2_wb, src_conv2_wb, size);
    printf("0x%x\n", src_conv2_wb);

    const char* filename_fc1_wt = "./ffx0/lenet5_data/fc1_wt.bin";
    size = get_bin_size(filename_fc1_wt);
    s16* src_fc1_wb = (s16*)malloc(size);
    read_bin(filename_fc1_wt, src_fc1_wb, size);
    printf("0x%x\n", src_fc1_wb);

    const char* filename_fc1_bias = "./ffx0/lenet5_data/fc1_bias.bin";
    size = get_bin_size(filename_fc1_bias);
    s16* src_fc1_bias = (s16*)malloc(size);
    read_bin(filename_fc1_bias, src_fc1_bias, size);
    printf("0x%x\n", src_fc1_bias);

    const char* filename_fc2_wt = "./ffx0/lenet5_data/fc2_wt.bin";
    size = get_bin_size(filename_fc2_wt);
    s16* src_fc2_wb = (s16*)malloc(size);
    read_bin(filename_fc2_wt, src_fc2_wb, size);
    printf("0x%x\n", src_fc2_wb);

    const char* filename_fc2_bias = "./ffx0/lenet5_data/fc2_bias.bin";
    size = get_bin_size(filename_fc2_bias);
    s16* src_fc2_bias = (s16*)malloc(size);
    read_bin(filename_fc2_bias, src_fc2_bias, size);
    printf("0x%x\n", src_fc2_bias);

    const char* filename_fc3_wt = "./ffx0/lenet5_data/fc3_wt.bin";
    size = get_bin_size(filename_fc3_wt);
    s16* src_fc3_wb = (s16*)malloc(size);
    read_bin(filename_fc3_wt, src_fc3_wb, size);
    printf("0x%x\n", src_fc3_wb);

    const char* filename_fc3_bias = "./ffx0/lenet5_data/fc3_bias.bin";
    size = get_bin_size(filename_fc3_bias);
    s16* src_fc3_bias = (s16*)malloc(size);
    read_bin(filename_fc3_bias, src_fc3_bias, size);
    printf("0x%x\n", src_fc3_bias);

    const char* filename_fc3_gloden_res = "./ffx0/lenet5_data/fc3_gloden_res.bin";
    u32* size_fc3_gloden_res = get_bin_size(filename_fc3_gloden_res);
    s16* src_fc3_gloden_res = (s16*)malloc(size_fc3_gloden_res);
    read_bin(filename_fc3_gloden_res, src_fc3_gloden_res, size_fc3_gloden_res);
    printf("0x%x\n", src_fc3_gloden_res);

    const char* filename_test_flag = "./ffx0/lenet5_data/test_flag.bin";
    u32 size_test_flag = get_bin_size(filename_test_flag);
    s16* src_test_flag = (s16*)malloc(size_test_flag);
    read_bin(filename_test_flag, src_test_flag, size_test_flag);
    printf("0x%x\n", src_test_flag);

    int cnt = 32; //10000;//æå¤10000ä¸ªæµè¯é

    fprintf(stderr, "Lenet5-MNIST! \n");

    s16* soft_max_out = (s16*)malloc(size_test_flag);
    s16* src_fc_out3 = (s16*)malloc(size_fc3_gloden_res);
    //	s16 *soft_max_out;
    //	s16 *src_fc_out3;
    for (tt = 0; tt < cnt / 16; tt = tt + 1) //batch=16
    {
        printk("TESTSET %d-%d!\n", tt * 16 + 1, (tt + 1) * 16);
        //CONV1
        s16 src_conv1_src_out[1024];

        if (RegEnable())
        {
            setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
            setSlaveMode();
            fprintf(stdout, "CONV1 config start! \n");
            //			fprintf(stdout, "INPUT_ADDR3H: 0x%x      \n",INPUT_ADDR3H);
            //			fprintf(stdout, "DEVICE_CON: 0x%x      \n",DEVICE_CON);
            //setConv_small(32,32,28,28,5,5,6,1,1,0,32,3,0,0,0,u32 trunc_sum_out_par,1,0,0,0,0x2000000,0,0x2010000,0,0,0,0,0,0x2080000,resptype,0,0);

            //			setConv_small(28,28,24,24,5,5,6,1,1,0,16,3,0,0,0,8,1,0,0,0,0x4000000+tt*28*28*2*16,0,0x2080000,0,0,0,0,0,0x3000000,resptype,0,0);

            setConv_small(28, 28, 24, 24, 5, 5, 6, 1, 1, 0, 16, 3, 0, 0, 0, 8, 1, 0, 0, 0, hrKmToPhys(src_conv1_src_in) + tt * 28 * 28 * 2 * 16, 0, hrKmToPhys(src_conv1_wb), 0, 0, 0, 0, 0, hrKmToPhys(src_conv1_src_out), resptype, 0, 0);
            //setConv_small(14,14,10,10,5,5,16,6,1,0,1,3,0,0,0,12,0,0,0,0,0x2000000,0,0x2010000,0,0,0,0,0,0x2080000,resptype,0,0);
        }

        printf("CONV1 config done! \n");
        cal_resp_proc(resptype);
        printf("CONV1 done \n");
        s16 src_pool_out1[1024];

        //POOL1
        for (pp = 0; pp < 16; pp = pp + 1)
        {
            if (RegEnable())
            {
                setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
                setSlaveMode();
                printf("POOL1 config start! %d/16	 \n", pp + 1);
                setPool(1, 0, 0, 2, 2, 6, 0, 24, 0, 0, 0, hrKmToPhys(src_conv1_src_out) + pp * 24 * 24 * 6 * 2, 0, 0, 0, 0, 0, 0, 0, hrKmToPhys(src_pool_out1) + pp * 12 * 12 * 6 * 2, resptype, 0, 0); //3020æ± åä»æ¯æbatch1
            }

            printf("POOL1 config done! %d/16	\n", pp + 1);
            cal_resp_proc(resptype);
            printf("POOL1 done %d/16	 \n", pp + 1);
        }
        exit(-1);
        free(src_conv1_src_out);

        //CONV2
        s16 src_conv2_src_out[1024];

        if (RegEnable())
        {
            setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
            setSlaveMode();
            printf("CONV2 config start! \n");
            //		setConv_small(12,12,8,8,5,5,16,6,1,0,16,3,0,0,0,13,1,0,0,0,0x3080000,0,0x2100000,0,0,0,0,0,0x3100000,resptype,0,0);
            setConv_small(12, 12, 8, 8, 5, 5, 16, 6, 1, 0, 16, 3, 0, 0, 0, 13, 1, 0, 0, 0, hrKmToPhys(src_pool_out1), 0, hrKmToPhys(src_conv2_wb), 0, 0, 0, 0, 0, hrKmToPhys(src_conv2_src_out), resptype, 0, 0);
        }

        printf("CONV2 config done! \n");
        cal_resp_proc(resptype);
        printf("CONV2 done \n");
        free(src_pool_out1);

        // POOL2
        s16 src_pool_out2[1024];
        for (pp = 0; pp < 16; pp = pp + 1)
        {
            if (RegEnable())
            {
                setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
                setSlaveMode();
                printf("POOL2 config start! %d/16	 \n", pp + 1);
                setPool(1, 0, 0, 2, 2, 16, 0, 8, 0, 0, 0, hrKmToPhys(src_conv2_src_out) + pp * 8 * 8 * 16 * 2, 0, 0, 0, 0, 0, 0, 0, hrKmToPhys(src_pool_out2) + pp * 4 * 4 * 16 * 2, resptype, 0, 0); //3020æ± åä»æ¯æbatch1
            }

            printf("POOL2 config done! %d/16	  \n", pp + 1);
            cal_resp_proc(resptype);
            printf("POOL2 done  %d/16	  \n", pp + 1);
        }
        free(src_conv2_src_out);
        //FC1
        s16 src_fc_out1[1024];

        if (RegEnable())
        {
            setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
            setSlaveMode();
            printf("FC1 config start! \n");
            setFC(256, 32, 16, 0, 15, 0, 1, 0, 0, 4, 0, hrKmToPhys(src_pool_out2), hrKmToPhys(src_fc1_wb), 0, hrKmToPhys(src_fc1_bias), hrKmToPhys(src_fc_out1), resptype, 0, 0);
        }
        printf("FC1 config done! \n");
        cal_resp_proc(resptype);
        printf("FC1 done \n");
        free(src_pool_out2);

        //FC2
        s16 src_fc_out2[1024];
        if (RegEnable())
        {
            setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
            setSlaveMode();
            printf("FC2 config start! \n");
            setFC(32, 16, 16, 0, 15, 0, 1, 0, 0, 4, 0, hrKmToPhys(src_fc_out1), hrKmToPhys(src_fc2_wb), 0, hrKmToPhys(src_fc2_bias), hrKmToPhys(src_fc_out2), resptype, 0, 0);
        }

        printf("FC2 config done! \n");
        cal_resp_proc(resptype);
        printf("FC2 done \n");
        free(src_fc_out1);
        //FC3
        if (RegEnable())
        {
            setDeviceParam(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0); //ä»æ¨¡å¼
            setSlaveMode();
            printf("FC3 config start! \n");
            setFC(16, 10, 16, 0, 14, 0, 1, 0, 0, 4, 0, hrKmToPhys(src_fc_out2), hrKmToPhys(src_fc3_wb), 0, hrKmToPhys(src_fc3_bias), hrKmToPhys(src_fc_out3) + tt * 16 * 2 * 16, resptype, 0, 0); //10-->aligned to 16
        }

        printf("FC3 config done! \n");
        cal_resp_proc(resptype);
        printf("FC3 done \n");
        free(src_fc_out2);

        printf("Softmax!\n");

        soft_max(hrKmToPhys(src_fc_out3) + tt * 16 * 2 * 16, hrKmToPhys(soft_max_out) + tt * 16 * 2, 16, 2, 16);
    }
    //åºå®æ¯è¾å32ä¸ªæµè¯éæ°æ®
    printf("Compare FC3 RES!\n");
    compare_rlt_offset(16 * 32, 2, hrKmToPhys(src_fc_out3), hrKmToPhys(src_fc3_gloden_res), 1); // compare FC3 results
    printf("Compare Conclusion RES!\n");
    compare_rlt_offset(1 * 32, 2, hrKmToPhys(soft_max_out), src_test_flag, 1); // compare FLAG results
    printf("END! \n");
}
