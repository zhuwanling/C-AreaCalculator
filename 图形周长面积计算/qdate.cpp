#include "qdate.h"
#include "ui_qdate.h"

Qdate::Qdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qdate)
{
    ui->setupUi(this);
    Init();
    ui->labelcm->hide();
}

Qdate::~Qdate()
{
    delete ui;
}


/*
 * 控件的初始化
 */
void Qdate::Init()
{
    ui->labelcm->show();
    ui->inputlineEdit1->hide();
    ui->inputlineEdit2->hide();
    ui->inputname1->hide();
    ui->inputname2->hide();
    ui->textEdit->hide();
    ui->inputlineEdit1->setText(NULL);
   ui->inputlineEdit2->setText(NULL);
   ui->textEdit->setText(NULL);
}
void  Qdate::ShowInputcircle()
{
   Init();
   ui->inputname1->setText("请输入半径");
   ui->inputname1->show();
   ui->inputlineEdit1->show();
}

/*
 * 以下为对输入宽框架的调整
 */
void  Qdate::ShowInputline()
{
    Init();
    ui->inputname1->setText("请输入顶点个数");
    ui->inputname2->setText("请输入顶点");
    ui->textEdit->show();
    ui->inputlineEdit1->show();
    ui->inputname1->show();
    ui->inputname2->show();
 }
void  Qdate::ShowInputquere()
{
    Init();
    ui->inputname1->setText("请输入边长");
    ui->inputlineEdit1->show();
    ui->inputname1->show();
}
void  Qdate::ShowInputrect()
{
    Init();
    ui->inputname1->setText("请输入长方形的长");
    ui->inputname2->setText("请输入长方形的宽");
    ui->inputlineEdit1->show();
    ui->inputlineEdit2->show();
    ui->inputname1->show();
    ui->inputname2->show();
}
void  Qdate::ShowInputtraigle()
{
    Init();
    ui->inputname1->setText("请输入三角形的高");
    ui->inputname2->setText("请输入三角形的底");
    ui->inputlineEdit1->show();
    ui->inputlineEdit2->show();
    ui->inputname1->show();
    ui->inputname2->show();
}
void Qdate::ShowInputellipse()
{
    Init();
    ui->inputname1->setText("请输入椭圆的长半轴");
    ui->inputname2->setText("请输入椭圆的短半轴");
    ui->inputlineEdit1->show();
    ui->inputlineEdit2->show();
    ui->inputname1->show();
    ui->inputname2->show();
}
void Qdate::ShowInputSector()
{
    Init();
    ui->inputname1->setText("请输入扇形的弧长L");
    ui->inputname2->setText("请输入扇形的半径R");
    ui->inputlineEdit1->show();
    ui->inputlineEdit2->show();
    ui->inputname1->show();
    ui->inputname2->show();
}
//检查数据正确性
void Qdate::Securit()
{
    int flag=0;
    for(int i=0;i<dateStove.size();i++)
    {
     //  if(dateStove[i]
    }
}
//存储数据
void Qdate::saveDate()
{
    while(!dateStove.empty())
    {
        dateStove.pop();
    }    //清除数据
    QString  temp;
    temp=ui->inputlineEdit1->text();
    if(temp!=NULL)
    {
            int a=temp.toInt();
            dateStove.push(a);
    }
     temp=ui->inputlineEdit2->text();
     if(temp!=NULL)
     {
             int a=temp.toInt();
             dateStove.push(a);
     }
     temp=ui->textEdit->toPlainText();\
     if(temp!=NULL)
     {
    QStringList number_list = temp.split("\n");

    for (int i = 0; i < number_list.size(); ++i)
    {
           QStringList number_listnum= number_list.at(i).split(" ");
          for(int j=0;j<2;j++)
          {
               dateStove.push(number_listnum.at(j).toInt());
          }
    }
     }
}
