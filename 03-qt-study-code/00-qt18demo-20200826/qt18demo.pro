#-------------------------------------------------
#
# Project created by QtCreator 2020-07-15T20:02:07
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt18demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    wellsdata.cpp \
    changesyncstatus.cpp \
    settingconfig.cpp \
    mdi.cpp \
    processjosn.cpp \
    wellofprocess.cpp \
    threadwell.cpp \
    threadudp.cpp

HEADERS  += mainwindow.h \
    wellsdata.h \
    changesyncstatus.h \
    settingconfig.h \
    mdi.h \
    processjosn.h \
    wellofprocess.h \
    threadwell.h \
    threadudp.h

FORMS    += mainwindow.ui \
    mdi.ui

DISTFILES +=

RESOURCES += \
    images.qrc
