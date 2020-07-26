
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


class QLabel;
class QPushButton;
class TimeServer;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
public slots:
		void showResult();
private:
    QLabel *statusLabel;
		QLabel *reqStatusLable;
    QPushButton *quitButton;
    TimeServer *server;
		int count;
};

#endif
