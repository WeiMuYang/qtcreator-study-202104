
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#define MAXSIZE 5
class QDialogButtonBox;
class QProgressBar;
class QPushButton;
class WorkThread;

class ThreadDlg : public QDialog
{
    Q_OBJECT
public:
    ThreadDlg(QWidget *parent = 0);
public slots:
		void start();
		void stop();
private:
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *stopButton;
    QDialogButtonBox *buttonBox;
		WorkThread* threadVector[MAXSIZE];
};

#endif
