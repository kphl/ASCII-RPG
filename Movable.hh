#ifndef MOVABLE__HH
#define MOVABLE__HH

#include "IMovable.hh"
#include "Object.hh"

class Movable : public Object, public IMovable {
    Movable(Position& p, char symbol);
    virtual ~Movable();

    virtual void move(Position& pos) = 0;
};

#endif
