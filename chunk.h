/* Module to define code representation.
 * "Chunk" refers to blobs of bytecodes.
 */

#ifndef frute_chunk_h
#define frute_chunk_h

#include "common.h"
#include "value.h"

/* One byte operation code
 * Tells what operation we are
 * dealing with: Add, Subtract
 */
typedef enum{
	OP_RETURN, // Return from current function
}Opcode;

typedef struct{
	int count; // No. of allocated entries in use
	int capacity; // No. of elements in the array we have allocated
	uint8_t *code; // Array of bytes
    ValueArray constants;
}Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
int addConstant(Chunk *chunk, Value value);

#endif
