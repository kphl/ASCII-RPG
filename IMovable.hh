#ifndef IMOVABLE__HH
#define IMOVABLE__HH

#include <vector>

#include "Object.hh"
#include "Position.hh"

class IMovable {
public:
    virtual ~IMovable() = 0;

    // max distance for a step
    virtual unsigned int stepDistance() const = 0;

    // compute possible movements
    virtual std::vector<Position> thinkMove(Position const& target) const = 0;

    // attempt a move to pos, tell if the move was done (object is the current object at pos (nullptr if there is nothing))
    virtual bool move(Position const& pos, Object const* object) = 0;
};

#endif
