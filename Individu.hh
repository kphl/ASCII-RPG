#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Movable.hh"

class Individu : public Movable {
public:
    Individu(unsigned int x, unsigned int y);
    virtual ~Individu();

    std::vector<Position> thinkMove(Position const& target) const override;
    void move(Position& pos) override;

    static const unsigned int MOVE_STEP = 1;
};

#endif
