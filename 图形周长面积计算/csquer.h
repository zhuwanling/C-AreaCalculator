#ifndef CSQUER_H
#define CSQUER_H
#include"Csimply.h"

class Csquer:public Csimply
{
public:
    Csquer(int edge);
    ~Csquer();
    virtual double CalArea();
     virtual double CalC();
private:
    double m_dendge;
};
#endif // CSQUER_H
