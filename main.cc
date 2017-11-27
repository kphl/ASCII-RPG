#include <iostream>
#include <string>
#include <vector>

/*
#include "Grid.hh"
#include "Individu.hh"
#include "Monstre.hh"
#include "Objectif.hh"
#include "Rocher.hh"
*/


#include "configs.hh"

int main()
{
/*
	std::string dataTxt[] = {
	    #include "data.txt"
	};
*/
    for (auto s : map)
        std::cout << s << std::endl;


/*
    std::vector<std::string> data;
    for (auto s : dataTxt)
        data.push_back(s);

    std::vector<Rocher> rochers;
    Grid g(data);
    for(int y = 0; y < data.size(); y++){
        for(int x = 0; x < data[y].size(); x++){
            if(data[y][x] == 'i')
                break;
            if(data[y][x] == 'm')
                break;
            if(data[y][x] == 'o'){
                Rocher r(x, y);
                rochers.push_back(r);
                break;
            }
            if(data[y][x] == 'T')
                break;
        }
    }

    while(True){
    }
*/

    return 1;
}
