
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <QtCore>
#include <QtNetwork>

int main()
{
   QStringList envVariables;
   QByteArray username;
   QList<QHostAddress> broadcastAddresses;
   QList<QHostAddress> ipAddresses;
   envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";

   QStringList environment = QProcess::systemEnvironment();
   foreach (QString string, envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            QStringList stringList = environment.at(index).split("=");
            if (stringList.size() == 2) {
                username = stringList.at(1).toUtf8();
		qDebug()<<username.data();
                break;
            }
        }
    }

    broadcastAddresses.clear();
    ipAddresses.clear();
    qDebug()<<"Interface numbers"<<QNetworkInterface::allInterfaces().count();
    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces()) {
		qDebug()<<"Interface name:"<<interface.name()<<endl<<"Interface hardwareAddress:"<<interface.hardwareAddress()<<endl<<"entry numbers:"<<interface.addressEntries().count();
		foreach (QNetworkAddressEntry entry, interface.addressEntries()) {
				QHostAddress broadcastAddress = entry.broadcast();
				qDebug()<<"entry ip:"<<entry.ip()<<"entry netmask:"<<entry.netmask();
				if (broadcastAddress != QHostAddress::Null) {
					broadcastAddresses << broadcastAddress;
					ipAddresses << entry.ip();
				}
			}
		}
}
