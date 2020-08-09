#-------------------------------------------------
#
# Project created by QtCreator 2020-08-08T22:07:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UdpHost
TEMPLATE = app


SOURCES += main.cpp\
        udphost.cpp \
    travel.cpp

HEADERS  += udphost.h \
    travel.h

FORMS    += udphost.ui
