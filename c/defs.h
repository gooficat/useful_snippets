#pragma once

#define ptr *
#define addr &
#define deref *

#define not !
#define is ==
#define notis !=
#define and &&
#define or ||

#define OR |
#define NOT ~
#define AND &
#define XOR ^
#define SLEFT <<
#define SRIGHT >>

#define elif else if

typedef signed char i8;
typedef unsigned char u8;

#ifdef _WIN32
typedef signed short i16;
typedef signed long i32;
typedef signed long long i64;

typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
#else
typedef signed short i16;
typedef signed int i32;
typedef signed long i64;
typedef signed long long i128;

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned long long u128;
#endif

typedef char ptr str;

#define struc_t typedef struct
#define enu_m typedef enum
#define unio_n typedef union
