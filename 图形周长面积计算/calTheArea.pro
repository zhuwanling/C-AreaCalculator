#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T22:37:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calTheArea
TEMPLATE = app


SOURCES += main.cpp\
        qmanu.cpp \
    qchoose.cpp \
    qdate.cpp \
    plotshap.cpp \
    csimply.cpp \
    ccircle.cpp \
    crect.cpp \
    csquer.cpp \
    ctriangle.cpp \
    convexhul.cpp \
    qellipse.cpp \
    csector.cpp \
    plotwidget.cpp \
    paint.cpp

HEADERS  += qmanu.h \
    qchoose.h \
    qdate.h \
    plotshap.h \
    csimply.h \
    ccircle.h \
    crect.h \
    csquer.h \
    ctriangle.h \
    convexhul.h \
    somedefine.h \
    qellipse.h \
    csector.h \
    plotwidget.h \
    paint.h

FORMS    += qmanu.ui \
    qchoose.ui \
    qdate.ui \
    plotshap.ui \
    paint.ui

RESOURCES += \
    picture.qrc
