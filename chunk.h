/* Module to define code representation.
 * "Chunk" refers to blobs of bytecodes.
 */

#ifndef Frute_chunk_h
#define Frute_chunk_h

#include "common.h"
#include "value.h"

/* One byte operation code
 * Tells what operation we are
 * dealing with: Add, Subtract
 */
typedef enum{
    OP_CONSTANT, // For operands(1 byte)
    OP_RETURN, // Return from current function
    OP_CONSTANT_LONG, // For operands(3 bytes)
}Opcode;

typedef struct{
    int count; // No. of allocated entries in use
    int capacity; // No. of elements in the array we have allocated
    uint8_t *code; // Array of bytes
    int *lines; // For line number
    ValueArray constants;
}Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);
void writeConstant(Chunk *chunk, Value value, int line);

#endif
