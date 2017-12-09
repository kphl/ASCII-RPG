#include <iostream>

#include "configs.hh"
#include "Game.hh"

void clear() {
    std::system("clear");
}

int main() {
    Game g(MAP_WIDTH, MAP_HEIGHT, MAP);

    // draw The initial grid
    std::cout << g.drawGrid() << std::endl;

    while (!g.isFinished()) {
        g.update();
        std::cout << g.drawGrid() << std::endl;
    }

    std::cout << "The game was won by : " << g.getWinnerTag() << std::endl;

    return 1;
}
