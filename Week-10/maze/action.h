/* This module defines the behaviours of the individual kinds of entity. */
#include "entity.h"

// These are the kinds of entity, as character codes from a level description.
enum kind { Blank='.', Wall='#', Star='*', Player='@' };
typedef char kind;

// Allow an entity to do some intialisation at the start of a level.
void wake(entity *entity);

// Carry out an entity's dying wishes.
void die(entity *entity);

// Get an active entity to take one step.
void act(entity *entity, direction d);
