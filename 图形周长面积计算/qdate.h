#ifndef QDATE_H
#define QDATE_H

#include <QWidget>
#include<queue>
#include <string>
#include"somedefine.h"
using  namespace std;

namespace Ui {
class Qdate;
}
/*
 *数据类
 */
class Qdate : public QWidget
{
    Q_OBJECT

public:
    explicit Qdate(QWidget *parent = 0);
    ~Qdate();
    queue <int>dateStove;
      void ShowInputcircle();  //各种输入界面显示
      void ShowInputrect();
      void ShowInputquere();
      void ShowInputtraigle();
      void ShowInputline();
      void ShowInputellipse();
      void ShowInputSector();

private:
    void Init();
    void Securit();
    Ui::Qdate *ui;

public slots:
     void saveDate();
};

#endif // QDATE_H
