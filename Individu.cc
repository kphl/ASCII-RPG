#include <utility>
#include <vector>

#include "Individu.hh"

Individu::Individu(unsigned int x, unsigned int y)
    : Movable(x, y, 'i'), mStepDistance(Individu::DEFAULT_STEP_DISTANCE)
{ }

Individu::~Individu(){
}

unsigned int Individu::stepDistance() const {
    return mStepDistance;
}

std::vector<Position> Individu::thinkMove(Position const& target) const {
    std::vector<Position> possiblePositions = Movable::findMovesOrthogonal(mPosition, stepDistance());
    std::vector<std::pair<unsigned int, Position>> positionDistances =  Movable::computeDistances(possiblePositions, target);
    Movable::sortMoves(positionDistances);

    std::vector<Position> sortedPositions;

    for (auto it(positionDistances.begin());it != positionDistances.end();++it) {
        sortedPositions.push_back(it->second);
    }

    return sortedPositions;
}

bool Individu::move(Position const& pos, Object const* object) {
    bool ok(false);

    if (!object) {
        ok = true;
    }
    else {
        switch (object->symbol()) {
            case 'T':
                ok = true;
                break;
            case '*':
                ok = true;
                mStepDistance = Individu::BOOSTED_STEP_DISTANCE;
                break;
            case '$':
                ok = true;
                break;
            default: break;
        }
    }

    if (ok) {
        mPosition.X() = pos.X();
        mPosition.Y() = pos.Y();
        return true;
    }

    return false;
}
