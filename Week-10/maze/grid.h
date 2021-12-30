/* The grid is a 2D array of entities. A forward reference to the entity type
avoids a dependency on the entity module. */
#include <stdbool.h>

// The grid type.
struct grid;
typedef struct grid grid;

// Forward reference to the entity type.
struct entity;
typedef struct entity entity;

// Define the direction type without including direction.h
typedef int direction;

// Create a grid object, with NULL entities.
grid *newGrid(int width, int height);

// Free up the grid object, but not the entities in it.
void freeGrid(grid *g);

// Get an entity out of the grid.
entity *getCell(grid *g, int x, int y);

// Put an entity into the grid.
void setCell(grid *g, int x, int y, entity *e);

// Get an entity's neighbour in the given direction. It is assumed that there
// is a suitable border round the grid so the request is never out of bounds.
void *nextCell(grid *g, int x, int y, direction d);
