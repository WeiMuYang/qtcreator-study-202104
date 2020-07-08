#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QtGui>

class MapWidget : public QWidget
{
    Q_OBJECT

public:
	MapWidget(QWidget *parent = 0);

private slots:
    void updateUI(int row);
    inline void toNext()
    {
    	mapper->toNext();
    };
    
    inline void toPrevious()
    {
    	mapper->toPrevious();
    };

private:
    void populateModel();

    QLabel *companyLabel;
    QLabel *typeLabel;
    QLabel *displacementLabel;
    QLabel *nationLabel;

    QComboBox *companyCombo;
    QLineEdit *typeEdit;
    QDoubleSpinBox *displacementSpin;
    QLabel *flagLabel;

    QPushButton *btnNext;
    QPushButton *btnPrev;
    QPushButton *btnSubmit;
    QPushButton *btnRevert;

    QStringList companies;

    QStandardItemModel *model;
    QDataWidgetMapper *mapper;
    
    QShortcut *leftShortCut;
    QShortcut *rightShortCut;
};

#endif
