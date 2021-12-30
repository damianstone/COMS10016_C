/* Directions allow entities to move around in the grid without using
absolute coordinates. Graphics coordinates are used, i.e. (x,y) with x
to the right and y down. Don't include this header in other headers,
just repeat the typedef. */

// There are eight directions, plus Here for the current position.
enum direction {
    Here, North, South, East, West, NorthEast, NorthWest, SouthEast, SouthWest
};
typedef int direction;

// Find the x offset corresponding to a given direction.
int deltaX(direction d);

// Find the y offset corresponding to a given direction.
int deltaY(direction d);
