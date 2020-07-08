CONFIG      += designer plugin debug_and_release
TEMPLATE    = lib
DESTDIR     = $$[QT_INSTALL_PLUGINS]/designer

CONFIG(debug, debug|release) {
    mac: TARGET = $$join(TARGET,,,_debug)
    win32: TARGET = $$join(TARGET,,,d)
}

INCLUDEPATH += .

# Input
HEADERS += compass.h compassplugin.h
SOURCES += compass.cpp compassplugin.cpp

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
