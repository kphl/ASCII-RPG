#ifndef GRID_H
#define GRID_H

#include <memory>
#include <string>
#include <vector>

#include "Object.hh"

class Grid {
public:
    Grid(unsigned int width, unsigned int height, std::string* data);
    virtual ~Grid();

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    std::unique_ptr<Object>& operator() (unsigned int x, unsigned int y);
    std::unique_ptr<Object> const& operator() (unsigned int x, unsigned int y) const;

protected:
    std::size_t findIndex(unsigned int x, unsigned int y) const;

private:
    unsigned int mWidth;
    unsigned int mHeight;
    std::vector<std::unique_ptr<Object>> mObjects;
};

#endif
