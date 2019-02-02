#include "qellipse.h"

qellipse::qellipse(int longedg,int widthedge):
PI(3.14)
{
    m_longedge=longedg;
    m_widthedgw=widthedge;
}


double qellipse:: CalArea()
{
    return  PI*m_longedge*m_widthedgw;
}
double qellipse::CalC()
{
    return PI*(m_longedge+m_widthedgw);
}
