#ifndef IMOVABLE__HH
#define IMOVABLE__HH

#include "Position.hh"

class IMovable {
public:
    virtual ~IMovable() = 0;

    virtual void move(Position& pos) = 0;
};

#endif
