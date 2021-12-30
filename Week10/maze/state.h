/* The state object holds the variables representing the global game state. A
forward reference to entities avoids a dependency on the entity module. */
#include <stdbool.h>

struct state;
typedef struct state state;

// Forward reference to the entity type.
struct entity;
typedef struct entity entity;

// Create a new state object.
state *newState();

// Free up the state object, but not any entities in it.
void freeState(state *s);

// Set player entity.
void setPlayer(state *s, entity *p);

// Get player entity.
entity *getPlayer(state *s);

// Add to the number of stars in the level, during initialisation.
void addStar(state *s);

// Get the number of stars left to find.
int getStars(state *s);

// Find a star during play, reducing the number left to find.
void findStar(state *s);

// Check if the game has ended.
bool ended(state *s);
