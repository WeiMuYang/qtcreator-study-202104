/////////////////////////////////////////////////////////////////
// æ≤Ã¨ Ù–‘°£
// #include <QtCore>
// #include "weapon.h"
// 
// int main(int argc, char *argv[])
// {
// 	QCoreApplication app(argc, argv);	
// 	
// 	CWeapon weapon;
// 	weapon.setStatus(fired);
// 	qDebug() << "status " << weapon.getStatus();
// 	weapon.setProperty("xxx", 1);
// 	qDebug() << "ID " << weapon.property("xxx").toInt();
// 	
//   	return 0;
// }

////////////////////////////////////////////////////////////////////
// ∂ØÃ¨ Ù–‘°£
#include <QtCore>
#include "weapon.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);	
	
	CWeapon weapon;
	weapon.setStatus(fired);
	qDebug() << "status " << weapon.getStatus();
	weapon.setProperty("own", 1);
	qDebug() << "own" << weapon.property("own").toInt();
	
  	return 0;
}
