#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSerialPort *serial = new QSerialPort;
    //设置串口名
    serial->setPortName(ui->portBox->currentText());
    //打开串口
    serial->open(QIODevice::ReadWrite);
    //设置波特率
    serial->setBaudRate(ui->rateBox->currentText().toInt());

    serial->isOpen();


    return a.exec();
}
