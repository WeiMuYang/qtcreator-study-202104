#include <QtGui>

#include "tablemodel.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    TableModel tableModel;
    QTableView view;
    view.setModel(&tableModel);
    view.setSelectionMode(QAbstractItemView::SingleSelection);
    view.setDragDropMode(QAbstractItemView::InternalMove);
    view.setDragEnabled(true);
    view.setAcceptDrops(true);
    view.setDropIndicatorShown(true); 
    view.resize(640, 480);
    view.show();

    return app.exec();
}
