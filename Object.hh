#ifndef OBJECT_HH
#define OBJECT_HH

#include "Position.hh"

class Object {
public:
    Object(unsigned int x, unsigned int y, char symbol);
    virtual ~Object() = 0;

    Position& pos();
    Position const& pos() const;

    char& symbol();
    char const& symbol() const;

protected:
    Position mPosition;
    char mSymbol;
};

#endif
