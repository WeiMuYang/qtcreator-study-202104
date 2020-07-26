#ifndef CONVERTWIDGET_H_
#define CONVERTWIDGET_H_

#include <QWidget>
#include "ui_convert.h" 

class ConvertWidget : public QWidget, private Ui::convertWidget
{
	Q_OBJECT
	
public:
	ConvertWidget(QWidget *parent = 0);
	virtual ~ConvertWidget();
private slots:
	void on_btnConvert_clicked();
	void on_btnExit_clicked();
	void on_btnSource_clicked();
	void on_btnDest_clicked();
	void on_radioGBToUTF_clicked();
	void on_radioUTFToGB_clicked();
private:
	QTextCodec *srcCodec;
	QTextCodec *destCodec;
};

#endif /*CONVERTWIDGET_H_*/
