#include <stdlib.h>

// to group several values together into a single entity is via struct.

struct item
{
    int x, y;
};

typedef struct item Alias; // usually the same is used twice

Alias move(struct item i, int dx, int dy)
{
    i.x = i.x + dx;
    i.y = i.y + dy;
    return i;
}

int main()
{
    Alias i = {137, 91};
    i = move(i, 1, 15);
    printf("%d %d\n", i.x, i.y);
}