#ifndef WORLD_H_
#define WORLD_H_

#include "organism.h"

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    Organism *organisms;
    size_t count;
    size_t capacity;

} World;

bool WorldInit(World *world, size_t initialCapacity);
void WorldFree(World *world);
bool WorldAddOrganism(World *world, Organism organism);
bool WorldRemoveOrganism(World *world, size_t index);

#endif
