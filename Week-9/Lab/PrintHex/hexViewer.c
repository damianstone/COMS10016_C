#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
 write a program that takes a filename (of any type of file opened as a binary file), 
 reads bytes (as unsigned char) from it one at a time, and prints the bytes on the standard 
 output in hex, in the same format as the unix command "od -t x1 filename" 
 would (but leaving out the address in the first column). 
 You may want to write another tiny program to write binary files with known content, 
 which you can use to (manual) test your hex viewer.

 */


int main(int n, char *args[]) {
    for (int i = 0; i < n; i++) {
        printf("Argument %d is %s\n", i, args[i]);
    }
    FILE *readFile = fopen(args[1], "rb"); // open to read
    unsigned char ch = fgetc(readFile); // first character
    while (! feof(readFile)) { // while not end of file
        // prints the bytes on the standard output in hexadecimal format
        printf("%02x ", ch);
        ch = fgetc(readFile); // next character
    }
    fclose(readFile);

    return 0;
}

