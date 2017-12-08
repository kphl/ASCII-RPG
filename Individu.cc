#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <iostream>

#include "Individu.hh"

Individu::Individu(unsigned int x, unsigned int y)
    : Movable(x, y, 'i')
{ }

Individu::~Individu(){
}



std::vector<Position> Individu::thinkMove(Position& target) const {
    std::vector<std::pair<unsigned int, Position>> possiblePositionsDistances;
    
    possiblePositionsDistances.push_back(std::pair<unsigned int, Position>(
        (target.X() - mPosition.X()) + std::abs((int)target.Y() - ( (int)mPosition.Y() + (int)Individu::MOVE_STEP)),
        Position(mPosition.X(), mPosition.Y() + Individu::MOVE_STEP)
        
    ));
    
    possiblePositionsDistances.push_back(std::pair<unsigned int, Position>(
        (target.X() - mPosition.X()) + std::abs((int)target.Y() - ( (int)mPosition.Y() - (int)Individu::MOVE_STEP)),
        Position(mPosition.X(), mPosition.Y() - Individu::MOVE_STEP)
    ));
    
    possiblePositionsDistances.push_back(std::pair<unsigned int, Position>(
        (target.X() - (mPosition.X() + Individu::MOVE_STEP)) + (target.Y() - mPosition.Y()),
        Position(mPosition.X() + Individu::MOVE_STEP, mPosition.Y())
    ));
    
    possiblePositionsDistances.push_back(std::pair<unsigned int, Position>(
        std::abs((int)target.X() - ((int)mPosition.X() - (int)Individu::MOVE_STEP)) + (target.Y()),
        Position(mPosition.X() - Individu::MOVE_STEP, mPosition.Y())
    ));
    
    std::sort(
        possiblePositionsDistances.begin(),
        possiblePositionsDistances.end(),
        [](std::pair<unsigned int, Position> const & a, std::pair<unsigned int, Position> const & b){ 
            return a.first < b.first;
        }
    );
    
    std::vector<Position> sortedPositions;
    for (auto it(possiblePositionsDistances.begin());it != possiblePositionsDistances.end();++it) {
        std::cout << it->first << "(list) : "
            << ((Position)it->second).X() << " "
            << ((Position)it->second).Y() << std::endl;
        
        sortedPositions.push_back(it->second);
    }
    
    return sortedPositions;
}

void Individu::move(Position& pos) {
    mPosition.X() = pos.X();
    mPosition.Y() = pos.Y();
}



