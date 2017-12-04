#include "Monstre.hh"

Monstre::Monstre(unsigned int x, unsigned int y)
    : Movable(x, y, 'm')
{ }

Monstre::~Monstre(){
}

void Monstre::move(Position& pos) {
    // plz implement here Monster's brain o/
    pos = pos; // quick hack to avoid -Wunused-parameter at compilation for now
}
