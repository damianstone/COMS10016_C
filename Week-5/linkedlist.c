/* Demo for a stack library implemented via linked lists */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int FAILURE_CODE = 1; // exit code at program failure

// items to be stored in the stack, the payload
typedef int item;

// single cell in linked list chain
typedef struct cell {
  item x;
  struct cell *next;
} cell;

// the stack itself gives access to the first linked list item
typedef struct stack {
  cell *first;
} stack;

// exit the program with particular error message
void error(char *message) {
  fprintf(stderr, "List failure: %s\n", message);
  exit(FAILURE_CODE);
}

// create an empty stack
stack *newStack() {
  stack *s = malloc(sizeof(stack));
  s->first = NULL;
  return s;
}

// check if stack is empty
bool isEmpty(stack *s) {
  return (s->first == NULL); 
}

// put item n on top of the stack s
void push(stack *s, item n) {
  cell *c = malloc(sizeof(cell)); // create pointer to new cell in memory
  *c = (cell) {n, s->first}; // initialise an link cell in before current first items
  s->first = c; // make new cell the current first item
}

// get top element of stack, but do not remove it
item peek(stack *s) {
  if (s->first == NULL) error("peek on empty stack");
  return s->first->x; // return item of first cell
}

// get and remove top element of stack s
item pop(stack *s) {
  cell *c = s->first;
  if (c == NULL) error("pop on empty stack");
  s->first = c->next; // make second cell the first cell (remove top)
  item x = c->x; // buffer item to return it later
  free(c); // release memory of removed cells
  return x; // return rescued item
}

// free all memory occupied by stack 
void freeStack(stack *s) {
  cell *c = s->first; 
  while (c != NULL) { // stop if current cell pointer is NULL
    cell *next = c->next; // store pointer to next cell
    free(c); // only then free current cell
    c = next; // make next cell current cell
  }
  free(s); // only when all cells are freed free the stack itself
}
 
// check a stack is structured as expected
bool check(stack *s, int n, item target[n]) {
  bool ok = true;
  cell *c = s->first;
  for (int i = 0; i < n; i++) {
    if ((c->x) != (target[i])) ok = false; // element does not match
    c = c->next;
  }
  if (c != NULL) ok = false; // must point to NULL at end of stack
  return ok;
}

// test stack functionality
void test() {
    stack *s = newStack();
    //assert(check(s, 0, NULL));
    push(s, 41);
    assert(check(s, 1, (int[]) {41}));
    push(s, 43);
    assert(check(s, 2, (int[]) {43, 41}));
    assert(peek(s) == 43);
    assert(check(s, 2, (int[]) {43, 41}));
    assert(pop(s) == 43);
    assert(check(s, 1, (int[]) {41}));
    freeStack(s);
}

int main() {
  test();
  return 0;
}