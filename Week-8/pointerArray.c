#include <stdio.h>

int main(int n, char *args[]) {
  char s[] = "BRexit"; // array initialised with string constant
  char *t = "BRexit"; // pointer to a string constant

  // note t[1] = 'r'; segfault here since it points into a constant
  t = s; // make t point to (non-constant) string
  t[1] = 'r'; // now this is allowed since t points to non-constant
  printf("%c %c %c\n", s[1], t[1], *(t+1));

  int i = 3, *p = &i, **q = &p; // three levels of indirection
  printf("%d %d %d\n", i, *p, **q); // all they have the same value because they are only pointers

  int *w[] = {p, &i, *q}; // array of pointers to int
  printf("%p %p %p\n", (void*) w[0],(void*) w[1],(void*) w[2]); // pointing to the same momery adress (3) 

  int y[] = {1, 2, 3}; // array of ints
  int (*x)[] = &y; // pointer to array of ints 
  printf("%d %d %d\n", (*x)[0], (*x)[1], (*x)[2]); // same results of Y

  int *(*z)[] = &w; // pointer to array of pointers to int
  printf("%p %d\n",(void*) (*z)[0], *(*z)[0]);

  int **r[] = {q, q, q}; // array of pointers to int pointers
  printf("%d\n", *(*(r[0])));

  int (*a[])[] = {x, x}; // array of pointers to arrays of ints
  printf("%d %d\n", (*a[0])[0], (*a[0])[1]);

  return 0;
}