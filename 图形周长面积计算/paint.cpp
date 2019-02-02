#include "paint.h"
#include "ui_paint.h"
#include<QString>
#include<QDebug>
#include<plotwidget.h>
extern int  left_margine ;
extern int  right_margine ;
extern int  top_margine ;
extern int  bottom_margine ;

paint::paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paint)
{
    ui->setupUi(this);  
    m_valuex=200;
    m_valuey=200;
}

paint::~paint()
{
    delete ui;
}
/*
 * 改变x坐标系值
 */
void paint::on_pushButton_x_clicked()
{
    m_valuex=ui->doubleSpinBox_MAXX->value();
    ui->plotview->Map_x_value=ui->doubleSpinBox_MAXX->value();
    ui->plotview->update();
}
/*
 * 改变y坐标系值
 */
void paint::on_pushButton_y_clicked()
{
    m_valuey=ui->doubleSpinBox_MAXY->value();
    ui->plotview->Max_y_value=ui->doubleSpinBox_MAXY->value();
    ui->plotview->update();
}
//以下三个位记录当前选择绘制那个图形
void paint::on_pushButton_clicked()
{
     ui->plotview->Flin=true;
     ui->plotview->Fcircle=false;
     ui->plotview->Ftraingle=false;
}

void paint::on_pushButton_2_clicked()
{
    ui->plotview->Flin=false;
    ui->plotview->Fcircle=true;
    ui->plotview->Ftraingle=false;
    ui->plotview->radiu[ui->plotview->circlenum+1]=ui->spinBox_circle->value();
}

void paint::on_pushButton_3_clicked()
{
    ui->plotview->Flin=false;
    ui->plotview->Fcircle=false;
    ui->plotview->Ftraingle=true;
}
/*根据坐标系值大小计算面积*/
void paint::on_pushButton_cal_clicked()
{
    double right_pos = width() - right_margine;
    double bottom_pos = height()- bottom_margine;
    double area=ui->plotview->CalArea();
    area=(double)((m_valuex*m_valuey)/((right_pos-left_margine)*(bottom_pos-top_margine)))*area;
    QString q=QString("%1").arg(area,0,'g',9);
    ui->label_Area->setText(q);
}
