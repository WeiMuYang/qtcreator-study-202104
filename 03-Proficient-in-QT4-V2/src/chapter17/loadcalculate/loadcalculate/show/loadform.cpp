
// #include <QtGui>
#include "loadform.h"
#include "calculate_interface.h"

 LoadForm::LoadForm(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    calc = new CalculateInterface("org.freedesktop.DbusExample", "/Calculate",
						QDBusConnection::sessionBus(), this);
    connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(submitClickedSlot()));
    connect(revertButton, SIGNAL(clicked(bool)), this, SLOT(revertClickedSlot()));
}

LoadForm::~LoadForm()
{
}

void LoadForm::submitClickedSlot()
{
	price = priceEdit->text().trimmed().toDouble();
	area = areaEdit->text().trimmed().toDouble();
	percent = percentEdit->text().trimmed().toInt();
	interest = interestEdit->text().trimmed().toDouble();
	year = yearEdit->text().trimmed().toInt();

	calc->initInput(price,area,percent,interest,year);
	
	housePriceEdit->setText(QString(tr("%1元")).arg(calc->housePrice(),0,'f',2));
	leadEdit->setText(QString(tr("%1元")).arg(calc->lead(),0,'f',2));
	totalPayEdit->setText(QString(tr("%1元")).arg(calc->totalPay(),0,'f',2));
	totalInterestEdit->setText(QString(tr("%1元")).arg(calc->totalInterest(),0,'f',2));
	initPayEdit->setText(QString(tr("%1元")).arg(calc->initPay(),0,'f',2));
	totalMonthsEdit->setText(QString(tr("%1月")).arg(calc->totalMonths()));
	payEdit->setText(QString(tr("%1元")).arg(calc->payPerMonth(),0,'f',2));
}

void LoadForm::revertClickedSlot()
{
	priceEdit->clear();
	areaEdit->clear();
	percentEdit->clear();
	interestEdit->clear();
	yearEdit->clear();
	
	housePriceEdit->clear();
	leadEdit->clear();
	totalPayEdit->clear();
	totalInterestEdit->clear();
	initPayEdit->clear();
	totalMonthsEdit->clear();
	payEdit->clear();
}

