
#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QTcpServer>
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
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QProgressBar *clientProgressBar;
    QProgressBar *serverProgressBar;
    QLabel *serverStatusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QDialogButtonBox *buttonBox;

    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    qint64  TotalBytes;
    qint64  bytesReceived;
    qint64  fileNameSize;
    QString fileName;
    QFile *localFile;
    QByteArray inBlock;
};

#endif
