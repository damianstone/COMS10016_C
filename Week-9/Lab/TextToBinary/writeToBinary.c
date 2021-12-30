#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*

write a simple program that reads a text file and transform it in a binary format

clang writeToBinary.c -o binary
./binary ./input.txt ./output.bin

*/

int main(int n, char *args[]) {
    for (int i = 0; i < n; i++) {
        printf("Argument %d is %s\n", i, args[i]);
    }
    FILE *readFile = fopen(args[1], "r"); // open to read
    FILE *writeFile = fopen(args[2], "wb"); // open to write
    // convert text file to binary file
    char ch = fgetc(readFile); // first character
    while (! feof(readFile)) { // while not end of file
        // transform every character to binary
        unsigned char binaryChar = (unsigned char) ch;
        fwrite(&binaryChar, sizeof(unsigned char), 1, writeFile);
        ch = fgetc(readFile); // next character
    }

}