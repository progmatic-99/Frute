#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(void) {

    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 12);

    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "Test Chunk");
    freeChunk(&chunk);

    return 0;
}

