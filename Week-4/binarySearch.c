#include <stdio.h>
#include <stdbool.h>

// Find index of c in sorted a or return -1 if not found
int binarySearch(char c, int n, char a[n])
{
    int start = 0, end = n, mid;
    bool found = false;
    while ((!found) && (end > start))
    {
        mid = start + (end - start) / 2;
        if (c == a[mid])
            found = true;
        else if (c < a[mid])
            end = mid;
        else
            start = mid + 1;
    }
    if (!found)
        mid = -1;
    return mid;
};

