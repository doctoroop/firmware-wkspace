#ifndef STD_TYPES_H
#define STD_TYPES_H
#include <stdbool.h>
// note: in ARM 32 bit, int is 32 bits long
typedef int8_t           i8;
typedef int16_t          i16;
typedef int32_t          i32;
typedef int64_t          i64;
typedef uint8_t          u8;
typedef uint16_t         u16;
typedef uint32_t         u32;
typedef uint64_t         u64;


typedef i8               INT8;
typedef i16              INT16;
typedef i32              INT32;
typedef i64              INT64;
typedef u8               UINT8;
typedef u16              UINT16;
typedef u32              UINT32;
typedef u64              UINT64;
typedef INT16 INT16T, *INT16P, **INT16I; //T=thing; P=ptr; I=indirect
typedef INT32 INT32T, *INT32P, **INT32I;
typedef UINT16 UINT16T, *UINT16P, **UINT16I;
typedef UINT32 UINT32T, *UINT32P, **UINT32I;
typedef UINT32           ADDR;

typedef float            FLOAT32;
typedef double           FLOAT64;

#ifndef NULL
#define NULL  0
#endif

typedef bool             BOOLEAN;
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef u32 BOOL32;
typedef u16 BOOL16;
typedef u8  BOOL8;
#endif
