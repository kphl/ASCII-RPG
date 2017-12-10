#include <stdexcept>
#include <string>

#include "Grid.hh"
#include "Individu.hh"
#include "Object.hh"
#include "objectFactory.hh"
#include "Monstre.hh"
#include "Object.hh"

Grid::Grid(unsigned int width, unsigned int height, std::vector<std::string>& data)
    : mWidth(width), mHeight(height), mObjects(width * height)
{
    for (unsigned int y=0;y<mHeight;++y) {
        for (unsigned int x=0;x<mWidth;++x) {
            mObjects[findIndex(x, y)] = makeObject(x, y, data.at(y).at(x));
        }
    }
}

Grid::~Grid() {
}

std::size_t Grid::findIndex(unsigned int x, unsigned int y) const {
    unsigned int index = y * mWidth + x;
    if (index >= mWidth * mHeight) {
        throw std::out_of_range("out of range \\o/");
    }

    return index;
}

unsigned int Grid::getWidth() const {
    return mWidth;
}

unsigned int Grid::getHeight() const {
    return mHeight;
}

std::unique_ptr<Object>& Grid::operator() (unsigned int x, unsigned int y) {
    return mObjects.at(findIndex(x, y));
}

std::unique_ptr<Object> const& Grid::operator() (unsigned int x, unsigned int y) const {
    return mObjects.at(findIndex(x, y));
}

Individu* Grid::getIndividu() const {
    for (auto it = mObjects.begin();it!= mObjects.end();++it) {
        if ((*it).get()) {
            if ((*it)->symbol() == 'i') {
                return static_cast<Individu*>((*it).get());
            }
        }
    }

    return nullptr;
}

Objectif* Grid::getObjectif() const {
    for (auto it = mObjects.begin();it!= mObjects.end();++it) {
        if ((*it).get()) {
            if ((*it)->symbol() == 'T') {
                return static_cast<Objectif*>((*it).get());
            }
        }
    }

    return nullptr;
}

Potion* Grid::getPotion() const {
    for (auto it = mObjects.begin();it!= mObjects.end();++it) {
        if ((*it).get()) {
            if ((*it)->symbol() == '*') {
                return static_cast<Potion*>((*it).get());
            }
        }
    }

    return nullptr;
}

std::vector<Monstre*> Grid::getMonstres() const {
    std::vector<Monstre*> monstres;

    for (auto it = mObjects.begin();it!= mObjects.end();++it) {
        if ((*it).get()) {
            if ((*it)->symbol() == 'm' || (*it)->symbol() == 'M') {
                monstres.push_back(static_cast<Monstre*>((*it).get()));
            }
        }
    }

    return monstres;
}
