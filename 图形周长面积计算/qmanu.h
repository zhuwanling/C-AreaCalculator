#ifndef QMANU_H
#define QMANU_H

#include <QMainWindow>
#include "QPainter"
#include"QPen"
#include"Qimage"
#include"qchoose.h"
#include"qdate.h"
#include"plotshap.h"
#include"csimply.h"
#include"ccircle.h"
#include"crect.h"
#include"csquer.h"
#include"ctriangle.h"
#include"convexhul.h"
#include"somedefine.h"
#include"qellipse.h"
#include"csector.h"
#include"paint.h"
namespace Ui {
class QManu;
}

class QManu : public QMainWindow
{
    Q_OBJECT

public:
    explicit QManu(QWidget *parent = 0);
    ~QManu();
public:
     void paintEvent(QPaintEvent *event);    //绘制事件的重载
private:
     void  Inity();                   //界面的初始化
     void  SloveAreaAnswer();         //根据类型选着计算
private:
    int flag;                     //背景图片的一个参数
    int m_nstarSizeX;             //初始化界面的宽
    int m_nstarSizeY;             //初始化界面的长

    enum type{area,perimeter};
    enum type  CalType;             //面积计算 与周长计算的记录参数
    QChoose * m_manager;
    Qdate * m_date;
    plotshap *m_gergroph;
    paint *m_point;
    Ui::QManu *ui;

private slots:
    void on_pushButton_clicked();                 //运行计算按钮

    void on_pushButton_model_clicked();              //模式转换按钮

    void on_action_pain_triggered();

signals:
    void SaveDate();                           //存储数据

};

#endif // QMANU_H
