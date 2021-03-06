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

    unsigned int& X();
    unsigned int& Y();
    unsigned int const& X() const;
    unsigned int const& Y() const;

    static unsigned int distance(Position const& a, Position const& b);

    friend bool operator ==(Position const& a, Position const&b);

private:
    Pos mPosition;
};

#endif
