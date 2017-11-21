#ifndef OBJECT_HH
#define OBJECT_HH

class Object {
    public:
        Object();
        Object(unsigned int x, unsigned int y, char symbol);
        ~Object();
        
        unsigned int getX() const;
        void setX(unsigned int x);
        
        unsigned int getY() const;
        void setY(unsigned int y);
        
        char getSymbol() const;
        void setContent(char symbol);
    
    private:
        unsigned int mX;
        unsigned int mY;
        char mSymbol;
};

#endif

