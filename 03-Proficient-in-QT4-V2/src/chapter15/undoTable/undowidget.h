#ifndef UNDOWIDGET_H_
#define UNDOWIDGET_H_

#include <QTableWidget>
#include <QUndoStack>

class UndoWidget : public QTableWidget
{
	Q_OBJECT
	
public:
	QUndoStack *undoStack;

	UndoWidget(QWidget * parent = 0);
	virtual ~UndoWidget();

public slots:
	void undo();
	void redo();

protected slots:	
	void changeFrgColor();
	void changeBkgColor();
	void changeFont();
	//void recordText(QTableWidgetItem *current, QTableWidgetItem* /*previous*/);
	void recordText(QTableWidgetItem *current);
	void itemEdited(QTableWidgetItem* item);

private:
	QAction *actFrgColor;
	QAction *actBkgColor;
	QAction *actFont;
	QString currentText;
	bool ignore;

	void populateTable();
	void createActions();
};

#endif /*UNDOWIDGET_H_*/
