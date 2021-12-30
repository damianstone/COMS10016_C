#include <stdio.h>
typedef struct item
{
    int x, y;
} item; // this combines the definition and aliasing of item

void move(item *i, int dx, int dy)
{
    i->x = i->x + dx; // i->x is a shorthand for (*i).x
    i->y = i->y + dy;
}

int main()
{
    item itemData = {137, 91};
    item *i = &itemData;
    move(i, 1, 15); // pass-by-reference
    printf("%d %d\n", i->x, i->y);
}