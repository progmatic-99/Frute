// Virtual Machine

#ifndef frute_vm_h
#define frute_vm_h


#include "chunk.h"

typedef struct{
    Chunk *chunk;
    uint8_t *ip; // Location of current instruction being executed
} VM;

/* To set exit code of the process.
 * VM runs a chunk and returns a value
 * from this chunk.
 */
typedef enum{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} Interpret_Result;

void initVM();
void freeVM();
Interpret_Result interpret(Chunk *chunk);

#endif
