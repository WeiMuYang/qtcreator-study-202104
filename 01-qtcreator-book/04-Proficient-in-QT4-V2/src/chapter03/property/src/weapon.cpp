#include "weapon.h"

CWeapon::CWeapon(QObject * parent)
 :	QObject(parent)
{
}
Status CWeapon::getStatus() const
{
	return status;
}

void CWeapon::setStatus(Status s)
{
	status = s;
}
