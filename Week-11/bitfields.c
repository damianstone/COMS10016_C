// Demo for using bit fields. (demos truncation, may produce compiler warning re truncation)
#include <stdio.h>
#include <string.h>

// limit the amount of bits spent on the fields of a struct.
typedef struct data {
  unsigned int a;
  unsigned int b; 
  unsigned int c;
  unsigned int d;
} data;

typedef struct bitfield {
  unsigned int a : 2; // limit this unsigned int to contain only 2 bits
  unsigned int b : 2; // limit this unsigned int to contain only 2 bits 
  unsigned int c : 14;// limit this unsigned int to contain only 14 bits
  unsigned int d : 14;// limit this unsigned int to contain only 14 bits
} bitfield; // consider that memory may be padded for structure, i.e. to multiples of 4

int main() {
  data x = { 3, 4, 16383, 16384}; // can hold all data
  bitfield y = { 3, 4, 16383, 16384}; // overflow for 4 (more than 2bits) and 16384 (more than 14bits)
  printf("data x size = %d\n", (int)sizeof(x)); // return 
  printf("bitfield y size = %d\n", (int)sizeof(y));
  printf("data x: .a=%d, .b=%d, .c=%d, .d=%d\n", x.a, x.b, x.c, x.d);
  printf("bitfield y: .a=%d, .b=%d, .c=%d, .d=%d\n", y.a, y.b, y.c, y.d); //truncation for b and d
  return 0;
}