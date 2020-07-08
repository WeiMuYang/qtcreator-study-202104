#include "compass.h"
#include "compassplugin.h"

#include <QtPlugin>

CompassPlugin::CompassPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void CompassPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool CompassPlugin::isInitialized() const
{
    return initialized;
}

QWidget *CompassPlugin::createWidget(QWidget *parent)
{
    return new Compass(parent);
}

QString CompassPlugin::name() const
{
    return "Compass";
}

QString CompassPlugin::group() const
{
    return "My Widgets";
}

QIcon CompassPlugin::icon() const
{
    return QIcon();
}

QString CompassPlugin::toolTip() const
{
    return "Compass";
}

QString CompassPlugin::whatsThis() const
{
    return "Compass";
}

bool CompassPlugin::isContainer() const
{
    return false;
}

QString CompassPlugin::domXml() const
{
    return "<widget class=\"Compass\" name=\"Compass\">\n"
           " <property name=\"geometry\">\n"
           "  <rect>\n"
           "   <x>0</x>\n"
           "   <y>0</y>\n"
           "   <width>100</width>\n"
           "   <height>100</height>\n"
           "  </rect>\n"
           " </property>\n"
           "</widget>\n";
}

QString CompassPlugin::includeFile() const
{
    return "compass.h";
}

Q_EXPORT_PLUGIN2(compassplugin, CompassPlugin)
