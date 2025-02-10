#include "arena.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Arena *arena = ArenaInit(1024);

  char *alloc = ArenaAlloc(arena, 128);

  printf("Please enter something: ");
  char *input = fgets(alloc, 128, stdin);
  printf("You entered: %s", input);

  ArenaFree(arena);

  return 0;
}
