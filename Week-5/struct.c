#include <stdlib.h>

// to group several values together into a single entity is via struct.

struct item
{
    int x, y;
};

struct item move(struct item i, int dx, int dy)
{
    i.x = i.x + dx;
    i.y = i.y + dy;
    return i;
}

int main()
{
    struct item i = {137, 91};
    i = move(i, 1, 15);
    printf("%d %d\n", i.x, i.y);
}