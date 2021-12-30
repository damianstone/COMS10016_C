#include "direction.h"
#include "base.h"
#include <stdbool.h>
#include <assert.h>

int deltaX(direction d) {
    switch (d) {
    case Here: case North: case South: return 0;
    case East: case NorthEast: case SouthEast: return 1;
    case West: case NorthWest: case SouthWest: return -1;
    default: fail("Unknown direction"); return 0;
    }
}

int deltaY(direction d) {
    switch (d) {
    case Here: case East: case West: return 0;
    case South: case SouthEast: case SouthWest: return 1;
    case North: case NorthEast: case NorthWest: return -1;
    default: fail("Unknown direction"); return 0;
    }
}

#ifdef directionTest

static bool check(int d, int dx, int dy) {
    return deltaX(d) == dx && deltaY(d) == dy;
}

int main() {
    assert(check(North, 0, -1));
    assert(check(East, 1, 0));
    assert(check(NorthEast, 1, -1));
    succeed("Direction module OK");
}

#endif
