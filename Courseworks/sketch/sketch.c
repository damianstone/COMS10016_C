// Basic program skeleton for a Sketch File (.sk) Viewer
#include "displayfull.h"
#include "sketch.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Allocate memory for a drawing state and initialise it
state *newState() {
  state *s = malloc(sizeof(state));
  *s = (state) {0, 0, 0, 0, LINE, 0, 0, 0};
  return s;
}

// Release all memory associated with the drawing state
void freeState(state *s) {
  free(s);
}

// helper function to get the mask for n bits
int getMask(int n) { 
  int mask = 0;
  for (int i = 0; i < n; i++) {
    mask |= 1 << i;
  }
  return mask;
}

// Extract an opcode from a byte (two most significant bits).
int getOpcode(byte b) {
  int opcode = b >> 6;
  return opcode;
}

// Extract an operand (-32..31) from the rightmost 6 bits of a byte.
int getOperand(byte b) {
  int mask = getMask(6);
  int operand = b & mask;
  if (b & (1 << 5)) { // check negative
    operand = b | ~mask;
  }
  return operand;
}

// helper function for tool command
void toolCommand(display *d, int operand, state *s) {
  if (operand == NONE) s->tool = NONE;
  else if (operand == LINE) s->tool = LINE;
  else if (operand == BLOCK) s->tool = BLOCK;
  else if (operand == COLOUR) colour(d, s->data);
  else if (operand == TARGETX) s->tx = s->data;
  else if (operand == TARGETY) s->ty = s->data;
  else if (operand == SHOW) show(d);
  else if (operand == PAUSE) pause(d, s->data);
  else if (operand == NEXTFRAME) s->end = true;
  s->data = 0; // set data = 0 after running any command tool
} 

// helper function for DY command
void dyCommand(display *d, int operand, state *s) {
  s->ty += operand;
  if (s->tool == LINE) {
    line(d, s->x, s->y, s->tx, s->ty);
  } else if (s->tool == BLOCK) {
    block(d,s->x,s->y,(s->tx) - (s->x),(s->ty) - (s->y));
  }
  s->x = s->tx;
  s->y = s->ty;
}

// Execute the next byte of the command sequence.
void obey(display *d, state *s, byte op) {
  int operand = getOperand(op);
  int command = getOpcode(op);
  switch (command) {
    case DX:
      s->tx += operand;
      break;
    case DY:
      dyCommand(d, operand, s);
      break;
    case TOOL:
      toolCommand(d, operand, s);
      break;
    case DATA:
      s->data = (s->data << 6) | (operand & getMask(6));
      break;
    default:
      break;
  }
}

// Draw a frame of the sketch file. For basic and intermediate sketch files
// this means drawing the full sketch whenever this function is called.
// For advanced sketch files this means drawing the current frame whenever
// this function is called.
bool processSketch(display *d, void *data, const char pressedKey) {
  if (data == NULL) return (pressedKey == 27);
  state *s = (state*) data;
  char *fileName = getName(d);
  FILE *fp = fopen(fileName, "rb");
  byte op = fgetc(fp); // get the next char
  if (s->start != 0) { // check specific location
    fseek(fp, s->start, SEEK_SET); // set start location
  }
  while (!feof(fp) && !s->end) {
    obey(d,s, op);
    op = fgetc(fp);
  }
  if (feof(fp)) {
    s->start = 0; // reset the state at the end of the file
  } else if (s->end) {
    s->start = ftell(fp);
  }
  obey(d, s, op);
  show(d);
  fclose(fp);
  *s = (state) {0, 0, 0, 0, LINE, s->start, 0, 0};
  return (pressedKey == 27);
}

// View a sketch file in a 200x200 pixel window given the filename
void view(char *filename) {
  display *d = newDisplay(filename, 200, 200);
  state *s = newState();
  run(d, s, processSketch); 
  freeState(s);
  freeDisplay(d);
}

// Include a main function only if we are not testing (make sketch),
// otherwise use the main function of the test.c file (make test).
#ifndef TESTING
int main(int n, char *args[n]) {
  if (n != 2) { // return usage hint if not exactly one argument
    printf("Use ./sketch file\n");
    exit(1);
  } else view(args[1]); // otherwise view sketch file in argument
  return 0;
}
#endif
