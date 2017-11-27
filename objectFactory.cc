#include "objectFactory.hh"

#include "Object.hh"
#include "Individu.hh"
#include "Objectif.hh"
#include "Monstre.hh"
#include "Rocher.hh"

std::unique_ptr<Object> makeObject(unsigned int x, unsigned int y, char c) {
    std::unique_ptr<Object> o;

    switch(c) {
        case 'i':
            o = std::make_unique<Individu>(x, y);
            break;
        case 'T':
            o = std::make_unique<Objectif>(x, y);
            break;
        case 'm':
            o = std::make_unique<Monstre>(x, y);
            break;
        case 'o':
            o = std::make_unique<Rocher>(x, y);
            break;
        default:
    }

    return o;
}
