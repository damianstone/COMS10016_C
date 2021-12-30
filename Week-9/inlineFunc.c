#include <stdio.h>

// compiler calls to a function replacing it with a copy of the function.
inline int square(int x) { 
    return x * x; 
}

int main() {
    int b = 5;
    // compiler try to copy the function in the execution time
    int c = square(b); // function may not be called, but inlined here

    return 0;
}