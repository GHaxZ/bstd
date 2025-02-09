#include <stddef.h>

typedef struct {
  void *buffer;
  size_t offset;
  size_t size;
} Arena;

Arena *ArenaInit(size_t size);

void *ArenaAlloc(Arena *arena, size_t size);

void ArenaFree(Arena *arena);
