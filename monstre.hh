#ifndef MONSTRE_H
#define MONSTRE_H

class Monstre
{
public:
	Monstre();

    virtual ~Monstre();

    void deplacement();

protected:
    int x, y;
};

#endif
