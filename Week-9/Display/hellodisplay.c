#include "display.h"
#include <stdbool.h>

#define SCALE 16
typedef struct location {int x, y;} location;

// hand control to the display module
// ask to call back our function
bool functionToBeCalledRepeatedly(display *d, void *data, const char pressedKey) {
  location *l = (location*) data; // cast incoming data to be location*
  colour(d, 0xFF); // set current colour to black to clear old box
  block(d, 0, 0, getWidth(d), getHeight(d)); // draw screen as black
  // change position state based on pressedKey input
  switch (pressedKey) {
    case 79: l->x += SCALE; break; // go right
    case 80: l->x -= SCALE; break; // go left
    case 81: l->y += SCALE; break; // go down
    case 82: l->y -= SCALE; // go up
  }
  // limit position state to size of the display window (wrap-around)
  *l = (location) { 
      (l->x + getWidth(d)) % getWidth(d),
      (l->y + getHeight(d)) % getHeight(d)
    };

  colour(d, 0xFFFF); // set current colour to blue
  block(d, l->x, l->y, SCALE, SCALE); // draw a box at new position (l->x,l->y)
  show(d); // show drawn stuff on the screen

  return (pressedKey == 27); // stop once ESC is pressed
}

int main() {
    // create a new window with 320x240 pixels
    display *d = newDisplay("Hello window", 320, 240); 
    location *l = malloc(sizeof(location));
    *l = (location){0, 0};
    run(d, l, functionToBeCalledRepeatedly);
    free(l);
    freeDisplay(d); // free all display memory, close the display window

    return 0; 
}

// run => clang -std=c11 -Wall -pedantic display.o hellodisplay.c -lSDL2 -o hellodisplay 
// run => ./hellodisplay
