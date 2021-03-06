#ifndef GRID_H
#define GRID_H

#include <memory>
#include <string>
#include <vector>

#include "Individu.hh"
#include "Object.hh"
#include "Monstre.hh"
#include "Objectif.hh"
#include "Potion.hh"
#include "Thune.hh"

class Grid {
public:
    Grid(unsigned int width, unsigned int height, std::vector<std::string>& data);
    virtual ~Grid();

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    std::unique_ptr<Object>& operator() (unsigned int x, unsigned int y);
    std::unique_ptr<Object> const& operator() (unsigned int x, unsigned int y) const;

    Individu* getIndividu() const;
    Objectif* getObjectif() const;
    Potion* getPotion() const;
    Thune* getThune() const;
    std::vector<Monstre*> getMonstres() const;

protected:
    std::size_t findIndex(unsigned int x, unsigned int y) const;

private:
    unsigned int mWidth;
    unsigned int mHeight;
    std::vector<std::unique_ptr<Object>> mObjects;
};

#endif
