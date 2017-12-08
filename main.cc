#include <iostream>

#include "configs.hh"
#include "Game.hh"

void clear() {
    #
}

int main() {
    Game g(MAP_WIDTH, MAP_HEIGHT, MAP);

    std::cout << g.drawGrid() << '\n';
    g.update();
    std::cout << g.drawGrid() << '\n';

    return 1;
}
