#include <stdio.h>

typedef struct item
{
    int x, y;
} item; // define the structure

item *newItem(int x0, int y0)
{
    item *fresh = malloc(sizeof(item)); // allocate memory needed
    *fresh = (item){x0, y0};            // initialise fields, same as {.x=x0, .y=y0}
    return fresh;
}

void move(item *i, int dx, int dy)
{
    i->x = i->x + dx;
    i->y = i->y + dy;
}

int main()
{
    item *i = newItem(41, 37);
    move(i, 1, 15);
    printf("%d %d\n", i->x, i->y);
    free(i); // release memory
}