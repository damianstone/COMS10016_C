// Demo for using signal processing.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

void customFunction(int signalValue) { // handler function
  printf("Signal value %d received. End program? (0 = no, 1 = yes):\n", signalValue);
  int finito;
  scanf("%d",&finito);
  if (finito == 1) exit(0); //exit the program
  else signal(SIGINT, customFunction); // set handler function for next time
  // function ends, so go back to procedure where signal interruption happened
}

int main() {
  signal(SIGINT, customFunction); // associate handler function to signal
  bool quit = false;
  while (!quit) {
    printf("\nHello from the loop.\n");
    
    // program will be interrupted and the customFunction will be called
    raise(SIGINT); // simulate signal (could be raised from outside program)
  }
  return 0;
}