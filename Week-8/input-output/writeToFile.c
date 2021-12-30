#include <stdio.h>
#include <stdlib.h>

// IMPORTANTE => a este codigo le faltan piezas, no funciona pero muentra los esencial

int main () {
    // to write characters to a text file
    FILE *out = fopen("out.text", "w");
    fputc(ch, out);
    fclose(out);

    // writing bytes to a binary file is the same but with "wb"
    FILE *out = fopen("out.text", "wb");
    fputc(ch, out);
    fclose(out);

    // write lines to a text file
    FILE *out = fopen("out.text", "w");
    fprintf(out, "hello \n");
    fprintf(out, "world! \n");
    fclose(out);
}