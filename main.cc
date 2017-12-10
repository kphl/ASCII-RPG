#include <iostream>
#include <thread>

#include "configs.hh"
#include "Game.hh"

void draw(Game const& g) {
#if REFRESH_TERM == TRUE
    std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME));
    std::system("clear");
    std::cout << g.drawGrid() << std::endl;
#endif
}

int main() {
    Game g(MAP_WIDTH, MAP_HEIGHT, MAP);

    // draw The initial grid
    draw(g);

    while (!g.isFinished()) {
        g.update();
        draw(g);
    }

    std::cout << "The game was won by : " << g.getWinnerTag() << std::endl;

    return 1;
}
