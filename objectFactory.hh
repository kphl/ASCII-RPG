#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <memory>

#include "Object.hh"

std::unique_ptr<Object> makeObject(unsigned int x, unsigned int y, char c);

#endif
