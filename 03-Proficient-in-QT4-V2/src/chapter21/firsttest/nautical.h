#ifndef NAUTICAL_H
#define NAUTICAL_H

#include <QObject>

class Nautical : public QObject 
{
	Q_OBJECT

public:
	Nautical(int nm)
	{
		m_nm = nm;
	};

	double toKilometer()
	{
		return m_nm * 1.852;
	}

private:
	double m_nm;
};

#endif

