#include <cmath>

#include "Individu.hh"

Individu::Individu(unsigned int x, unsigned int y)
    : Movable(x, y, 'i')
{ }

Individu::~Individu(){
}

void Individu::move(Position& pos) {
    pos = pos; // quick hack to avoid -Wunused-parameter at compilation for now

    int x_diff = mPosition().x - pos().x;
    int y_diff = mPosition().y - pos().y;

    int x_diff_abs = std::abs(x_diff);
    int y_diff_abs = std::abs(y_diff);

    if (x_diff_abs > y_diff_abs) {
        mPosition().x += 1 * (x_diff > 0 ? 1 : -1);
    }
    else {
        mPosition().y += 1 * (y_diff > 0 ? 1 : -1);
    }
}
