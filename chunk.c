#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk)
{
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
    initValueArray(&chunk->constants);
}

void freeChunk(Chunk *chunk)
{
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	initChunk(chunk);
    freeValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte)
{
	if(chunk->capacity < chunk->count + 1){
		int old_capacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(old_capacity);
		chunk->code = GROW_ARRAY(chunk->code, uint8_t,
				old_capacity, chunk->capacity);
	}

	chunk->code[chunk->count] = byte; // Storing the byte
	chunk->count ++; // Incrementing counter
}

