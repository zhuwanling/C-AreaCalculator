#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include"Csimply.h"
class Ctriangle : public Csimply
{
public:
    Ctriangle(int edge,int height);
   ~Ctriangle();
    virtual double CalArea();   //计算面积
    virtual double CalC();//计算周长
private:
    double  m_dheight;
    double m_dendge;
};

#endif // CTRIANGLE_H
