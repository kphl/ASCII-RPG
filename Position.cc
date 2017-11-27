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
