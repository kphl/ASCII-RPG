#include <vector>
#include <utility>

#include "Monstre.hh"
#include "Position.hh"

Monstre::Monstre(unsigned int x, unsigned int y)
    : Movable(x, y, 'm')
{ }

Monstre::~Monstre(){
}

unsigned int Monstre::stepDistance() const {
    return Monstre::MOVE_STEP;
}

std::vector<Position> Monstre::thinkMove(Position const& target) const {
    std::vector<Position> possiblePositions = Movable::findMovesOrthogonal(mPosition, stepDistance());
    std::vector<std::pair<unsigned int, Position>> positionDistances =  Movable::computeDistances(possiblePositions, target);
    Movable::sortMoves(positionDistances);

    std::vector<Position> sortedPositions;

    for (auto it(positionDistances.begin());it != positionDistances.end();++it) {
        sortedPositions.push_back(it->second);
    }

    return sortedPositions;
}

bool Monstre::move(Position const& pos, Object const* object) {
    if (!object
        || object->symbol() == 'i') {
        mPosition.X() = pos.X();
        mPosition.Y() = pos.Y();
        return true;
    }

    return false;
}
