// in here i have to declare all of my functions 
// But what happen if I don't want to export a function and I want to make it local.

#include <stdio.h>

// STATIC FUNCTIONS
// with static I make it local
// they cannot be used in any other modulen.
// not linked
static void swap(int array[], int i, int j);

// STATIC VARIABLES
// se inicializa una sola vez y se borra cuando el programa se termina
int f() {
    int b = 5;
    b++;
    return b;
} // always return 6

int g() {
    static int c = 5; // run only once
    c++;
    return c;
} // first return 6, called again 7, 8, ...


// sort will be exported 
void sort(int n, int array[n]);

// EXTERN
// tambien se puede usar extern.
// to use variables that has been created in another modules
// is for to call 
// we dont use it in this module.
extern void sortExtern(int n, int array[n]);


// REGISTER 
// the compiler tries to allocate the variable to fast storage within the processor
register int chupalo;