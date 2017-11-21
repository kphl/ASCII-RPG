#ifndef OBJECTIF_H
#define OBJECTIF_H

class Objectif
{
public:
	Objectif(int x, int y);

    virtual ~Objectif();

    void deplacement();

protected:
    int x_, y_;
};

#endif
