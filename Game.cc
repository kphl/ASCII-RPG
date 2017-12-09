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
    Objectif* objectif = mGrid.getObjectif();

    // Individu
    std::vector<Position> possiblePositions = individu->thinkMove(objectif->pos());

    for (Position p : possiblePositions) {
        if (!mGrid(p.X(), p.Y()) || p == objectif->pos()) {
            mGrid(p.X(), p.Y()) = std::move(mGrid(individu->pos().X(), individu->pos().Y()));
            individu->move(p);
            break;
        }
    }

    // if the player hit the target, the game is finished
    if (isFinished()) {
        return;
    }

    // Monstre
    for (Monstre* m : mGrid.getMonstres()) {
        std::vector<Position> monsterPossiblePositions = m->thinkMove(individu->pos());
        for (Position p : monsterPossiblePositions) {
            if (!mGrid(p.X(), p.Y()) || p == individu->pos()) {
                mGrid(p.X(), p.Y()) = std::move(mGrid(m->pos().X(), m->pos().Y()));
                m->move(p);
                break;
            }
        }

        // If the current monster eat the player, the game is finished
        if (isFinished()) {
            return;
        }
    }
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
    return mGrid.getObjectif() == nullptr
        || mGrid.getIndividu() == nullptr;
}

std::string Game::getWinnerTag() const {
    if (mGrid.getObjectif() == nullptr) {
        return "Individu";
    }

    // Let's assume monster won when it's not the player ¯\_(ツ)_/¯
    return "Monsters";
}
