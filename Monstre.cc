#include "Monstre.hh"

Monstre::Monstre(unsigned int x, unsigned int y)
    : Movable(x, y, 'm')
{ }

Monstre::~Monstre(){
}

std::vector<Position> Monstre::thinkMove(Position& target) const {
    std::vector<Position> possiblePositions = Movable::findMovesOrthogonal(mPosition, Monstre::MOVE_STEP);
    std::vector<std::pair<unsigned int, Position>> positionDistances =  Movable::computeDistances(possiblePositions, target);
    Movable::sortMoves(positionDistances);

    std::vector<Position> sortedPositions;

    for (auto it(positionDistances.begin());it != positionDistances.end();++it) {
        sortedPositions.push_back(it->second);
    }

    return sortedPositions;
}

void Monstre::move(Position& pos) {
    mPosition.X() = pos.X();
    mPosition.Y() = pos.Y();
}
