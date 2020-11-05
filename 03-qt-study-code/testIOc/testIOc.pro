QT += core
QT -= gui

CONFIG += c++11

TARGET = testIOc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    bdaqctrl.h \
    compatibility.h
