/* Demo for using the qsort library function */
#include <stdio.h>
#include <stdlib.h>

// a function of type (int)(const void*, const void*)
// that returns neg, 0 or pos depending on which two
// int elements provided via pointers to them is larger
int compare(const void *p, const void *q) {
    const int *pi = p, *qi = q; //pointers to int - first step
    int x = *pi, y = *qi; // initialize two ints for the pointers
    if (x < y) return -1; // now we can do the comparison
    else if (x == y) return 0;
    else return 1; // 1 if the first one is the largest one
}

//Using the qsort function
int main() {
    int ns[] = { 8, 2, 6, 5, 9, 1, 7 }; // an array to sort
    int itemSize = sizeof(int); // initialize the size
    int length = sizeof(ns) / itemSize; // the number of entries
    // call qsort with the last argument being a function pointer
    qsort(ns, length, itemSize, compare); // not necesary to explicit the pointers
    for (int i = 0; i < length; i++) {
      printf("%d ", ns[i]);
    }
    printf("\n");
}