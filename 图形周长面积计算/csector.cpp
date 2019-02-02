#include "csector.h"

CSector::CSector(int L,int R)
{
    m_L=L;
    m_R=R;
}

CSector::~CSector()
{

}
double  CSector::CalArea()
{
    return m_L*m_R/2;
}

double  CSector::CalC()
{
    return m_L+2*m_R;
}
