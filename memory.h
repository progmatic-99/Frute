/* Module to grow the array.
 * Figure out the new capacity.
 * Grow the array to that size.
 */

#ifndef frute_memory_h
#define frute_memory_h
#include <stddef.h>

#define GROW_CAPACITY(capacity) \
    ((capacity < 8) ? 8 : (capacity * 2))

#define GROW_ARRAY(previous, type, oldCount, count) \
    (type *)reallocate(previous, sizeof(type) * (oldCount), \
            sizeof(type) * (count))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

void *reallocate(void *previous, size_t oldSize, size_t newSize);

#endif
