
#ifndef CALCULATE_H
#define CALCULATE_H
#include <QObject>
 class Calculate : public QObject
 {
    Q_OBJECT
public:
    Calculate();
public Q_SLOTS:
    double housePrice();
    double lead();	
    double payPerMonth();
    int totalMonths();
    double initPay();
    double totalPay();
    double totalInterest();
    void   initInput(double price,double area,int percent,double interest,int year);
private:
    double m_price; 
    double m_area;
    int m_percent;
    double m_interest;
    int m_year;
};

#endif