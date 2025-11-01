#include "game.hpp"
#include "utils.hpp"

int main(void)
{
    Game game(1600, 900);
    game.load(getAssetPath("map.json"));
    game.run(60);
    return 0;
}