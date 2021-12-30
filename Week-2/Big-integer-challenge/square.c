/*
TASK => Write a program square.c containing a function square which squares an integer, 
and a function main which finds and prints the square of 42. Then extend the program 
so it can find and print the square of integers entered by the user.
*/

#include <stdio.h>

int square(int number) {
    return number * number;
};

int main() {
    int number;
    printf("Enter the first number: \n");
    scanf("%d", &number);
    printf("The squared is %d\n", square(number));
};