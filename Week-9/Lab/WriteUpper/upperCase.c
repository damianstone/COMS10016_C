#include <stdio.h>
#include <ctype.h>
/* 
 write a simple program that reads a text file and writes the 
 contents of it into another text file with all letters converted into upper case

 Dos argumentos en la linea de comando. el primero el archivo que se va leer
 el segundo el archivo que se va a escribir en mayusculas

 clang upperCase.c -o upper
 ./upper ./input.txt ./output.txt
*/

void readAndWrite(char *file, char *file2) {
    FILE *readFile = fopen(file, "r"); // open to read
    FILE *writeFile = fopen(file2, "w"); // open to write
    char ch = fgetc(readFile); // first character
    while (! feof(readFile)) { // while not end of file
        char upperChar = toupper(ch); // convert to upper case
        printf("%c\n", ch); 
        ch = fgetc(readFile); // next character
        fputc(upperChar, writeFile); // write to file
    }
    fclose(readFile);
    fclose(writeFile);
}

int main(int n, char *args[]) {
    for (int i = 0; i < n; i++) {
        printf("Argument %d is %s\n", i, args[i]);
    }
    readAndWrite(args[1], args[2]);
    return 0;
}
