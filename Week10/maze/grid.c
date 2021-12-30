#include "grid.h"
#include "direction.h"
#include "base.h"
#include <stdlib.h>
#include <assert.h>

// The grid structure with an array of size 'width' of pointers to
// arrays of size 'height' of entity pointers
struct grid {
    int width, height;
    entity ***cells;
};

// Check if x and y are within bounds, and fail if not.
// This is a defensive check; it should never fail.
static void checkBounds(grid *g, int x, int y) {
    if (x < 0 || x >= g->width) fail("x out of bounds");
    if (y < 0 || y >= g->height) fail("y out of bounds");
}

grid *newGrid(int width, int height) {
    grid *g = malloc(sizeof(grid));
    g->width = width;
    g->height = height;
    g->cells = malloc(width * sizeof(void *));
    for (int x = 0; x < width; x++) {
        g->cells[x] = malloc(height * sizeof(void *));
    }
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            g->cells[x][y] = NULL;
        }
    }
    return g;
}

void freeGrid(grid *g) {
    for (int x = 0; x < g->width; x++) {
      for (int y = 0; y < g->height; y++)
        if (g->cells[x][y] != NULL) free(g->cells[x][y]);
      free(g->cells[x]);
    }
    free(g->cells);
    free(g);
}

entity *getCell(grid *g, int x, int y) {
    checkBounds(g, x, y);
    return g->cells[x][y];
}

void setCell(grid *g, int x, int y, entity *e) {
    checkBounds(g, x, y);
    g->cells[x][y] = e;
}

void *nextCell(grid *g, int x, int y, direction d) {
    return getCell(g, x + deltaX(d), y + deltaY(d));
}

#ifdef gridTest

// Define a local entity structure just for testing.
struct entity { char kind; };
typedef struct entity entity;

// Create an entity, just for testing.
static entity *newEntity(char k) {
    entity *e = malloc(sizeof(entity));
    e->kind = k;
    return e;
}

int main() {
    grid *g = newGrid(3, 3);
    entity *player = newEntity('@');
    entity *space = newEntity('.');
    setCell(g, 1, 1, player);
    setCell(g, 2, 1, space);
    assert(getCell(g, 1, 1) == player);
    entity *next = nextCell(g, 1, 1, EAST);
    assert(next == space);
    free(player);
    free(space);
    freeGrid(g);
    succeed("Grid module OK");
    return 0;
}

#endif
