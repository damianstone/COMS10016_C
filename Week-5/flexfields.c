#include <stdio.h>

typedef struct word
{
    int count;
    char s[];
} word; // array must be last


word *newWord(char *s)
{
    int n = strlen(s) + 1;              // calculate memory needed for string
    word *w = malloc(sizeof(word) + n); // allocate memory needed
    strcpy(w->s, s);                    // initialise string
    w->count = 0;                       // initialise count
    return w;
}


int main()
{
    word *w = newWord("hello");
    printf("%s %d\n", w->s, w->count);
    free(w); // release memory
}