#include "arena.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Arena *arena = ArenaInit(8);

  char *alloc = ArenaAlloc(arena, 32);

  printf("Please enter something: ");
  char *input = fgets(alloc, 32, stdin);
  printf("You entered: %s", input);

  ArenaFree(arena);

  return 0;
}
