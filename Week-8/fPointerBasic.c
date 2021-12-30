#include <stdio.h>

// QSORT LIBRARY
// Thats what qsort library provide on stdlib
void qsort (
  void *base, // pointers to the first element of the array
  size_t nitems,// number of items of the array
  size_t size, // size of the data, if ita an array of ints it woulb be 4 bits
  int (*compar)(const void *, const void *) // compare two items 
); // esto ya lo tiene la libraria x lo que no hay que escribirlo


int main()
{   // HOW TO POINT FUNCTIONS
    int square(int x) { return x * x; }
    // a function int to int
    int (*f)(int); // function pointer f that can point to functions
    // that take an int argument and return an int
    f = square;                   // initialise the function pointer
    printf("7 x 7 = %d\n", f(7)); // call function via f
}

