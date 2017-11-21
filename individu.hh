#ifndef INDIVIDU_H
#define INDIVIDU_H

class Individu
{
public:
	Individu();

    virtual ~Individu();

    void deplacement();

protected:
    int x, y;
};

#endif
