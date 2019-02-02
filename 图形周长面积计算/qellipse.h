#ifndef QELLIPSE_H
#define QELLIPSE_H
#include"csimply.h"

class qellipse: public  Csimply
{
public:
    qellipse(int longedg,int widthedge);
     virtual double CalArea();
    virtual  double CalC();
private:
    double m_longedge,m_widthedgw;
    const double PI;
};
#endif // QELLIPSE_H
