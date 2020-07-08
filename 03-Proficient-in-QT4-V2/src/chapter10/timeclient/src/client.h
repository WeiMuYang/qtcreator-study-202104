
#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>

class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QDateTimeEdit;

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    void readTime();
    void requsetTime();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton();

private:
    QLabel *hostLabel;
    QLabel *portLabel;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *getTimeButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;

    QTcpSocket *tcpSocket;
    uint time2u;
		QDateTimeEdit *dateEdit;
};

#endif
