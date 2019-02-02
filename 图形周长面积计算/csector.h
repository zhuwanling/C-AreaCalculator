#ifndef CSECTOR_H
#define CSECTOR_H
#include"csimply.h"
class CSector : public Csimply
{
public:
    CSector(int L,int R);
    ~CSector();
    double m_L;
    double m_R;
    virtual double CalArea();//计算面积
    virtual double CalC();//计算周长
};

#endif // CSECTOR_H
