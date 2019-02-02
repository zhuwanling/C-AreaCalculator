#ifndef QCHOOSE_H
#define QCHOOSE_H

#include <QWidget>
#include"Qdate.h"
#include"somedefine.h"
namespace Ui {
class QChoose;
}

class QChoose : public QWidget
{
    Q_OBJECT

public:
    explicit QChoose(QWidget *parent = 0);
    ~QChoose();
    Qdate *m_date;
    int m_type;

private:
    void InitColor();
    Ui::QChoose *ui;

private slots:     //用户选择不同图形
    void on_pushButtoncircle_clicked();

    void on_pushButton_2rect_clicked();

    void on_pushButton_3quere_clicked();

    void on_pushButton_4traigle_clicked();

    void on_pushButton_5line_clicked();


    void on_pushButton_6ellipse_clicked();
    void on_pushButton_7Sector_clicked();
};

#endif // QCHOOSE_H
