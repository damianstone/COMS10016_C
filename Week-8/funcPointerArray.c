/* Demo for array of function pointers */
#include <stdio.h>

// The operation functions, to add, subtract, multiply, divide.
int add(int x, int y) { return x+y; }
int subtract(int x, int y) { return x-y; }
int multiply(int x, int y) { return x*y; }
int divide(int x, int y) { return x/y; }

// Assign to alias op the type of the operation functions.
typedef int op(int x, int y);

// The operators as an enumeration.
enum opcode { Plus, Minus, Times, Over };

// The array of function pointers, indexed by operator
// and initialised pointing to the operation functions.
op *ops[] = { add, subtract, multiply, divide }; // array of function pointers

// Usage Demo.
int main() {
    op *f = ops[Times]; // pick the multiply operation and assign it to function pointer f
    int n = f(6, 7); // execute multiply operation
    printf("Answer 6 x 7 = %d\n", n); // print result
}