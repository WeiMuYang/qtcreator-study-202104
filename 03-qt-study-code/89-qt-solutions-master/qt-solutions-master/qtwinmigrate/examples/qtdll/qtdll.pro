TEMPLATE     = lib
CONFIG	    += dll
SOURCES	     = main.cpp \
    widget.cpp

TARGET	     = qtdialog
DLLDESTDIR   = $$[QT_INSTALL_PREFIX]/bin

include(../../src/qtwinmigrate.pri)

FORMS += \
    widget.ui

HEADERS += \
    widget.h
