#include "qmanu.h"
#include "ui_qmanu.h"



QManu::QManu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QManu)
{
    ui->setupUi(this);
    flag=0;
    CalType=area;
    Inity();
    connect(this,SIGNAL(SaveDate()),m_date,SLOT(saveDate()));
    m_point=NULL;

}

QManu::~QManu()
{
    delete m_date;
    delete m_manager;
    delete m_gergroph;
    delete ui;
}
/*
 * 菜单初始界面设置
*/
void QManu:: Inity()
{
    ui->label->hide();
    ui->valuelabel->hide();
    setWindowTitle("面积计算");
    m_nstarSizeX=800;
    m_nstarSizeY=600;
    resize(m_nstarSizeX, m_nstarSizeY);
    m_manager=new QChoose(this);
    m_manager->move(0,20);
    m_manager->show();
    m_date=new Qdate(this);
    m_date->move(300,300);
    m_date->show();
    m_gergroph=new plotshap(this);
    m_gergroph->move(400,0);
    m_manager->m_date=m_date;
}
/*
 * 菜单背景图绘制
 */
void QManu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage img;
    QImage nimg;
    img.load(":/new/prefix1/bk.jpg");
    if(flag==0)
    {
        nimg=img.scaled(m_nstarSizeX,m_nstarSizeY);
        painter.drawImage(0,0,nimg);
        flag=1;
    }
    else
    {
          nimg=img.scaled(width(),height());
           painter.drawImage(0,0,nimg);
    }
}

/*
 * 点击确定按钮开始计算面积
 */
void QManu::on_pushButton_clicked()
{
    emit SaveDate();
    m_gergroph->hide();
    m_gergroph->date=m_date->dateStove;
    m_gergroph->type=m_manager->m_type;
    m_gergroph->move(600,60);
    m_gergroph->show();
    SloveAreaAnswer();

}


/*
 * 计算选着图形
 */
void QManu:: SloveAreaAnswer()
{
    Csimply  *Shap=NULL;
    switch (m_manager->m_type)
    {
    case circlenum :
    {
        int edge=m_date->dateStove.front();
        m_date->dateStove.pop();
        Shap=new Ccircle(edge);
    } break;
    case rectnum:
    {
        int h=m_date->dateStove.front();
        m_date->dateStove.pop();
        int w=m_date->dateStove.front();
         m_date->dateStove.pop();
         Shap=new Crect(w,h);

    }  break;
     case querenum:
    {\
        int edge=m_date->dateStove.front();
         m_date->dateStove.pop();
          Shap=new Csquer(edge);
    } break;
    case  traiglenum:
    {
        int witdh=m_date->dateStove.front();
         m_date->dateStove.pop();
         int height=m_date->dateStove.front();
           m_date->dateStove.pop();
           Shap=new Ctriangle(witdh,height);
    }  break;
    case  linenum:
    {
        CConvexHul *line=new CConvexHul;
        line->date=m_date->dateStove;
        line->Input();
        Shap=line;
    } break;
    case ellipsenum:
    {
        int witdh=m_date->dateStove.front();
         m_date->dateStove.pop();
         int height=m_date->dateStove.front();
           m_date->dateStove.pop();
           Shap=new qellipse(witdh,height);
    }  break;
    case sectornum:
    {
        int L=m_date->dateStove.front();
                 m_date->dateStove.pop();
                 int R=m_date->dateStove.front();
                   m_date->dateStove.pop();
                   Shap=new CSector(L,R);
    } break;
    }
    if(Shap!=NULL)
    {
        QString answer;
        if(CalType==area)
        {
          answer=QString("%1").arg(Shap->CalArea());
           ui->label->setText("面积：");
        }
        else if(CalType==perimeter)
        {
           answer=QString("%1").arg(Shap->CalC());
           ui->label->setText("周长：");
        }
    ui->valuelabel->setText(answer);
    ui->valuelabel->show();
    ui->label->show();
    }
}


/*
 * 模式转换
 */
void QManu::on_pushButton_model_clicked()
{
    if(CalType==area)
    {
       if(m_manager->m_type!=traiglenum)
       {
       CalType=perimeter;
       ui->pushButton_model->setText("切换模式(周长)");
       }

    }
    else if(CalType==perimeter)
    {
        CalType=area;
        ui->pushButton_model->setText("切换模式(面积)");
    }
}

void QManu::on_action_pain_triggered()
{
    m_point=new  paint;
    m_point->show();

}
