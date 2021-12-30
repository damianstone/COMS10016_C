#include "action.h"
#include "base.h"
#include <assert.h>

void wake(entity *e) {
    state *s = getState(e);
    kind k = getKind(e);
    if (k == Player) setPlayer(s, e);
    else if (k == Star) addStar(s);
}

void die(entity *e) {
    state *s = getState(e);
    kind k = getKind(e);
    if (k == Star) findStar(s);
    mutate(e, Blank);
}

void act(entity *e, direction d) {
    kind k = getKind(e);
    if (k == Player) {
        entity *target = getNext(e, d);
        kind tk = getKind(target);
        if (tk == Star) die(target);
        if (tk == Blank || tk == Star) move(e, target);
    }
}

#ifdef actionTest

// Create a test grid, 3 x 3 with a player, a wall, and a star.
static grid *setup() {
    state *s = newState();
    grid *g = newGrid(3, 3);
    kind *level[] = { "...", "#@*", "..." };
    for (int x=0; x<3; x++) {
        for (int y=0; y<3; y++) {
            newEntity(s, g, x, y, level[y][x]);
        }
    }
    return g;
}

// Wake up all the entities, and check the game state.
static void testWake(grid *g) {
    entity *player = getCell(g, 1, 1);
    for (int x=0; x<3; x++) {
        for (int y=0; y<3; y++) {
            entity *e = getCell(g, x, y);
            wake(e);
        }
    }
    state *s = getState(player);
    assert(getPlayer(s) == player);
    int n = getStars(s);
    assert(n == 1);
}

int main() {
    grid *g = setup();
    testWake(g);
    succeed("Action module OK");
    return 0;
}

#endif
