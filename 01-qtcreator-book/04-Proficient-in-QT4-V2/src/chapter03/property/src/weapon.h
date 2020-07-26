#include <QObject>

#ifndef _WEAPON_H_
#define _WEAPON_H_

typedef enum {
	nil, 
	ready, 
	fired, 
	exceptional
}Status;

class CWeapon : public QObject
{
	Q_OBJECT
	Q_PROPERTY(Status status READ getStatus WRITE setStatus)
	Q_ENUMS(Status)

public:
	CWeapon(QObject *parent = 0);
	void setStatus(Status s);
	Status getStatus() const;
	
private:
	Status status;
	Status st;
};
#endif
