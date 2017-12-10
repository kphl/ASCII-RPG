#ifndef POTION__HH
#define POTION__HH

#include "Object.hh"

class Potion : public Object {
public:
    static const char SYMBOL = '*';

    Potion(unsigned int x, unsigned int y);
    virtual ~Potion();
};

#endif
