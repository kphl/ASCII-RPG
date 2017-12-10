#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

#include "configs.hh"
#include "Movable.hh"

Movable::Movable(unsigned int x, unsigned int y, char symbol)
    : Object(x, y, symbol)
{ }

Movable::~Movable(){
    // pure virtual destructor
}

/// AI algorithms

std::vector<Position> Movable::findMovesOrthogonal(Position const& current, unsigned int step) {
    std::vector<Position> possiblePositions;

    while(step > 0) {
        possiblePositions.push_back(
            Position(
                current.X(),
                current.Y() > step - MAP_HEIGHT ? MAP_HEIGHT : current.Y() + step ));

        possiblePositions.push_back(
            Position(
                current.X(),
                current.Y() < step ? 0 : current.Y() - step ));

        possiblePositions.push_back(
            Position(
                current.X() > step + MAP_WIDTH ? MAP_WIDTH : current.X() + step,
                current.Y() ));

        possiblePositions.push_back(
            Position(
                current.X() < step ? 0 : current.X() - step,
                current.Y() ));

        --step;
    }

    return possiblePositions;
}

std::vector<std::pair<unsigned int, Position>> Movable::computeDistances(std::vector<Position> const& positions, Position const& target) {
    std::vector<std::pair<unsigned int, Position>> distances;

    for (auto it(positions.begin());it!=positions.end();++it) {
        distances.push_back(
            std::pair<unsigned int, Position>(
                Position::distance(*it, target),
                *it
            ));
    }

    return distances;
}

void Movable::sortMoves(std::vector<std::pair<unsigned int, Position>>& movements) {
    std::sort(
        movements.begin(),
        movements.end(),
        [](std::pair<unsigned int, Position> const& a, std::pair<unsigned int, Position> const& b) {
            // sort Positions by distances only
            return a.first < b.first;
        }
    );
}
