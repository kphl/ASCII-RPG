#ifndef SMARTMONSTER__HH
#define SMARTMONSTER__HH

#include <vector>

#include "Monstre.hh"
#include "Position.hh"

class SmartMonster : public Monstre {
public:
    static const char SYMBOL = 'M';

    SmartMonster(unsigned int x, unsigned int y);
    virtual ~SmartMonster();

    std::vector<Position> thinkMove(Position const& target) const override;
};

#endif
