#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Movable.hh"

class Individu : public Movable {
public:
    static const unsigned int DEFAULT_STEP_DISTANCE = 1;
    static const unsigned int BOOSTED_STEP_DISTANCE = 2;

    Individu(unsigned int x, unsigned int y);
    virtual ~Individu();

    unsigned int stepDistance() const override;
    std::vector<Position> thinkMove(Position const& target) const override;
    bool move(Position const& pos, Object const* object) override;

private:
    unsigned int mStepDistance;
};

#endif
