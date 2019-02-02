#include "ccircle.h"
#include"QDebug"

Ccircle::Ccircle(int edge)
{
    m_dradiu=edge;
    m_dPI = 3.141;
}


Ccircle::~Ccircle()
{
}

/*
 * 面积计算
 */
double Ccircle::CalArea()
{
    return m_dPI*m_dradiu*m_dradiu;
}

double Ccircle::CalC()
{
    return m_dPI*m_dradiu;
}
