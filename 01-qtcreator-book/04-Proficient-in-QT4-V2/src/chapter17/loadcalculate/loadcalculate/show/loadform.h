
#ifndef LOADFORM_H
#define LOADFORM_H

#include "ui_loadform.h"
class CalculateInterface;
class LoadForm: public QWidget, Ui::ShowWidget
{
    Q_OBJECT

public:
    LoadForm(QWidget *parent = 0);
    ~LoadForm();

private slots:

    void submitClickedSlot();
	void revertClickedSlot();
		
private:
	double price;
	double area;
	int percent;
	double interest;
	int year;
    CalculateInterface *calc;
};

#endif