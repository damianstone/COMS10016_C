// Demo for using unions.
#include <stdio.h>
#include <string.h>

// store different elements and data types in the same memory
//Store info in one type 
typedef union data { // define the same 32bit of memory as 3 different data types
  int i;
  float f;
  char str[4]; 
} data;

int main() {
  data d;
  d.i = 16;
  d.f = 11.11;
  strcpy(d.str, "Hi!"); // overwrites d.i / d.f since IS the same memory
  printf("d.i = %d\n", d.i); // return 16
  printf("d.f = %f\n", d.f); // return 11.11
  printf("d.str = %s\n", d.str);
  return 0;
}