#include <sstream>
#include <vector>

#include "Game.hh"
#include "Individu.hh"
#include "Monstre.hh"
#include "Objectif.hh"
#include "Potion.hh"
#include "SmartMonstre.hh"

Game::Game(unsigned int width, unsigned int height, std::vector<std::string>& map)
    : mGrid(width, height, map)
{ }

Game::~Game() {
}

void Game::update() {
    Individu* individu = mGrid.getIndividu();
    Objectif* objectif = mGrid.getObjectif();
    Potion* potion = mGrid.getPotion();

    Object* iTarget = objectif;
    if (potion) {
        iTarget = potion;
    }

    // Individu
    moveMovable(*individu, *iTarget);

    // if the player hit the target, the game is finished
    if (isFinished()) {
        return;
    }

    // Monstre
    for (Monstre* m : mGrid.getMonstres()) {
        moveMovable(*m, *individu);

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
    if (!isFinished()) {
        return "\"5 more minutes plzzz\" :c";
    }

    if (mGrid.getObjectif() == nullptr) {
        return "Individu";
    }

    // Let's assume monster won when it's not the player ¯\_(ツ)_/¯
    return "Monsters";
}

void Game::moveMovable(Movable& movable, Object const& target) {
    Position pos = movable.pos();
    std::vector<Position> possiblePositions = movable.thinkMove(target.pos());

    for (Position p : possiblePositions) {
        // the movement is possible only if the destination cell is nullptr or the target
        if (movable.move(p, mGrid(p.X(), p.Y()).get())) {
            mGrid(p.X(), p.Y()) = std::move(mGrid(pos.X(), pos.Y()));
            break;
        }
    }
}
