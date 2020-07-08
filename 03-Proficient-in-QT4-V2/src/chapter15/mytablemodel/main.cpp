#include <QtGui>

#include "weaponmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    WeaponModel model;

    QTableView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("自定义模型"));
    view.resize(640,480);
    view.show();
    return app.exec();
}
