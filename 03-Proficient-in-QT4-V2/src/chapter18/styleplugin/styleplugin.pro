TEMPLATE    = lib
CONFIG     += plugin
HEADERS     = mystyle.h \
              mystyleplugin.h
SOURCES     = mystyle.cpp \
              mystyleplugin.cpp
TARGET      = mystyleplugin
DESTDIR     = $$[QT_INSTALL_PLUGINS]/styles

# install
target.path = $$[QT_INSTALL_PLUGINS]/styles
INSTALLS += target
