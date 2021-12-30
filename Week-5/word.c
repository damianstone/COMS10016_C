#include <stdio.h>

typedef struct word
{
    char s[30];
    int count;
} word; // declare as well an alias 

int main() {
    printf("Struct word is %d bytes\n", (int)sizeof(word));
    return 0;
}