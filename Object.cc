#include "Object.hh"

Object::Object(unsigned int x, unsigned int y, char symbol)
    : mPosition(x, y), mSymbol(symbol)
{ }

Object::~Object(){
     // pure virtual destructor
     // plz let this function empty
}

Position& Object::pos() {
    return mPosition;
}

Position const& Object::pos() const {
    return mPosition;
}

char& Object::symbol() {
    return mSymbol;
}

char const& Object::symbol() const {
    return mSymbol;
}
