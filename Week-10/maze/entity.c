#include "entity.h"
#include "base.h"
#include <stdlib.h>
#include <assert.h>

// Give an entity direct access to the grid and game state, so that it
// can act autonomously.
struct entity {
    kind k;
    int x, y; 
    state *s;
    grid *g;
};

entity *newEntity(state *s, grid *g, int x, int y, kind k) {
    entity *e = malloc(sizeof(entity));
    *e = (entity) { k, x, y, s, g };
    setCell(g, x, y, e);
    return e;
}

void freeEntity(entity *e) {
    free(e);
}

kind getKind(entity *e) {
    return e->k;
}

state *getState(entity *e) {
    return e->s;
}

grid *getGrid(entity *e) {
    return e->g;
}

entity *getNext(entity *e, direction d) {
    return nextCell(e->g, e->x, e->y, d);
}

// Move an entity by swapping places with a given target entity.
void move(entity *e, entity *target) {
    grid *g = e->g;
    int x = e->x;
    int y = e->y;
    e->x = target->x;
    e->y = target->y;
    target->x = x;
    target->y = y;
    setCell(g, target->x, target->y, target);
    setCell(g, e->x, e->y, e);
}

void mutate(entity *e, kind newKind) {
    e->k = newKind;
}

#ifdef entityTest

// Create a test grid, 3 x 3 with player in the middle.
static grid *setup() {
    state *s = newState();
    grid *g = newGrid(3, 3);
    kind *level[] = { "...", ".@.", "..." };
    for (int x=0; x<3; x++) {
        for (int y=0; y<3; y++) {
            newEntity(s, g, x, y, level[y][x]);
        }
    }
    return g;
}

static void testMove() {
    grid *g = setup();
    entity *player = getCell(g, 1, 1);
    assert(getKind(player) == '@');
    entity *space = getCell(g, 2, 1);
    assert(getKind(space) == '.');
    move(player, space);
    assert(getCell(g, 1, 1) == space);
    assert(getCell(g, 2, 1) == player);
}

int main() {
    testMove();
    succeed("Entity module OK");
    return 0;
}

#endif
