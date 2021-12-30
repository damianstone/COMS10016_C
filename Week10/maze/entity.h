/* An entity is anything that can appear in the grid.  This module provides
generic operations that all entities can use. */
#include "grid.h"
#include "state.h"

struct entity;
typedef struct entity entity;

// Entities come in different kinds - a kind is defined as a char, for
// compatibility with text-based level descriptions. This forward reference
// avoids any dependency on the action module.
typedef char kind;

// Create a new entity and wire it up.
entity *newEntity(state *s, grid *g, int x, int y, kind k);

// Free up an entity.
void freeEntity(entity *e);

grid *getGrid(entity *e);

// Get the kind of an entity.
kind getKind(entity *e);

// Get the state object from an entity.
state *getState(entity *e);

// Get an entity's neighbour in the given direction. It is assumed that there
// is a suitable border round the grid so the request is never out of bounds.
entity *getNext(entity *entity, direction d);

// Move an entity by swapping places with a given target entity.
void move(entity *e, entity *target);

// Change the kind of an entity.
void mutate(entity *e, kind newKind);
