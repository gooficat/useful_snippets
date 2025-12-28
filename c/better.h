#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


#define CLASS(name)                                                                                \
    typedef struct name name;                                                                      \
    struct name

#define ENUM(name, ...) typedef enum name __VA_ARGS__ name

#define VECTOR_TYPE(type)                                                                          \
    CLASS(vector_##type)                                                                           \
    {                                                                                              \
        type* data;                                                                                \
        size_t size;                                                                               \
        size_t capacity;                                                                           \
    }

#define MAKE_VECTOR(type) (vector_##type){.data = malloc(sizeof(type)), .size = 0, .capacity = 1}

#define PUSH(vec, val)                                                                             \
    {                                                                                              \
        if (++(vec).size > (vec).capacity)                                                         \
        {                                                                                          \
            (vec).capacity *= 2;                                                                   \
            (vec).data = realloc((vec).data, (vec).capacity * sizeof((vec).data[0]));              \
        }                                                                                          \
        (vec).data[(vec).size - 1] = val;                                                          \
    }
#define at(i) data[i]
#define POP(vec)                                                                                   \
    {                                                                                              \
        --(vec).size;                                                                              \
        if ((vec).capacity / 2 > (vec).size)                                                       \
        {                                                                                          \
            (vec).capacity /= 2;                                                                   \
            (vec).data = realloc((vec).data, (vec).capacity * sizeof((vec).data[0]));              \
        }                                                                                          \
    }

#define NEW(type, ...)                                                                             \
    ({                                                                                             \
        type* placeholder = malloc(sizeof(type));                                                  \
        *placeholder = (type)__VA_ARGS__;                                                          \
        placeholder;                                                                               \
    });

typedef char* STRING;

#define copy_str(s)                                                                                \
    ({                                                                                             \
        size_t l = strlen(s) + 1;                                                                  \
        STRING v = malloc(l);                                                                      \
        strcpy_s(v, l, s);                                                                         \
        v;                                                                                         \
    })

#define ull_from_str(s)                                                                            \
    strtoull(s, ({                                                                                 \
                 STRING t = (s) + strlen(s) - 1;                                                   \
                 &t;                                                                               \
             }),                                                                                   \
             10)

#define ptr *
#define addr &
#define deref *

#ifndef __cplusplus
#define and &&
#define or ||
#define not !
#define is ==
#endif

#define notis !=

#define OR |
#define NOT ~
#define AND &
#define XOR ^
#define SLEFT <<
#define SRIGHT >>

#define elif else if

extern const char FMODE_RT[];
extern const char FMODE_RB[];
extern const char FMODE_WT[];
extern const char FMODE_WB[];

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
