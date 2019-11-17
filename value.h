// Representing Values

#ifndef Frute_value_h
#define Frute_value_h

#include "common.h"

typedef double Value;

typedef struct {
    int count;
    int capacity;
    Value *values;
}ValueArray;

#endif

