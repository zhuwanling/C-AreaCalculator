#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"csimply.h"

class Ccircle : public  Csimply
{
public:
    Ccircle(int edge);
   ~Ccircle();
    virtual double CalArea();   //计算面积
    virtual double CalC();      //计算周长
    double m_dradiu;
private:
    double m_dPI;
};

#endif // CCIRCLE_H
