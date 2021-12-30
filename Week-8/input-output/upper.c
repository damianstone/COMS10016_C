/* Echo everything typed in upper case.  Use CTRL/D (or CTRL/C) to end */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    // read input from the standard input
    char ch = getchar();
    while (! feof(stdin)) {
        printf("%c", toupper(ch));
        ch = getchar();
    }
}