#ifndef GAME__HH
#define GAME__HH

#include <vector>
#include <string>

#include "Grid.hh"

class Game {
public:
    Game(unsigned int width, unsigned int height, std::vector<std::string>& map);
    ~Game();

    void update();
    std::string const drawGrid() const;

    bool isFinished() const;

private:
    Grid mGrid;
};

#endif
