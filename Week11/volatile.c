// Demo for using volatile keyword, may not work with all compiler versions
// but must compile with -O3 compiler flag in any case.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

bool *q; // storage of memory address to interfere with function's local variables

void customFunction(int signalValue) {
  *q = 1; // change the variable 'quit' from outside the function
  signal(SIGINT, customFunction);
}

int main() {
  signal(SIGINT, customFunction);
  // leaving out volatile below may cause the loop to run forever
  // since compiler may optimize the loop code to become 'while (true) {...}'
  // since 'quit' seems constant for this scope - but we know better...
  const bool volatile quit = false;
  // provide unchecked global access to address of 'quit'
  __asm__ (
      "nop\n"
      : "=a" (q)
      : "a"  (&quit)
  );
  while (!quit) {
    printf("\nHello from the loop.\n");
    raise(SIGINT);
  }
  return 0;
}