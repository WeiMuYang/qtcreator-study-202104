#-------------------------------------------------
#
# Project created by QtCreator 2020-08-11T20:55:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qdicethread.cpp

HEADERS  += mainwindow.h \
    qdicethread.h

FORMS    += mainwindow.ui
