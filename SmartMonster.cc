#include "Object.hh"
#include "SmartMonstre.hh"


SmartMonster::SmartMonster(unsigned int x, unsigned int y)
    : Monstre(x, y)
{
    mSymbol = SmartMonster::SYMBOL;
}

SmartMonster::~SmartMonster() {
}

std::vector<Position> SmartMonster::thinkMove(Position const& target) const {
    std::vector<Position> possiblePositions;

    std::vector<Position> orth = Movable::findMovesOrthogonal(mPosition, stepDistance());
    std::vector<Position> diag = Movable::findMovesDiagonal(mPosition, stepDistance());

    possiblePositions.insert(possiblePositions.end(), orth.begin(), orth.end());
    possiblePositions.insert(possiblePositions.end(), diag.begin(), diag.end());

    std::vector<std::pair<unsigned int, Position>> positionDistances =  Movable::computeDistances(possiblePositions, target);
    Movable::sortMoves(positionDistances);

    std::vector<Position> sortedPositions;

    for (auto it(positionDistances.begin());it != positionDistances.end();++it) {
        sortedPositions.push_back(it->second);
    }

    return sortedPositions;
}
