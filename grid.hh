#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <vector>

class Grid
{
public:
	Grid();
	Grid(std::vector<std::string> data);
    virtual ~Grid();

protected:
    std::vector<std::string> data_;
};

#endif
