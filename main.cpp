#include <SDL3/SDL.h>

#include <flecs.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SDL3_image/SDL_image.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SQLite::Database db("database.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    flecs::world ecs;

    return EXIT_SUCCESS;
}
