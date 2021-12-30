#include <string.h>
#include <stdio.h>

// sprintf(s,"…",.…)

int main() {
    char str[25];
    sprintf(str, "%d squared is %d", 3, 3 * 3); // poner texto entremedio
    printf("%s\n", str); // prints “3 squared is 9”
    return 0;
}