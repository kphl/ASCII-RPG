#include <sstream>

#include "Game.hh"

Game::Game(unsigned int width, unsigned int height, std::vector<std::string>& map)
    : mGrid(width, height, map)
{ }

Game::~Game(){
}

void Game::update() {

    // update
    Individu* individu = mGrid.getIndividu();

    // 1 = Individu
    individu->move(mGrid.getObjectif()->pos());

    // 2 = Monstre
    for (Monstre* m : mGrid.getMonstres()) {
        m->move(individu->pos());
    }
}

std::string const Game::drawGrid() const {
    std::stringstream s;

    for (unsigned int i(0);i<mGrid.getHeight();++i) {
        for (unsigned int j(0);j<mGrid.getWidth();++j) {
            if (mGrid(i, j)) {
                s << mGrid(i, j)->symbol();
            }
            else {
                s << ' ';
            }
        }
        s << '\n';
    }

    return s.str();
}

bool Game::isFinished() const {

    // check
    // 1 = Individu goes to Target
    // 2 = Monstre eats Individu

    return false;
}
