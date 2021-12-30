/* Read a file and display the lines
Lines cannot be longer than max-1 characters (max-2 on Windows) */

#include <stdio.h>
#include <stdbool.h>

// read a text file one line at a time, assuming it has short lines
int main() {
    const int max = 100;
    FILE *in = fopen("in.txt", "r"); // open in read mode 
    char line[max];
    fgets(line, max, in);
    while (! feof(in)) {
        printf("Line: %s", line);
        fgets(line, max, in);
    }
    fclose(in);
}