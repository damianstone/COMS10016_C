/* This is a maze game, written to illustrate very simple multi-module development,
and the use of display.h for graphics. Move around with the arrow keys and pick
up all the green emerald squares. The graphics acceleration is switched off so
that it runs on all emulators etc ... input and drawing may be slower than usual. */
#include "display.h"
#include "action.h"
#include "direction.h"
#include <stdbool.h>

#define BLOCKSIZE 32

// This is currently the only level.  It uses matrix (y,x) coordinates, so it
// looks the right way round.
static const int width = 9, height = 9;
static char *level[] = {
    "#########",
    "#...#..*#",
    "#.#.#.###",
    "#.#....*#",
    "#.####.##",
    "#@#*....#",
    "####.##.#",
    "#*...#*.#",
    "#########"
};

// Fill the grid from the level matrix and return the player entity
static entity *fill(grid *g, state *s) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            newEntity(s, g, x, y, level[y][x]);
            entity *e = getCell(g, x, y);
            wake(e);
        }
    }
    return getPlayer(s);
}

// Draw the grid on the display
static void draw(display *d, grid *g, int stars) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      entity *e = getCell(g, x, y);
      switch (getKind(e)) {
        case Blank: colour(d, 0xFF); break;
        case Wall: colour(d, 0x88FF); break;
        case Star: colour(d, 0xFF00FF); break;
        case Player: colour(d, 0xFFFFFFFF);
      }
      block(d, x * BLOCKSIZE, y * BLOCKSIZE, BLOCKSIZE, BLOCKSIZE);
    }
  }
  colour(d, 0xFF00FF);
  for (int x = 0; x < stars; x++) {
    block(d, x * BLOCKSIZE / 2 + BLOCKSIZE / 4, BLOCKSIZE / 4, BLOCKSIZE / 4, BLOCKSIZE / 4);
  }
}

// Draws, shows and moves the position of the player and updates the state according to pressedKey input.
// Function assumes that data is of type entity* and points to a valid and initialised structure.
// The function returns true, iff the navigation should come to an end.
bool navigate(display *d, void *data, const char pressedKey) {
  entity *player = (entity*) data;
  grid *g = getGrid(player);
  int stars = getStars(getState(player));
  if (stars != 0) {
    if (pressedKey == 80) act(player, West);
    else if (pressedKey == 79) act(player, East);
    else if (pressedKey == 82) act(player, North);
    else if (pressedKey == 81) act(player, South);
    draw(d, g, stars);
  } else {
    colour(d, 0xFFFFFFFF);
    block(d, 0, 0, BLOCKSIZE * width, BLOCKSIZE * height);
  }
  show(d);
  return (pressedKey == 27);
}

// Play the game.
int main() {
    grid *g = newGrid(width, height); // create a new grid to play on
    state *s = newState(); // create a new game state
    entity *player = fill(g, s); // create the level and return the player
    display *d = newDisplay("Emerald Maze", width * BLOCKSIZE, height * BLOCKSIZE); // create a display window
    run(d, (void*)player, navigate); // hand display, data and function (to be called repeatedly) to the run routine
    freeState(s); // free the state
    freeGrid(g); // free the grid
    freeDisplay(d); // close the graphics
}
