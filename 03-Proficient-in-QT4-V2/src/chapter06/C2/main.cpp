#include "target.h"

#include <QtGui>
#include <QTextCodec>
#include <QtDebug>
#include <math.h>

#include "radar.h"

static const int TargetCount = 200;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QGraphicsScene scene;
    scene.setSceneRect(-400, -300, 800, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < TargetCount; ++i) {
        Target *target = new Target;
        target->setPos(qrand() % 800 - 400,
                      qrand() % 600 - 300);
	target->setVisible(true);
        scene.addItem(target);
    }

    RadarView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(Qt::black);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QObject::tr("º£Õ½Ä£Äâ"));
    view.resize(800, 600);
    view.show();

    return app.exec();
}
