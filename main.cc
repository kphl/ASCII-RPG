#include <iostream>

#include "configs.hh"
#include "Game.hh"

int main() {
    Game g(MAP_WIDTH, MAP_HEIGHT, MAP);

    std::cout << g.drawGrid() << '\n';

    return 1;
}
