#include "Movable.hh"

Movable::Movable(unsigned int x, unsigned int y, char symbol)
    : Object(x, y, symbol)
{ }

Movable::~Movable(){
    // pure virtual destructor
}
