#include "ctriangle.h"

#include "Ctriangle.h"


Ctriangle::Ctriangle(int edge,int height)
{
    m_dheight=height;
    m_dendge=edge;
}


Ctriangle::~Ctriangle()
{
}


double Ctriangle::CalArea()
{
    return m_dheight*m_dendge/2;
}
double Ctriangle::CalC()
{

}
