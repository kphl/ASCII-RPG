#include <stdexcept>
#include <string>

#include "Grid.hh"
#include "objectFactory.hh"

Grid::Grid() {}

Grid::Grid(unsigned int width, unsigned int height, std::string* data)
    : mWidth(width), mHeight(height), mObjects(width * height)
{
    for (unsigned int i=0;i<mWidth;++i) {
        for (unsigned int j=0;j<mHeight;++j) {
            mObjects[findIndex(i, j)] = makeObject(j, i, data[j].at(i));;
        }
    }
}

Grid::~Grid() {}

std::size_t Grid::findIndex(unsigned int x, unsigned int y) const {
    unsigned int index = x * mWidth + y;
    if (index > mWidth * mHeight) {
        throw std::out_of_range("out of range");
    }

    return index;
}

std::unique_ptr<Object>& Grid::operator() (unsigned int x, unsigned int y) {
    return mObjects.at(findIndex(x, y));
}

std::unique_ptr<Object> const& Grid::operator() (unsigned int x, unsigned int y) const {
    return mObjects.at(findIndex(x, y));
}
