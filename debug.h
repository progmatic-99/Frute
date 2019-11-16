// Disassembler

#ifndef frute_debug_h
#define frute_debug_h

#include "chunk.h"

// Disassembles all instructions in entire chunk
void disassembleChunk(Chunk *chunk, const char *name);

// Disassembles single instruction
int disassembleInstruction(Chunk *chunk, int offset);

#endif

