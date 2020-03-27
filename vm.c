/* Static VM instance:
 * Not a sound engineering choice
 * More flexibility when taking an explicit pointer
 * and passing it around.
 * Global variables are bad.
 */

#include "common.h"
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

    for(;;) {
        uint8_t instruction;
        switch(instruction = READ_BYTE())
        {
            case OP_RETURN: {
                                return INTERPRET_OK;
                            }
        }
    }

    #undef READ_BYTE
}

Interpret_Result interpret(Chunk *chunk)
{
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
