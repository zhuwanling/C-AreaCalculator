#ifndef PAINT_H
#define PAINT_H

#include <QWidget>

namespace Ui {
class paint;
}

class paint : public QWidget
{
    Q_OBJECT

public:
    explicit paint(QWidget *parent = 0);
    ~paint();

private slots:             //选择的图形
    void on_pushButton_x_clicked();

    void on_pushButton_y_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_cal_clicked();

private:
    int  m_valuex;
    int  m_valuey;
    Ui::paint *ui;
};

#endif // PAINT_H
