#include "plotshap.h"
#include "ui_plotshap.h"

plotshap::plotshap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plotshap)
{
    ui->setupUi(this);
}

plotshap::~plotshap()
{
    delete ui;
}

void plotshap::paintEvent(QPaintEvent *event) //
{
    QPainter painter(this);
    QPen  solidpen;
    solidpen.setColor(Qt::black);
    solidpen.setWidth(4);
    painter.setPen(solidpen);
    ShowShap(&painter);

}
/*
 * 绘制对应图形
 */
void plotshap::ShowShap(QPainter *painer )
{
    if(type== traiglenum)
    {
        int edge=0;
        int heighe=0;
        if(!date.empty())
        {
            edge=date.front();
            date.pop();
            heighe=date.front();
            date.pop();
            edge=(edge%10+1)*10;
            heighe=(heighe%10+1)*10;
            painer->drawLine(0,100,edge,100);
            painer->drawLine((edge/2),100-heighe,0,100);
            painer->drawLine((edge/2),100-heighe,edge,100);

      }
    }
   else if(type==circlenum)
    {
        int radiu;
        radiu=date.front();
        radiu=radiu%10*20;
        painer->drawEllipse(20,20,radiu,radiu);
    }
    else if(type==rectnum)
    {
        if(!date.empty())
        {
        int wedge;
        int hedge;

        hedge=date.front();
        date.pop();
        wedge=date.front();
        date.pop();
        wedge=(wedge%10)*20;
        hedge=(hedge%10)*20;
        painer->drawRect(0,0,hedge,wedge);
        }
    }
    else if(type==querenum)
    {
        int edge;
        edge=date.front();
        edge=edge%10*20;
        painer->drawRect(0,0,edge,edge);
    }
    else if(type== ellipsenum )
    {
        if(!date.empty())
        {
        int wedge;
        int hedge;

        hedge=date.front();
        date.pop();
        wedge=date.front();
        date.pop();
        wedge=(wedge%10)*20;
        hedge=(hedge%10)*20;
        painer->drawEllipse(0,0,hedge,wedge);
        }
    }
    else if(type==linenum)
    {
        painer->drawLine(10,10,100,100);
        painer->drawLine(100,100,20,20);
        painer->drawLine(20,20,10,10);

    }
    else if(type==sectornum)
    {
        painer->drawPie(0,0,200,200,30 * 16,120 * 16);
    }
}
