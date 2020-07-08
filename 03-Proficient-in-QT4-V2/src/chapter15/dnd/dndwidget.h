#ifndef DNDWIDGET_H
#define DNDWIDGET_H

#include <QTableWidget>

class DNDWidget : public QTableWidget
{
    Q_OBJECT

public:
    DNDWidget(QWidget * parent = 0);

private:
	void populateTable();
};

#endif
