#include <stdio.h>

void op(const int *x,       // int value *x is read only in function
int *const y) {             // address of pointer y is fixed in function
                            // *x = 7 is illegal, value cannot be updated
                            // y = x is illegal, y cannot be updated

}