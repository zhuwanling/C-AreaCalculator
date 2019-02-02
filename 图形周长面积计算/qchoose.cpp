#include "qchoose.h"
#include "ui_qchoose.h"

QChoose::QChoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QChoose)
{
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
    ui->setupUi(this);
     m_type=0;
}

QChoose::~QChoose()
{
     delete m_date;
    delete ui;
}
/*
 * 还原初始化按钮的颜色
 */
void QChoose::InitColor()
{
   ui->pushButtoncircle->setStyleSheet("background-color: rgb(240, 240, 240)");
   ui->pushButton_2rect->setStyleSheet("background-color: rgb(240, 240, 240)");
   ui->pushButton_3quere->setStyleSheet("background-color: rgb(240, 240, 240)");
   ui->pushButton_4traigle->setStyleSheet("background-color: rgb(240, 240, 240)");
   ui->pushButton_5line->setStyleSheet("background-color: rgb(240, 240, 240)");
   ui->pushButton_6ellipse->setStyleSheet("background-color: rgb(240, 240, 240)");
   ui->pushButton_7Sector->setStyleSheet("background-color: rgb(240, 240, 240)");
}

/*
 *以下为各个对应界面转换
 */
void QChoose::on_pushButtoncircle_clicked()
{
    m_type=circlenum;
    m_date->ShowInputcircle();
    InitColor();
    ui->pushButtoncircle->setStyleSheet("background-color:red");
}

void QChoose::on_pushButton_2rect_clicked()
{
     InitColor();
     ui->pushButton_2rect->setStyleSheet("background-color:red");
    m_type=rectnum;
    m_date->ShowInputrect();
}

void QChoose::on_pushButton_3quere_clicked()
{
     InitColor();
     ui->pushButton_3quere->setStyleSheet("background-color:red");
    m_type=querenum;
    m_date->ShowInputquere();
}

void QChoose::on_pushButton_4traigle_clicked()
{
     InitColor();
     ui->pushButton_4traigle->setStyleSheet("background-color:red");
    m_type=traiglenum;
    m_date->ShowInputtraigle();
}


void QChoose::on_pushButton_5line_clicked()
{
     InitColor();
     ui->pushButton_5line->setStyleSheet("background-color:red");
    m_type=linenum;
    m_date->ShowInputline();
}

void QChoose::on_pushButton_6ellipse_clicked()
{
     InitColor();
     ui->pushButton_6ellipse->setStyleSheet("background-color:red");
    m_type=ellipsenum;
    m_date->ShowInputellipse();
}

void QChoose::on_pushButton_7Sector_clicked()
{
     InitColor();
     ui->pushButton_7Sector->setStyleSheet("background-color:red");
    m_type=sectornum;
    m_date->ShowInputSector();
}
