#ifndef BOX_HH
#define BOX__HH

#include "Object.hh"

class Box {
    public:
        Box();
        Box(unsigned int x, unsigned int y);
        Box(unsigned int x, unsigned int y, Object* content);
        ~Box();

        unsigned int getX() const;
        void setX(unsigned int x);
        
        unsigned int getY() const;
        void setY(unsigned int y);
        
        Object* getContent() const;
        void setContent(Object* content);

    private:
        unsigned int mX;
        unsigned int mY;
        Object* mContent;
};

#endif
