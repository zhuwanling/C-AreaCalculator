#include "convexhul.h"
#include "ConvexHul.h"


CConvexHul::CConvexHul()
{

}
CConvexHul::~CConvexHul()
{
    delete[]m_point;
}
void CConvexHul::Input()
{
    if(!date.empty())
    {
        m_nsize=date.front();
        date.pop();
        m_point=new POINT[m_nsize];
    }
    int len=0;
    int xvalue;
    int yvalue;
    while(!date.empty())
    {
        xvalue=date.front();
        date.pop();
        yvalue=date.front();
        date.pop();
        m_point[len].x=xvalue;
        m_point[len++].y=yvalue;
    }
}
/*
 * 对点进行排序函数
 */
void CConvexHul::SortPoint()
{
    int i,j;
    POINT temp(m_point[0].x,m_point[0].y);            //选取作为基点
    int index = 0;
    for (i = 0; i < m_nsize; i++)
    {
        if (m_point[i].y < temp.y || (m_point[i].y == temp.y&&m_point[i].x < temp.x))
        {
            index = i;
            temp.x = m_point[i].x;
            temp.y = m_point[i].y;
        }
    }
    m_point[index] = m_point[0];
    m_point[0] = temp;

    for (i = 1; i < m_nsize; i++)
    {
        for (j = 1; j < m_nsize - 1 - i; j++)
        {
            if ((m_point[j].y - temp.y) && (m_point[j + 1].y - temp.y))
            {
                if ((m_point[j].x - temp.x) / (m_point[j].y - temp.y) < (m_point[j + 1].x - temp.x) / (m_point[j + 1].y - temp.y))
                {
                    POINT replace;
                    replace = m_point[j];
                    m_point[j] = m_point[j + 1];
                    m_point[j + 1] = temp;
                }
            }
        }
    }


}

/*
 *计算图形面积
 */
double CConvexHul::CalArea()
{
    SortPoint();
    int i;
    double area = 0;
    for (i = 1; i < m_nsize-1; i++)
    {
        POINT temp1(m_point[i].x - m_point[0].x, m_point[i].y - m_point[0].y), temp2(m_point[i + 1].x - m_point[0].x, m_point[i + 1].y - m_point[0].y);
        area += Cross(temp1, temp2);
    }
    return area / 2;
}

/*
 * 计算图形周长
 */
double CConvexHul::CalC()
{
    double sum=0;
    for(int i=0;i<m_nsize;i++)
    {
      sum+=sqrt((m_point[i].x-m_point[i].x)*(m_point[i].x-m_point[i].x)+
                (m_point[i].y-m_point[i].y)*(m_point[i].y-m_point[i].y));
     }
    return sum;
}
