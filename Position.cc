#include <cmath>

#include "Position.hh"

Position::Position()
    : mPosition()
{}

Position::Position(const unsigned int x, const unsigned int y)
    : mPosition({x, y})
{}

Position::Position(Pos pos)
    : mPosition(pos)
{}

Position::~Position() {}

Pos& Position::operator() () {
    return mPosition;
}

Pos const& Position::operator() () const {
    return mPosition;
}

void Position::setPosition(const unsigned int x, const unsigned int y) {
    mPosition.x = x;
    mPosition.y = y;
}

void Position::setPosition(const Pos& p) {
    mPosition.x = p.x;
    mPosition.y = p.y;
}

unsigned int const& Position::X() const {
    return mPosition.x;
}

unsigned int const& Position::Y() const {
    return mPosition.y;
}

unsigned int& Position::X() {
    return mPosition.x;
}

unsigned int& Position::Y() {
    return mPosition.y;
}

unsigned int Position::distance(Position const& a, Position const& b) {
    int x_diff = a.mPosition.x - b.mPosition.x;
    int y_diff = a.mPosition.y - b.mPosition.y;

    int x_diff_abs = std::abs(x_diff);
    int y_diff_abs = std::abs(y_diff);

    return x_diff_abs + y_diff_abs;
}
