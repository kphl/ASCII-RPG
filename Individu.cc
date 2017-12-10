#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <iostream>

#include "Individu.hh"

Individu::Individu(unsigned int x, unsigned int y)
    : Movable(x, y, 'i')
{ }

Individu::~Individu(){
}

std::vector<Position> Individu::thinkMove(Position const& target) const {
    std::vector<Position> possiblePositions = Movable::findMovesOrthogonal(mPosition, Individu::MOVE_STEP);
    std::vector<std::pair<unsigned int, Position>> positionDistances =  Movable::computeDistances(possiblePositions, target);
    Movable::sortMoves(positionDistances);

    std::vector<Position> sortedPositions;

    for (auto it(positionDistances.begin());it != positionDistances.end();++it) {
        sortedPositions.push_back(it->second);
    }

    return sortedPositions;
}

void Individu::move(Position& pos) {
    mPosition.X() = pos.X();
    mPosition.Y() = pos.Y();
}
