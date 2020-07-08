#ifndef PALETTE_H
#define PALETTE_H

#include <QtGui>

#include "previewlabel.h"

class Palette : public QWidget
{
	Q_OBJECT

public:
    Palette(QWidget *parent = 0);

signals:
	void penChanged(QPen& pen);
	void brushChanged(QBrush& brush);

private slots:
	void penChanged();
	void brushChanged();

private:
    QLabel *penColorLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *brushColorLabel;
    QLabel *brushStyleLabel;
	PreviewLabel *preLabel;
    QSpinBox *penWidthSpinBox;
    QComboBox *penColorComboBox;
    QComboBox *penStyleComboBox;
    QComboBox *brushColorComboBox;
    QComboBox *brushStyleComboBox;

	void createColorComboBox(QComboBox *comboBox);
	void createStyleComboBox();
};

#endif

