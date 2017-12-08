#ifndef MOVABLE__HH
#define MOVABLE__HH

#include "IMovable.hh"
#include "Object.hh"

class Movable : public Object, public IMovable {
public:
    Movable(unsigned int x, unsigned int y, char symbol);
    virtual ~Movable() = 0;

    virtual void move(Position& pos) = 0;

protected:
    Grid* mGrid;
};

#endif
