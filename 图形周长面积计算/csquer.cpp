#include "csquer.h"

Csquer::Csquer(int edge)
{
    m_dendge=edge;
}


Csquer::~Csquer()
{
}


double Csquer::CalArea()
{
    return m_dendge*m_dendge;
}

double Csquer::CalC()
{
    return 4*m_dendge;
}
