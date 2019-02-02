#ifndef CRECT_H
#define CRECT_H
#include"Csimply.h"


class Crect :public  Csimply
{
public:
    Crect(int witdh,int height);
    ~Crect();
    virtual double  CalArea();//计算面积
    virtual double CalC();//计算周长
private:
    double m_dwitdh;
    double m_dheight;
};

#endif // CRECT_H
