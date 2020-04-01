/* Static VM instance:
 * Not a sound engineering choice
 * More flexibility when taking an explicit pointer
 * and passing it around.
 * Global variables are bad.
 */
#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

void initVM()
{
}

void freeVM()
{
}

static Interpret_Result run()
{
#define READ_BYTE() (*vm.ip ++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define READ_CONSTANT_LONG() (vm.chunk->constants.values[READ_BYTE()])

    for(;;) {
#ifdef DEBUG_TRACE_EXECUTION
        // To convert ip back to relative offset from beginningof bytecode
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instruction;
        switch(instruction = READ_BYTE())
        {
            case OP_CONSTANT: {
                 Value constant = READ_CONSTANT();
                 printValue(constant);
                 printf("\n");
                 break;
            }

            case OP_CONSTANT_LONG: {
                 Value constant = READ_CONSTANT_LONG();
                 printValue(constant);
                 printf("\n");
                 break;
            }

            case OP_RETURN: {
                 return INTERPRET_OK;
            }
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
#undef READ_CONSTANT_LONG
}

Interpret_Result interpret(Chunk *chunk)
{
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
