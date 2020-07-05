#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 11);

    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);
    writeChunk(&chunk, OP_RETURN, 1);
    writeChunk(&chunk, OP_CONSTANT_LONG, 2);
    writeChunk(&chunk, constant, 2);
    writeChunk(&chunk, constant, 2);
    writeChunk(&chunk, OP_RETURN, 2);

    //disassembleChunk(&chunk, "Test Chunk");
    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);

    return 0;
}

