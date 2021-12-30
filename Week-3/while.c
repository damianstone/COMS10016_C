// as long as the expression is true the block is executed again and again

/* Print a countdown in 1s
intervals. */

#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <stdio.h>

int main() {
  int t = 10;
  while (t > 0) {
    sleep(1); // wait 1 second
    printf("%d\n", t);
    t--;
  }
  return 0;
};