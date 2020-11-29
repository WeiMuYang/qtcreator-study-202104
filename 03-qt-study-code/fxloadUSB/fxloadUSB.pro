QT += core
QT -= gui

CONFIG += c++11

TARGET = fxloadUSB
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    ezusb.h \
    libusb.h


LIBS += "D:\Qt\LibUSB\Mingw32\libusb.a"
