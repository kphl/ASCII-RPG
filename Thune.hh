#ifndef THUNE_H
#define THUNE_H

#include "Object.hh"

class Thune : public Object {
public:
    static const char SYMBOL = '$';

    Thune(unsigned int x, unsigned int y);
    virtual ~Thune();
};

#endif
