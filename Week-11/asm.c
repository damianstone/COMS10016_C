#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// insert assembly code in c

int main() {
  int input1 = 100;
  int input2 = 100;
  int output;

  __asm__ (
      "addl %%ebx, %%eax"
      : "=a" (output)
      : "a"  (input1), "b" (input2)
  );
  printf("Output=%d\n",output); // return 200
  return 0;
}