#include <iostream>

#include "configs.hh"
#include "Game.hh"

void clear() {
    std::system("clear");
}

int main() {
    Game g(MAP_WIDTH, MAP_HEIGHT, MAP);

    std::cout << g.drawGrid() << std::endl;
    g.update();
    std::cout << g.drawGrid() << std::endl;
    g.update();
    std::cout << g.drawGrid() << std::endl;
    g.update();
    std::cout << g.drawGrid() << std::endl;
    g.update();
    std::cout << g.drawGrid() << std::endl;
    g.update();
    std::cout << g.drawGrid() << std::endl;
    return 1;
}
