#ifndef WORLD_H_
#define WORLD_H_

#include "organism.h"

#include <stddef.h>
#include <stdbool.h>

#define WORLD_WIDTH 600.0f
#define WORLD_HEIGHT 400.0f

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
void WorldUpdate(World *world, float dt);

#endif
