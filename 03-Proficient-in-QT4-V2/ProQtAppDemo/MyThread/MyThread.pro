#-------------------------------------------------
#
# Project created by QtCreator 2020-06-13T17:50:35
#
#-------------------------------------------------

QT       += core gui
CONFIG += thread

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyThread
TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    workthread.cpp

HEADERS  += dialog.h \
    workthread.h

FORMS    +=
