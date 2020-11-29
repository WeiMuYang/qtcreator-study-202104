#-------------------------------------------------
#
# Project created by QtCreator 2020-11-17T11:12:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = USB
TEMPLATE = app


SOURCES += main.cpp\
        usb.cpp

HEADERS  += usb.h \
    lusb0_usb.h

FORMS    += usb.ui

LIBS +=  D:\Qt\libusbwin32\gcc\libusb.a

