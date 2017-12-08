#ifndef MONSTRE_H
#define MONSTRE_H

#include "Movable.hh"

class Monstre : public Movable {
public:
    Monstre(unsigned int x, unsigned int y);
    virtual ~Monstre();

    std::vector<Position> thinkMove(Position& target) const override;
    void move(Position& pos) override;
};

#endif
