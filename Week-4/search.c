#include <stdio.h>

// Find (last) index of c in a or return -1 if not found
int linearSearch1(char c, int n, char a[n])
{
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == c)
            result = i;
    }
    return result;
}; 

