
char c[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'j', 'k', 'l', 'm', 'n'};

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

// Find (first) index of c in a or return -1 if not found
// Early return for efficiency
int linearSearch2(char c, int n, char a[n])
{
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == c)
            return i; // early return
    }
    return result;
}

// Logical simpliciy
int linearSearch3(char c, int n, char a[n])
{
    int result = -1;
    int found = 0; // sentinel variable
    for (int i = 0; (i < n) && (!found); i++)
    {
        if (a[i] == c)
        {
            result = i;
            found = 1;
        }
    }
    return result;
};


#include <stdbool.h>
    // Find (first) index of c in a or return -1 if not found
    // Type bool
    int
    linearSearch4(char c, int n, char a[n])
{
    int result = -1;
    bool found = false;
    for (int i = 0; (i < n) && (!found); i++)
    {
        if (a[i] == c)
        {
            result = i;
            found = true;
        }
    }
    return result;
};