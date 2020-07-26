#ifndef MSG_H
#define MSG_H

#include <QtCore>
#include <QtGui>

class Msg : public QWidget
{
	Q_OBJECT

public:
	Msg();

public slots:
	void directoryChanged(QString path);
	void fileChanged(QString path);

private:
	QLabel* label;
	QFileSystemWatcher fsWatcher;
};
#endif
