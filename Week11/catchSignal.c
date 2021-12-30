// Demo for using signal processing to execute code before division by zero exits program.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

void customFunction(int signalValue) { // handler function
  printf("Code executed before program ends...\n");
}

int main() {
  signal(SIGFPE, customFunction); // associate handler function to signal
  int a = 0;
  a /= a; // division by zero, before ending program execute our customFunction
  return 0;
}