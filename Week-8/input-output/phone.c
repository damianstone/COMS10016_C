/* Read a number and name per line.  Note the limits on lengths.
There are two potential problems:
The name mustn't have any spaces in.
If the number starts with 0, it won't be preserved. */
#include <stdio.h>

int main() {
    const int max = 100;
    char line[max], name[50];
    int n;
    FILE *in = fopen("in.txt", "r");
    fgets(line, max, in);
    while (! feof(in)) {
        sscanf(line, "%d %s", &n, name); // to read numbers and names from a string, one per line. Scan strings
        printf("Number %d name %s\n", n, name);
        fgets(line, max, in);
    }
    fclose(in);
}

// min 24