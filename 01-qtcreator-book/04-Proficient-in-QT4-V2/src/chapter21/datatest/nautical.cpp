#include "nautical.h"

Nautical::Nautical()
{
}

Nautical::~Nautical()
{
}

Nautical::Nautical(const Nautical& nautical)
{
		m_nm = nautical.m_nm;
}

Nautical::Nautical(int nm)
{
		m_nm = nm;
}

double Nautical::toKilometer()
{
		return m_nm * 1.852;
}

