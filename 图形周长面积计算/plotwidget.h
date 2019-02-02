#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include<QPixmap>
#include<QPoint>
#include<QImage>
#define MAX 1000
class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = 0);
    double Max_y_value;
    double Min_y_value;
    double Map_x_value;
    QPixmap *DrawMap;
    bool F_inital;
    int  DrowCount;
    QPoint x[MAX];       //直线的点
    QPoint circlex[MAX];    //园的点
    QPoint tranglex[MAX];      //三角形的点
    int lengnum;     //直线点的个数
    int circlenum;
    int tranglenum;
    bool Flin;  //当前是否画直线
    bool Fcircle ;//当前是否画圆
    bool Ftraingle;//当前是否画三角形
    int radiu[MAX];   //记录半径
private:
    void paintEvent(QPaintEvent *);
    void plotpolar(QPainter *painer);
    QImage *m_img;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public :
    double CalArea();
public slots:

};

#endif // PLOTWIDGET_H
