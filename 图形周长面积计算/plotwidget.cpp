#include "plotwidget.h"
#include<QDebug>
#include <QMouseEvent>
#include<QRgb>
int  left_margine = 60;
int  right_margine = 60;
int  top_margine = 40;
int  bottom_margine = 80;

PlotWidget::PlotWidget(QWidget *parent) :
    QWidget(parent)
{
    Max_y_value = 200;
    Min_y_value = 0;
    Map_x_value = 200;//ms
    lengnum=-1;
    circlenum=-1;
    tranglenum=-1;
    Flin=false;
    Fcircle=false;
    Ftraingle=false;
    m_img=NULL;
}
void PlotWidget::mousePressEvent(QMouseEvent *event)
{
    if(Flin)
    {
    x[++lengnum]=event->pos();
    }
    else if(Fcircle)
    {
        circlex[++circlenum]=event->pos();
    }
    else if(Ftraingle)
    {
        tranglex[++tranglenum]=event->pos();
    }
    this->update();

}
void PlotWidget::mouseMoveEvent(QMouseEvent *event)
{

}
/*
 * 坐标系绘制
 */
void  PlotWidget:: paintEvent(QPaintEvent *)
{
        delete m_img;
        m_img=new QImage(width(),height(),QImage::Format_RGB32);
        QPainter painer(this);
        QPainter painge(m_img);
        QRgb value=qRgb(255,255,255);
        for(int i=0;i<width();i++)
        {
            for(int j=0;j<height();j++)
                m_img->setPixel(i,j,value);

        }
        painer.fillRect(0,0,width(),height(),Qt::white);
        if(lengnum>=1)
        {
            for(int i=0;i<=lengnum-1;i++)
            painge.drawLine(x[i].x(),x[i].y(),x[i+1].x(),x[i+1].y());
        }
        if(circlenum>=0)
        {
            for(int i=0;i<=circlenum;i++)
            {
                painge.drawEllipse(circlex[i].x()-radiu[i],circlex[i].y()-radiu[i],radiu[i]*2,radiu[i]*2);
            }
        }

        painer.drawImage(0,0,*m_img);
        plotpolar(&painer);
}

void PlotWidget::plotpolar(QPainter *painer)
{
    QPen solidpen;
    int right_pos = width() - right_margine;
    int bottom_pos = height()- bottom_margine;
    solidpen.setWidth(8);
    solidpen.setStyle(Qt::SolidLine);
    solidpen.setColor(Qt::black);
    painer->setPen(solidpen);
    painer->drawLine(left_margine - 4,top_margine,left_margine - 4,bottom_pos);   //y坐标
    solidpen.setWidth(4);
    painer->setPen(solidpen);
    painer->drawLine(left_margine,bottom_pos + 2,right_pos,bottom_pos + 2);       //x坐标
    solidpen.setWidth(0);
    solidpen.setStyle(Qt::DashLine);
    painer->setPen(solidpen);
    painer->drawLine(left_margine, top_margine + (bottom_pos- top_margine)/2.0 ,
                     right_pos,top_margine + (bottom_pos- top_margine)/2.0);   //中线
    solidpen.setStyle(Qt::DotLine);
    painer->setPen(solidpen);
    QRectF rectF1(5, top_margine -25,50,20);
    painer->drawText(rectF1,QString::fromLocal8Bit(""));
    int row=10;
    int low=10;
    for(int i = 0 ;i <= row;i++)
    {
        painer->drawLine(left_margine,top_margine + (bottom_pos - top_margine)*i/10.0
                         ,right_pos,top_margine + (bottom_pos - top_margine)*i/10.0 );
        QRectF rectF1(5, top_margine -5 + (bottom_pos - top_margine)*i/10.0,
                      50,20);
        painer->drawText(rectF1,
                         QString("%1").arg(QString::number((Max_y_value- Min_y_value)*(row-i)/10.0f,'f',2)));
    }

    for(int i = 0 ;i<=low ; i++)
    {
        painer->drawLine(left_margine + (right_pos - left_margine)*i/10.0f,top_margine
                         ,left_margine + (right_pos - left_margine)*i/10.0f,bottom_pos );
        QRectF rectF1(left_margine + (right_pos - left_margine)*i/10.0f - 30, bottom_pos + 5 ,
                      80,20);
        painer->drawText(rectF1,
                         QString("%1").arg(QString::number((Map_x_value- Min_y_value)*i/10.0f,'f',2)));
    }
}
  /*
   * 计算绘制图形包含多少像素点；
   */
double PlotWidget::CalArea()
{
     QRgb value=qRgb(255,255,255);
    int i,j;
    double sum=0;
      //统计像素点。
    for(i=0;i<width();i++)
    {
        int maxup=0;
        int maxdown=0;
        for(j=0;j<height();j++)
        {
           if( m_img->pixel(i,j)!=value)
           {
               maxup=j;
               break;
           }
        }
        for(j=height()-10;j>=0;j--)
        {
            if( m_img->pixel(i,j)!=value)
            {
                maxdown=j;
                break;
            }
        }
        sum+=maxdown-maxup;
    }
    return sum;
}
