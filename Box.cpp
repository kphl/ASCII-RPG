#include "Box.hh"
#include "Object.hh"

Box::Box()
    : mX(0), mY(0), mContent(nullptr)
{}

Box::Box(unsigned int x, unsigned int y)
    : mX(x), mY(y), mContent(nullptr)
{}

Box::Box(unsigned int x, unsigned int y, Object* content)
    : mX(x), mY(y), mContent(content)
{}

Box::~Box() {
}

unsigned int Box::getX() const {
    return mX;
}

void Box::setX(unsigned int x) {
    mX = x;
}

unsigned int Box::getY() const {
    return mY;
}

void Box::setY(unsigned int y) {
    mY = y;
}

Object* Box::getContent() const {
    return mContent;
}

void Box::setContent(Object* content) {
    mContent = content;
}

