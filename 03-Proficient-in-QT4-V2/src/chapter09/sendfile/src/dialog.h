
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
class QFile;
class QDialogButtonBox;
class QLabel;
class QProgressBar;
class QPushButton;
class QTcpSocket;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

public slots:
    void start();
    void startTransfer();
    void updateClientProgress(qint64 numBytes);
    void displayError(QAbstractSocket::SocketError socketError);
    void openFile();

private:
    QProgressBar *clientProgressBar;
    QLabel *clientStatusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QDialogButtonBox *buttonBox;

    QTcpSocket tcpClient;
    qint64  TotalBytes;
    qint64  bytesWritten;
    qint64  bytesToWrite;
    qint64  loadSize;
    QString fileName;
    QFile *localFile;
    QByteArray outBlock;
};

#endif
