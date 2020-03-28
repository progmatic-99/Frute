/* Static VM instance:
 * Not a sound engineering choice
 * More flexibility when taking an explicit pointer
 * and passing it around.
 * Global variables are bad.
 */
#include <stdio.h>

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
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for(;;) {
        uint8_t instruction;
        switch(instruction = READ_BYTE())
        {
            case OP_CONSTANT: {
                 Value constant = READ_CONSTANT();
                 printValue(constant);
                 printf("\n");
                 break;
            }

            /*case OP_CONSTANT_LONG: {
                 Value constant1 = READ_CONSTANT();

                 printValue(constant1);
                 printf("\n");
            }*/

            case OP_RETURN: {
                 return INTERPRET_OK;
            }
        }
    }

    #undef READ_BYTE
    #undef READ_CONSTANT
}

Interpret_Result interpret(Chunk *chunk)
{
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
