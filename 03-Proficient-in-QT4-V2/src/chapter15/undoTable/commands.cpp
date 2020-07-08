#include <QtGui>
#include "commands.h"
#include "undowidget.h"

TextColorCommand::TextColorCommand(UndoWidget *undoWidget, QColor beforeColor, 
		QColor afterColor, QUndoCommand *parent)
    : QUndoCommand(parent)
{
	affectedItems = undoWidget->selectedItems();
	before = beforeColor;
	after = afterColor;
	setText(QObject::tr("设置文字颜色"));
}

void TextColorCommand::undo()
{
    foreach(QTableWidgetItem *item, affectedItems)
        if (item) 
        	item->setTextColor(before);	// deprecated, use setForeground()	
}

void TextColorCommand::redo()
{
    foreach(QTableWidgetItem *item, affectedItems)
        if (item) 
        	item->setTextColor(after);	// deprecated, use setForeground()	
}

BkgColorCommand::BkgColorCommand(UndoWidget *undoWidget, QColor beforeColor, 
		QColor afterColor, QUndoCommand *parent)
    : QUndoCommand(parent)
{
	affectedItems = undoWidget->selectedItems();
	before = beforeColor;
	after = afterColor;
	setText(QObject::tr("设置背景颜色"));
}

void BkgColorCommand::undo()
{
    foreach(QTableWidgetItem *item, affectedItems)
        if (item) 
        	item->setBackgroundColor(before);
}

void BkgColorCommand::redo()
{
    foreach(QTableWidgetItem *item, affectedItems)
        if (item) 
        	item->setBackgroundColor(after);
}

FontCommand::FontCommand(UndoWidget *undoWidget, QFont beforeFont, 
		QFont afterFont, QUndoCommand *parent)
    : QUndoCommand(parent)
{
	affectedItems = undoWidget->selectedItems();
	before = beforeFont;
	after = afterFont;
	setText(QObject::tr("设置字体:")+afterFont.family());
}

void FontCommand::undo()
{
    foreach(QTableWidgetItem *item, affectedItems)
        if (item) 
        	item->setFont(before);	
}

void FontCommand::redo()
{
    foreach(QTableWidgetItem *item, affectedItems)
        if (item) 
        	item->setFont(after);
}

EditCommand::EditCommand(QTableWidgetItem *item, QString beforeText, 
		QString afterText, QUndoCommand *parent)
    : QUndoCommand(parent)
{
	affectedItem = item;
	before = beforeText;
	after = afterText;
	setText(QObject::tr("输入文字:")+after);
}

void EditCommand::undo()
{
    if (affectedItem) 
    	affectedItem->setText(before);	
}

void EditCommand::redo()
{
    if (affectedItem) 
    	affectedItem->setText(after);
}
