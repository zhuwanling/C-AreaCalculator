#ifndef PLOTSHAP_H
#define PLOTSHAP_H

#include <QWidget>
#include"QPainter"
#include"queue"
#include"somedefine.h"
using namespace std;
namespace Ui {
class plotshap;
}
/*
 * 绘制对应图形的类
 */

class plotshap : public QWidget
{
    Q_OBJECT

public:
    explicit plotshap(QWidget *parent = 0);
    ~plotshap();
    queue<int>date;
    int type;

private:
    Ui::plotshap *ui;
    void paintEvent(QPaintEvent *event);
    void  ShowShap(QPainter *painer );
};

#endif // PLOTSHAP_H
