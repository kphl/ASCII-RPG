#ifndef MONSTRE_H
#define MONSTRE_H

#include "Movable.hh"

class Monstre : public Movable {
public:
    Monstre(unsigned int x, unsigned int y);
    virtual ~Monstre();

    unsigned int stepDistance() const override;
    std::vector<Position> thinkMove(Position const& target) const override;
    bool move(Position const& pos, Object const* object) override;

    static const unsigned int MOVE_STEP = 1;
};

#endif
