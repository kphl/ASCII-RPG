#ifndef CONFIGS__HH
#define CONFIGS__HH

#define MAP_HEIGHT 8
#define MAP_WIDTH 7
#define MAP_FILE "data.txt"

#include <string>
#include <vector>
std::vector<std::string> MAP = {
    #include MAP_FILE
};

#endif
