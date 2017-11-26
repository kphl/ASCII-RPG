#ifndef CONFIGS__HH
#define CONFIGS__HH

#define MAP_HEIGHT 8
#define MAP_WIDTH 8
#define MAP_FILE "data.txt"

#include <string>
std::string map[] = {
    #include MAP_FILE
};

#endif
