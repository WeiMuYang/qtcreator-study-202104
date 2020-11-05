QT += core
QT -= gui

CONFIG += c++11

TARGET = testIOI
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    bdaqctrl.h \
    compatibility.h
