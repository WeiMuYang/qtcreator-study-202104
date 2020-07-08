
#include <math.h>
#include <QDebug>
#include "calculate.h"
Calculate::Calculate()
{

}

void Calculate::initInput(double price,double area,int percent,double interest,int year)
{
	m_price =price;
	m_area = area;
	m_percent = percent;
	m_interest = interest;
	m_year = year;

}

double Calculate::housePrice()
{
	double houseprice = m_price*m_area;
	return houseprice;
}

double Calculate::lead()
{
	double load = housePrice()*m_percent*0.1;
	return load;
}

double Calculate::payPerMonth()
{
	double capital = m_price*m_area*m_percent*0.1;
	double monthinterest = m_interest/12*0.85*0.01;
	double temp = pow((1+monthinterest),(m_year*12));
	double paypermonth = (capital*monthinterest*temp)/(temp-1);
	qDebug()<<paypermonth;
	return paypermonth;
}

int Calculate::totalMonths()
{
	int totalmonths = m_year*12;
	return totalmonths;
}

double Calculate::initPay()
{
	double initpay = housePrice()*(1-m_percent*0.1);
	return initpay;
}

double Calculate::totalPay()
{
	double totalpay = payPerMonth()*totalMonths();
	return totalpay;

}

double Calculate::totalInterest()
{
	double totalinterest = totalPay()-lead();
	return totalinterest;
}


