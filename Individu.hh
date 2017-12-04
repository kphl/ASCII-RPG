#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Movable.hh"

class Individu : public Movable {
public:
    Individu(unsigned int x, unsigned int y);
    virtual ~Individu();

    void move(Position& pos) override;
};

#endif
