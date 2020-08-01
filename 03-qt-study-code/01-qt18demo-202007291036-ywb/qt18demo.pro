#-------------------------------------------------
#
# Project created by QtCreator 2020-07-15T20:02:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt18demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wellsdata.cpp \
    changesyncstatus.cpp \
    settingconfig.cpp \
    mdi.cpp

HEADERS  += mainwindow.h \
    wellsdata.h \
    changesyncstatus.h \
    settingconfig.h \
    mdi.h

FORMS    += mainwindow.ui \
    mdi.ui

DISTFILES +=

RESOURCES += \
    images.qrc
