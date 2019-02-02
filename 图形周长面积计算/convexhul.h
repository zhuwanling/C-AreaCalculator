#ifndef CONVEXHUL_H
#define CONVEXHUL_H
#include"Csimply.h"
#include<queue>
#include"math.h"
using namespace std;
struct POINT
{
    int x, y;
    POINT(int x = 0, int y = 0) :x(x), y(y) {}
};
class CConvexHul:
 public	Csimply
{
public:
    CConvexHul();
   ~CConvexHul();
    void Input();
    queue<int>date;   //存储数据

private:
    POINT * m_point;   //存储点
    int m_nsize;

public:
    double Cross(POINT A, POINT B) { return (A.x*B.y - A.y*B.x); }
    void SortPoint();    //犄角排序
    double CalArea();
    double CalC();
};

#endif // CONVEXHUL_H
