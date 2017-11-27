#ifndef POSITION_HH
#define POSITION_HH

struct Pos {
    unsigned int x;
    unsigned int y;
};


class Position {
public:
    Position();
    Position(const unsigned int x, const unsigned int y);
    Position(Pos pos);
    virtual ~Position();

    Pos& operator() ();
    Pos const& operator() () const;

    void setPosition(const unsigned int x, const unsigned int y);
    void setPosition(const Pos& p);

private:
    Pos mPosition;
};

#endif
