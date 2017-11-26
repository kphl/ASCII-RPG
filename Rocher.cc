#include <iostream>
#include <vector>
#include <string>

#include "Rocher.hh"


Rocher::Rocher()
{
}

Rocher::~Rocher(){}

Rocher::Rocher(std::vector<std::string> data){
    data_ = data;
    for (std::vector<std::string>::iterator it = data_.begin() ;
        it != data_.end() ; ++it){
        std::cout << *it << std::endl;
    }
}
