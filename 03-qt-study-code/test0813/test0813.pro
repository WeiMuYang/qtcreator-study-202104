#-------------------------------------------------
#
# Project created by QtCreator 2020-08-13T19:15:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = test0813
TEMPLATE = app





SOURCES += main.cpp\
        mainwindow.cpp \
    welldata.cpp \
    process.cpp \
    threadwell.cpp

HEADERS  += mainwindow.h \
    welldata.h \
    process.h \
    threadwell.h

FORMS    += mainwindow.ui
