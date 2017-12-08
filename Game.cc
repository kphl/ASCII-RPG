#include <sstream>
#include <vector>
#include <iostream>

#include "Game.hh"

Game::Game(unsigned int width, unsigned int height, std::vector<std::string>& map)
    : mGrid(width, height, map)
{ }

Game::~Game() {
}

void Game::update() {
    Individu* individu = mGrid.getIndividu();

    // Individu
    std::vector<Position> possiblePositions = individu->thinkMove(mGrid.getObjectif()->pos());
    
    std::cout << "current pos = " << individu->pos().X() << " " << individu->pos().Y() << std::endl;
    for (Position p : possiblePositions) {
        std::cout << "check p = " << p.X() << " " << p.Y() << std::endl;
        
        if (!mGrid(p.X(), p.Y())) {
            std::cout << "select" << std::endl;
            
            mGrid(p.X(), p.Y()) = std::move(mGrid(individu->pos().X(), individu->pos().Y()));
            individu->move(p);
            break;
        }
    }

    // Monstre
    /*for (Monstre* m : mGrid.getMonstres()) {
        vector<Position> possiblePositions = m->move(individu->pos());
        for (Position p : possiblePositions) {
            if (!mGrid(p.x, p.y)) {
                mGrid(m.Position().x, m.Position().y) = nullptr;
                m->move(p);
                mGrid(p.x, p.y) = m;
                break;
            }
        }
    }*/
}

std::string const Game::drawGrid() const {
    std::stringstream s;

    for (unsigned int y(0);y<mGrid.getHeight();++y) {
        for (unsigned int x(0);x<mGrid.getWidth();++x) {
            if (mGrid(x, y)) {
                s << mGrid(x, y)->symbol();
            }
            else {
                s << '.';
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
