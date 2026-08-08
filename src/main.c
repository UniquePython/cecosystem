#include <raylib.h>

#include "organism.h"
#include "world.h"

#define WIDTH 900
#define HEIGHT 600

#define FPS 120

#define INITIAL_ORGANISMS 30

#define ORGANISM_RADIUS 5.0f

Vector2 ToScreenCoords(const Vector2 *position)
{
    return (Vector2){
        .x = position->x * ((float)WIDTH / WORLD_WIDTH),
        .y = position->y * ((float)HEIGHT / WORLD_HEIGHT),
    };
}

Color ColorFor(SpeciesKind species)
{
    switch (species)
    {
    case SPECIES_PLANT:
        return GREEN;
    case SPECIES_HERBIVORE:
        return SKYBLUE;
    case SPECIES_CARNIVORE:
        return RED;
    default:
        return GRAY;
    }
}

Organism NewRandomOrganism(void)
{
    Organism organism = {0};

    organism.species = (SpeciesKind)GetRandomValue(0, 2);

    organism.position.x = (float)GetRandomValue(0, WORLD_WIDTH);
    organism.position.y = (float)GetRandomValue(0, WORLD_HEIGHT);

    organism.velocity.x = (float)GetRandomValue(-5, 5);
    organism.velocity.y = (float)GetRandomValue(-5, 5);

    organism.energy = 0.0f;
    organism.age = 0.0f;

    return organism;
}

bool InitOrganisms(World *world)
{
    for (size_t idx = 0; idx < INITIAL_ORGANISMS; idx++)
        if (!WorldAddOrganism(world, NewRandomOrganism()))
            return false;

    return true;
}

void DrawOrganisms(const World *world)
{
    for (size_t idx = 0; idx < world->count; idx++)
    {
        const Organism *organism = &world->organisms[idx];
        DrawCircleV(ToScreenCoords(&organism->position), ORGANISM_RADIUS, ColorFor(organism->species));
    }
}

int main(void)
{
    SetRandomSeed((unsigned int)GetTime());

    World world = {0};
    if (!WorldInit(&world, INITIAL_ORGANISMS))
        return 1;

    if (!InitOrganisms(&world))
        return 1;

    InitWindow(WIDTH, HEIGHT, "cecosystem");
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        WorldUpdate(&world, GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        DrawOrganisms(&world);
        EndDrawing();
    }

    CloseWindow();
    WorldFree(&world);
    return 0;
}
