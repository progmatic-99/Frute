/*
oldSize 	newSize 	            Operation
0 	        Non‑zero 	            Allocate new block.
Non‑zero 	0 	                    Free allocation.
Non‑zero 	Smaller than oldSize 	Shrink existing allocation.
Non‑zero 	Larger than oldSize 	Grow existing allocation.
*/

#include <stdlib.h>

#include "common.h"
#include "memory.h"

void *reallocate(void *previous, size_t oldSize, size_t newSize)
{
	if(newSize == 0){
		free(previous);
		return NULL;
	}

	return realloc(previous, newSize);
}
