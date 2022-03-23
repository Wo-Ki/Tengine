/* $Id: mydef.h,v 1.5 2006/03/07 09:38:26 tjl Exp $ */

#ifndef _mydef_h
#define _mydef_h

#ifdef __MIPS64__
#define _P2V(addr)       (0x9000000000000000 | ((u64)(addr))) /* physical address to virtual address */
#define _P2V_CACHE(addr) (0xb000000000000000 | ((u64)(addr))) /* physical address to virtual address */
#define _ADDRESS_TYPE    u64
#else
#define _P2V(addr)    (addr)
#define _ADDRESS_TYPE u32
#endif

#ifdef __X86__
#include "test_x86.h"
#elif __MIPS64__
#define READ64_REGISTER(x, y)            \
    do {                                 \
        y = *((volatile u64*)(_P2V(x))); \
    } while (0)
#define READ64_CACHE_REGISTER(x, y)            \
    do {                                       \
        y = *((volatile u64*)(_P2V_CACHE(x))); \
    } while (0)

#define WRITE64_REGISTER(x, y)           \
    do {                                 \
        *((volatile u64*)(_P2V(x))) = y; \
    } while (0)
#define WRITE64_CACHE_REGISTER(x, y)           \
    do {                                       \
        *((volatile u64*)(_P2V_CACHE(x))) = y; \
    } while (0)

#define READ_REGISTER(x, y)               \
    do {                                  \
        y = *((volatile uint*)(_P2V(x))); \
    } while (0)

#define WRITE_REGISTER(x, y)              \
    do {                                  \
        *((volatile uint*)(_P2V(x))) = y; \
    } while (0)

#define READ_CACHE_REGISTER(x, y)               \
    do {                                        \
        y = *((volatile uint*)(_P2V_CACHE(x))); \
    } while (0)

#define WRITE_CACHE_REGISTER(x, y)              \
    do {                                        \
        *((volatile uint*)(_P2V_CACHE(x))) = y; \
    } while (0)

#define READ8_REGISTER(x, y)               \
    do {                                   \
        y = *((volatile uchar*)(_P2V(x))); \
    } while (0)

#define WRITE8_REGISTER(x, y)              \
    do {                                   \
        *((volatile uchar*)(_P2V(x))) = y; \
    } while (0)

#define READ16_REGISTER(x, y)               \
    do {                                    \
        y = *((volatile ushort*)(_P2V(x))); \
    } while (0)

#define WRITE16_REGISTER(x, y)              \
    do {                                    \
        *((volatile ushort*)(_P2V(x))) = y; \
    } while (0)

#define nop()                        \
    do {                             \
        __asm__ __volatile__("nop"); \
    } while (0)

#define le32_to_cpu(x) x
#define cpu_to_le32(x) le32_to_cpu(x)
#define cpu_to_be16(x) \
    ((u16)((((u16)(x)&0x00FFU) << 8) | (((u16)(x)&0xFF00U) >> 8)))
#else /*OPENRISC*/
#define cpu_to_be16(x) (x)
#define le16_to_cpu(x) \
    ((u16)((((u16)(x)&0x00FFU) << 8) | (((u16)(x)&0xFF00U) >> 8)))

#define le32_to_cpu(x) \
    ((u32)((((u32)(x)&0x000000FFU) << 24) | (((u32)(x)&0x0000FF00U) << 8) | (((u32)(x)&0x00FF0000U) >> 8) | (((u32)(x)&0xFF000000U) >> 24)))

#define le64_to_cpu(x) \
    ((u64)((((u64)(x)&0x00000000000000FFULL) << 56) | (((u64)(x)&0x000000000000FF00ULL) << 40) | (((u64)(x)&0x0000000000FF0000ULL) << 24) | (((u64)(x)&0x00000000FF000000ULL) << 8) | (((u64)(x)&0x000000FF00000000ULL) >> 8) | (((u64)(x)&0x0000FF0000000000ULL) >> 24) | (((u64)(x)&0x00FF000000000000ULL) >> 40) | (((u64)(x)&0xFF00000000000000ULL) >> 56)))

#define cpu_to_le16(x) (le16_to_cpu(x))
#define cpu_to_le32(x) (le32_to_cpu(x))
#define cpu_to_le64(x) (le64_to_cpu(x))

#define READ_REGISTER(x, y)                           \
    do {                                              \
        volatile u32 z = *((volatile u32*)(_P2V(x))); \
        y = le32_to_cpu(z);                           \
    } while (0)

#define WRITE_REGISTER(x, y)                          \
    do {                                              \
        volatile u32 z = y;                           \
        *((volatile u32*)(_P2V(x))) = cpu_to_le32(z); \
    } while (0)

