/* Print character codes from a text file */
#include <stdio.h>
#include <stdbool.h>

// check if the open is suceeful and it could open the file
FILE *fopenCheck(char *file, char *mode) {
    FILE *p = fopen(file, mode);
    if (p !=NULL) { // chekc if the check was opened
        return p;
    }
    fprintf(stderr, "Can't open %s: ", file); // print an standar error
    fflush(stderr);
    perror(""); // an alternative to fprintf()
    exit(1); 
}

// Reading characters from a file
int main() {

    FILE *in = fopenCheck("in.text", "r");

    // firs prameter, the name of the file and second the mode to acces (r for read)
    FILE *in = fopen("in.txt", "r"); // return the pointer to the file and it provide acces the content of the file
    char ch = fgetc(in); // first byte or character of the file
    while (! feof(in)) { // true when have reach the end of the file
        printf("%d\n", ch);
        ch = fgetc(in);
    }
    fclose(in); // close the file
} 
 
// i this way we can read and entire character file