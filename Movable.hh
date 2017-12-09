#ifndef MOVABLE__HH
#define MOVABLE__HH

#include <map>
#include <vector>

#include "IMovable.hh"
#include "Object.hh"
#include "Position.hh"

class Movable : public Object, public IMovable {
public:
    Movable(unsigned int x, unsigned int y, char symbol);
    virtual ~Movable() = 0;

    virtual std::vector<Position> thinkMove(Position& target) const = 0;
    virtual void move(Position& pos) = 0;

    /// Basical AI algorithms

    static std::vector<Position> findMovesOrthogonal(Position const& current, unsigned int step);

    static std::vector<std::pair<unsigned int, Position>> computeDistances(std::vector<Position> const& positions, Position const& target);

    static void sortMoves(std::vector<std::pair<unsigned int, Position>>& movements);
};

#endif
