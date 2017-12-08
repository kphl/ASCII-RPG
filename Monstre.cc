#include "Monstre.hh"

Monstre::Monstre(unsigned int x, unsigned int y)
    : Movable(x, y, 'm')
{ }

Monstre::~Monstre(){
}

std::vector<Position> Monstre::thinkMove(Position& target) const {
    /*int x_diff = mPosition().x - pos().x;
    int y_diff = mPosition().y - pos().y;

    int x_diff_abs = std::abs(x_diff);
    int y_diff_abs = std::abs(y_diff);

    std::vector<Position> possiblePositions;

    Position p;
    if (x_diff_abs > y_diff_abs) {
        p.x = mPosition().x + Individu::MOVE_STEP * (x_diff > 0 ? 1 : -1);
        p.y = mPosition().y;
    }
    else {
        p.x = mPosition().x;
        p.y = mPosition().y += 1 * (y_diff > 0 ? 1 : -1);
    }
    possiblePositions.push_back(p);
    
    Position p2;
    if (x_diff_abs > y_diff_abs) {
        p2.x = mPosition().x;
        p2.y = mPosition().y += 1 * (y_diff > 0 ? 1 : -1);
    }
    else {
        p2.x = mPosition().x + Individu::MOVE_STEP * (x_diff > 0 ? 1 : -1);
        p2.y = mPosition().y;
    }
    possiblePositions.push_back(p2)
    
    return possiblePositions;*/
    return std::vector<Position>(1);
}

void Monstre::move(Position& pos) {
    mPosition.X() = pos.X();
    mPosition.Y() = pos.Y();
}

