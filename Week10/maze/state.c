#include "base.h"
#include "state.h"
#include <stdlib.h>
#include <assert.h>

struct state {
    entity *player;
    int stars;
};

state *newState() {
    state *s = malloc(sizeof(state));
    *s = (struct state) { NULL, 0 };
    return s;
}

void freeState(state *s) {
    free(s);
}

void setPlayer(state *s, entity *p) {
    s->player = p;
}

entity *getPlayer(state *s) {
    return s->player;
}

void addStar(state *s) {
    s->stars++;
}

int getStars(state *s) {
    return s->stars;
}

void findStar(state *s) {
    --s->stars;
}

bool ended(state *s) {
    return s->stars == 0;
}

#ifdef stateTest

int main() {
    state *s = newState();
    addStar(s);
    assert(getStars(s) == 1);
    findStar(s);
    assert(getStars(s) == 0);
    freeState(s);
    succeed("State module OK");
    return 0;
}

#endif
