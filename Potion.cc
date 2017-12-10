#include "Position.hh"
#include "Potion.hh"


Potion::Potion(unsigned int x, unsigned int y)
    : Object(x, y, Potion::SYMBOL)
{ }

Potion::~Potion(){
}
