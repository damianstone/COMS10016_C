#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// validates if the type number is within the capacity that a char can store,
// then it calls the charToBinary() function and prints the result.
void charToBinary(char c, char result[]) {
  char mask = 0x1;
  int cBytes = sizeof(c) * 8;
  int i;

  for (i = 0; i < cBytes; i++) {
    result[cBytes-1-i] = (c >> i) & mask;
    result[cBytes-1-i] += '0';
  }
  result[cBytes] = 0;
}

// visualises each bit by occupying a mask and traversing each bit through a for loop.
bool visualiseChar(char* n) {
  int charNumber;
  sscanf(n, "%d", &charNumber);
  if( charNumber > CHAR_MAX || charNumber < CHAR_MIN) {
    printf("Input error.\n");
    return false;
  }
  char result[9];
  charToBinary((char)charNumber, result);
  printf("%s\n", result);
  return true;
}

int main(int n, char *argv[]) {
    if (n < 2) {
        printf("Input error.\n");
        return -1;
    }
    if (strcmp(argv[1], "char") == 0) visualiseChar(argv[2]);
    return 0;
}