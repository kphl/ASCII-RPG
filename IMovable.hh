#ifndef IMOVABLE__HH
#define IMOVABLE__HH

#include <vector>

#include "Position.hh"

class IMovable {
public:
    virtual ~IMovable() = 0;

    // compute possible movements
    virtual std::vector<Position> thinkMove(Position const& target) const = 0;

    // do the move to pos
    virtual void move(Position& pos) = 0;
};

#endif
