#include "qmanu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QManu w;
    w.show();

    return a.exec();
}
