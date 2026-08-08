#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <raylib.h>

typedef enum
{
    SPECIES_PLANT,
    SPECIES_HERBIVORE,
    SPECIES_CARNIVORE,

} SpeciesKind;

typedef struct
{
    SpeciesKind species;

    Vector2 position;
    Vector2 velocity;

    float energy;
    float age;

} Organism;

#endif
