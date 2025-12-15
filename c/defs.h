#pragma once

#define ptr *
#define addr &
#define deref *


#ifndef __cplusplus
#define not !
#define and &&
#define or ||
#endif
#define is ==
#define notis !=

#define OR |
#define NOT ~
#define AND &
#define XOR ^
#define SLEFT <<
#define SRIGHT >>

#define elif else if

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char ptr str;

#define struc_t typedef struct
#define enu_m typedef enum
#define unio_n typedef union
