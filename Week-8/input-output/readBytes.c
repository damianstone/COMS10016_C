/* Print character codes from a text file */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    //read bytes from a binary file
    FILE *in = fopen("in.mp3", "rb"); // using "rb"
    unsigned char ch = fgetc(in); // using unsigned is cleanest 
    while (! feof(in)) {
        printf("%d\n", ch);
        ch = fgetc(in);
    }
    fclose(in); // important to close every file 
} 