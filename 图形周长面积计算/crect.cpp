#include "crect.h"

Crect::Crect(int witdh,int height)
{
   m_dheight=height;
   m_dwitdh=witdh;
}


Crect::~Crect()
{
}
/*
 * 面积计算
 */
double Crect::CalArea()
{
    return m_dwitdh*m_dheight;
}
double Crect::CalC()
{
    return 2*(m_dwitdh+m_dheight);
}
