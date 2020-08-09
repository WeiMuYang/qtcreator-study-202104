#-------------------------------------------------
#
# Project created by QtCreator 2020-08-08T22:20:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = udpClient
TEMPLATE = app


SOURCES += main.cpp\
        udpclient.cpp

HEADERS  += udpclient.h

FORMS    += udpclient.ui
