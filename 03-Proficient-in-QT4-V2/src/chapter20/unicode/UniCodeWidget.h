#ifndef UNICODEWIDGET_H_
#define UNICODEWIDGET_H_

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

class UniCodeWidget : public QWidget
{
	Q_OBJECT
public:
	UniCodeWidget();
	virtual ~UniCodeWidget();
private slots:
	void showUniCode(const QString& text);	
private:
	QLineEdit *txtEdit;
	QLabel *lblUnicode;
	QVBoxLayout *layout;
};

#endif /*UNICODEWIDGET_H_*/
