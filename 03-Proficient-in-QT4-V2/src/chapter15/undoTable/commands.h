#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include <QTableWidget>
#include <QColor>
#include <QList>

class UndoWidget;

class TextColorCommand : public QUndoCommand
{
public:
	TextColorCommand(UndoWidget *undoWidget, QColor beforeColor, QColor afterColor, QUndoCommand *parent = 0);

    void undo();
    void redo();

private:
	QList<QTableWidgetItem*> affectedItems;
	QColor before;
	QColor after;
};

class BkgColorCommand : public QUndoCommand
{
public:
	BkgColorCommand(UndoWidget *undoWidget, QColor beforeColor, QColor afterColor, QUndoCommand *parent = 0);

    void undo();
    void redo();

private:
	QList<QTableWidgetItem*> affectedItems;
	QColor before;
	QColor after;
};

class FontCommand : public QUndoCommand
{
public:
	FontCommand(UndoWidget *undoWidget, QFont beforeFont, QFont afterFont, QUndoCommand *parent = 0);

    void undo();
    void redo();

private:
	QList<QTableWidgetItem*> affectedItems;
	QFont before;
	QFont after;
};

class EditCommand : public QUndoCommand
{
public:
	EditCommand(QTableWidgetItem *item, QString beforeText, QString afterText, QUndoCommand *parent = 0);

    void undo();
    void redo();

private:
	QTableWidgetItem* affectedItem;
	QString before;
	QString after;
};

#endif
