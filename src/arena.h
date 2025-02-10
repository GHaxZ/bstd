#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct {
  /* The memory currently allocated to this arena */
  void *memory;
  /* The memory amount in bytes currently allocated to this arena */
  size_t size;
  /* Memory offset for allocations */
  size_t offset;
} Arena;

/*
 * Initialize a new arena with the specified initial size
 */
Arena *ArenaInit(size_t size);

/*
 * Allocate the specifed amount of memory in bytes in an arena.
 * In case there isn't enough memory, the arenas size will increase.
 */
void *ArenaAlloc(Arena *arena, size_t size);

/*
 * Free the Arenas memory and the arena itself
 */
void ArenaFree(Arena *arena);

#endif // !ARENA_H
