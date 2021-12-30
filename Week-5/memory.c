#include <stdlib.h>

int reallocation()
{
    int capacity = 4;
    char *s = malloc(capacity);
    capacity = capacity * 3 / 2; // increased by 50%
    s = realloc(s, capacity);
    free(s);
}

int main()
{
    // basic memory
    int N;
    int *ip = malloc(N * sizeof(int)); // HEAP => if i need more memory
    int iArr[N];                       // STACK => use for less memory

    // using mallo
    // the return type of mallo is VOID
    char *s = malloc(4); // like char s[4] but persistent
    strcpy(s, "cat");    // remember de +1 character that is not visible
    printf("%s\n", s);
    free(s); // releasing memory, string disappears here

    // Two was to acces the location of an array (char)
    printf("%s\n", s[2]);     // = a
    printf("%s\n", *(s + 2)); // = a

    return 0;
};