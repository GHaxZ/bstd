#include "arena.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// Round up to the next multiple of the systems guaranteed memory alignment
static size_t alignUp(size_t n) {
  return (n + (sizeof(max_align_t) - 1)) & ~(sizeof(max_align_t) - 1);
}

Arena *ArenaInit(size_t size) {
  size = alignUp(size);

  void *buffer = malloc(size);
  if (buffer == NULL) {
    return NULL;
  }

  Arena *arena = malloc(sizeof(Arena));
  if (!arena) {
    free(buffer);
    return NULL;
  }

  arena->memory = buffer;
  arena->offset = 0;
  arena->size = size;

  return arena;
}

void *ArenaAlloc(Arena *arena, size_t size) {
  size_t aligned_offset = alignUp(arena->offset);

  if (aligned_offset + size > arena->size) {
    size_t new_size = arena->size;

    while (aligned_offset + size > new_size) {
      if (new_size > SIZE_MAX / 2)
        return NULL;

      new_size *= 2;
    }

    void *new_buffer = realloc(arena->memory, new_size);

    if (!new_buffer) {
      return NULL;
    }

    arena->memory = new_buffer;
    arena->size = new_size;
  }

  void *ptr = (char *)arena->memory + aligned_offset;
  arena->offset = aligned_offset + size;

  return ptr;
}

void ArenaFree(Arena *arena) {
  free(arena->memory);
  free(arena);
}
