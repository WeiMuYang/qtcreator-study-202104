
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
class QFile;
class QDialogButtonBox;
class QLabel;
class QProgressBar;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

public slots:
    void saveFile();
	void stop();
    void openFile();

private:
    void timerEvent(QTimerEvent* event);	
	void doCopy();
	QProgressBar *progressBar;
    QLabel *statusLabel;
    QPushButton *saveButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QPushButton *stopButton;
    QDialogButtonBox *buttonBox;

    QFile 	*rFile;
	QFile	*wFile;
    qint64  totalBytes;
    qint64  bytesWritten;
    qint64  bytesToWrite;
    qint64  loadSize;
    QString fileName;
	QString currentFile;
    QByteArray tempBuf;
	bool isStop;
	int timeId;


};

#endif
