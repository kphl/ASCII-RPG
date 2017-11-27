#ifndef IMOVABLE__HH
#define IMOVABLE__HH

#include "Position.hh"

class IMovable {
public:
    virtual ~IMovable() {}

    virtual void move(Position& pos) = 0;
};

#endif
