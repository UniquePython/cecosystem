#include "world.h"

#include <stdlib.h>

bool WorldInit(World *world, size_t initialCapacity)
{
    if (!world)
        return false;

    Organism *organisms = malloc(initialCapacity * sizeof(Organism));
    if (!organisms)
        return false;

    world->organisms = organisms;
    world->count = 0;
    world->capacity = initialCapacity;

    return true;
}

void WorldFree(World *world)
{
    free(world->organisms);
    world->organisms = NULL;
    world->count = 0;
    world->capacity = 0;
}

bool WorldAddOrganism(World *world, Organism organism)
{
    if (!world)
        return false;

    if (world->count == world->capacity)
    {
        size_t newCapacity = (world->capacity == 0) ? 4 : world->capacity * 2;
        Organism *resized = realloc(world->organisms, newCapacity * sizeof(Organism));
        if (!resized)
            return false;

        world->organisms = resized;
        world->capacity = newCapacity;
    }

    world->organisms[world->count] = organism;
    world->count++;

    return true;
}

bool WorldRemoveOrganism(World *world, size_t index)
{
    if (!world)
        return false;

    if (index >= world->count)
        return false;

    world->organisms[index] = world->organisms[world->count - 1];
    world->count--;

    return true;
}
