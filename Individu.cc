#include "Individu.hh"

Individu::Individu(unsigned int x, unsigned int y)
    : Movable(x, y, 'i')
{ }

Individu::~Individu(){
}

void Individu::move(Position& pos) {
    pos = pos; // quick hack to avoid -Wunused-parameter at compilation for now
}