#define READ_CACHE_REGISTER(x, y)                           \
    do {                                                    \
        volatile u32 z = *((volatile u32*)(_P2V_CACHE(x))); \
        y = le32_to_cpu(z);                                 \
    } while (0)

#define WRITE_CACHE_REGISTER(x, y)                          \
    do {                                                    \
        volatile u32 z = y;                                 \
        *((volatile u32*)(_P2V_CACHE(x))) = cpu_to_le32(z); \
    } while (0)

#define READ8_REGISTER(x, y)            \
    do {                                \
        y = *((volatile u8*)(_P2V(x))); \
    } while (0)

#define WRITE8_REGISTER(x, y)               \
    do {                                    \
        *((volatile u8*)(_P2V(x))) = (u8)y; \
    } while (0)

#define READ16_REGISTER(x, y)                         \
    do {                                              \
        volatile u16 z = *((volatile u16*)(_P2V(x))); \
        y = le16_to_cpu(z);                           \
    } while (0)
#define WRITE16_REGISTER(x, y)                        \
    do {                                              \
        volatile u16 z = y;                           \
        *((volatile u16*)(_P2V(x))) = cpu_to_le16(z); \
    } while (0)

#define nop()             \
    do {                  \
        __asm__("l.nop"); \
    } while (0)
#endif /* MIPS64 */

#define phx_read_u64(where)          \
    ({                               \
        volatile u64 val;            \
        READ64_REGISTER(where, val); \
        val;                         \
    })
#define phx_read_cache_u64(where)          \
    ({                                     \
        volatile u64 val;                  \
        READ64_CACHE_REGISTER(where, val); \
        val;                               \
    })

#define phx_write_u64(where, val)       WRITE64_REGISTER(where, val)
#define phx_write_cache_u64(where, val) WRITE64_CACHE_REGISTER(where, val)

#define phx_read_cache_u32(where)        \
    ({                                   \
        volatile u32 val;                \
        READ_CACHE_REGISTER(where, val); \
        val;                             \
    })

#define phx_write_cache_u32(where, val) WRITE_CACHE_REGISTER(where, val)

#define phx_read_u32(where)        \
    ({                             \
        volatile u32 val;          \
        READ_REGISTER(where, val); \
        val;                       \
    })

#define phx_write_u32(where, val) WRITE_REGISTER(where, val)
#define phx_read_u8(where)          \
    ({                              \
        volatile u8 val;            \
        READ8_REGISTER(where, val); \
        val;                        \
    })

#define phx_write_u8(where, val) WRITE8_REGISTER(where, val)
#define phx_read_u16(where)          \
    ({                               \
        volatile u16 val;            \
        READ16_REGISTER(where, val); \
        val;                         \
    })
#define phx_write_u16(where, val) WRITE16_REGISTER(where, val)

#define phx_write_mask_bit(where, mask, val)                          \
    ({                                                                \
        volatile u32 tmp;                                             \
        tmp = ((phx_read_u32(where)) & (~(mask))) | ((val) & (mask)); \
        phx_write_u32(where, tmp);                                    \
    })

#define delay_cnt(n)                   \
    {                                  \
        volatile unsigned int i = (n); \
        while (i--)                    \
            ;                          \
    }

/*for openrisc only*/
#define TEST_IRQ

//#define TEST_CAN
//#define TEST_LPC
//#define TEST_MEM
//#define TEST_LDMA
//#define TEST_I2C
//#define TEST_NAND

//#define TEST_PCIE
//#define TEST_GMAC
//#define TEST_RAB

/* pcie */
#ifdef TEST_PCIE
#define TEST_PCIE_EP        1
#define TEST_SINGLE_MEM_RW  1
#define TEST_SINGLE_IO_RW   1
#define TEST_MESSAGE        1
#define TEST_DMA_MEM_RW_LIE 1
#define TEST_DMA_RW_LL_MODE 1

#define MAX_MEM_RW_TEST 20
#define MAX_IO_RW_TEST  20
#define DMA_TEST_LEN    16
#endif

/* rab */
#ifdef TEST_RAB
#define TEST_AXI_CSR_LOCK
#define TEST_MAINTENANCE_RW
#define TEST_NREAD_NWRITE
#define TEST_DOORBELL
#define TEST_DATA_MSG
#ifdef TEST_DATA_MSG
#define TEST_OB_DATA_MSG
#define TEST_IB_DATA_MSG
#endif
#define TEST_DATA_STREAM
#ifdef TEST_DATA_STREAM
#define TEST_OB_DATA_STREAM
#define TEST_IB_DATA_STREAM
#endif
#define TEST_RAB_DMA
#define TEST_50_BIT /* should defile EXT_ADDR_50BIT for BFM */
#endif

#endif
