// Demo for variable argument lists (a.k.a. ellipsis)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h> // important import this 

// use ... to implement any argument

// function with variable argument list
// function that sum all the arguments
int sum(int argNum, ...) { // use ... only at the end of parameter list
  int overall = 0;
  va_list arguments; // storage for arguments
  va_start(arguments, argNum); // initialise argument list with length i
  for (int j = 1; j <= argNum; j++) {
    overall += va_arg(arguments, int); // access next argument as int
  }
  va_end(arguments); // clean up argument list. Like free in malloc
  return overall;
}

int main() {
  printf("%d\n", sum(2,1,2)); // 1 + 2
  printf("%d\n", sum(3,2,3,4)); // 2 + 3 + 4
  return 0;
}