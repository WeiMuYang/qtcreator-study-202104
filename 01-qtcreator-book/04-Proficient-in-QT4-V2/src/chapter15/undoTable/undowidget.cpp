#include <QtGui>
#include <QtDebug>

#include "undoWidget.h"
#include "commands.h"

UndoWidget::UndoWidget(QWidget * parent)
	: QTableWidget(parent)
{
	ignore = false;
	setRowCount(5);
	setColumnCount(5);
	createActions();
	populateTable();
	undoStack = new QUndoStack; 
	//itemActivated信号没有发出，故采用currentItemChanged
	/*connect(this, SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)), 
			this, SLOT(recordText(QTableWidgetItem*, QTableWidgetItem*)));*/
	connect(this, SIGNAL(itemActivated(QTableWidtet*)), this, SLOT(recordText(QTableWidget*)));
	connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(itemEdited(QTableWidgetItem*)));
}

UndoWidget::~UndoWidget()
{
}

void UndoWidget::populateTable()
{
	setItem(0, 0, new QTableWidgetItem(tr("测试")));
	setItem(0, 1, new QTableWidgetItem(tr("字体")));
	setItem(0, 2, new QTableWidgetItem(tr("test")));
}

void UndoWidget::createActions()
{
	actFrgColor = new QAction(tr("文字颜色"), this);
	connect(actFrgColor, SIGNAL(triggered()), this, SLOT(changeFrgColor()));
	
	actBkgColor = new QAction(tr("背景颜色"), this);
	connect(actBkgColor, SIGNAL(triggered()), this, SLOT(changeBkgColor()));

	actFont = new QAction(tr("字体"), this);
	connect(actFont, SIGNAL(triggered()), this, SLOT(changeFont()));
	
	addAction(actFrgColor);
	addAction(actBkgColor);
	addAction(actFont);
	setContextMenuPolicy(Qt::ActionsContextMenu);
}

void UndoWidget::changeFrgColor()
{
    QTableWidgetItem *item = currentItem();
    QColor oldColor = item ? item->textColor() : palette().base().color();
    QColor textColor = QColorDialog::getColor(oldColor, this);
    if (!textColor.isValid())
        return;

    QList<QTableWidgetItem*> selected = selectedItems();
    if (selected.count() == 0)
        return;

    foreach(QTableWidgetItem *item, selected)
        if (item) {
        	ignore = true;
        	item->setTextColor(textColor);	// deprecated, use setForeground()
        }
    undoStack->push(new TextColorCommand(this, oldColor,textColor));
}

void UndoWidget::changeBkgColor()
{
    QTableWidgetItem *item = currentItem();
    // QTableWidgetItem首次返回的背景色是黑色，导致撤消时背景是黑色
    QColor oldColor = item ? item->background().color() : palette().base().color();
    QColor bkgColor = QColorDialog::getColor(oldColor, this);
    if (!bkgColor.isValid())
        return;

    QList<QTableWidgetItem*> selected = selectedItems();
    if (selected.count() == 0)
        return;

    foreach(QTableWidgetItem *item, selected)
        if (item) { 
        	ignore = true;
        	item->setBackgroundColor(bkgColor);
        }
    undoStack->push(new BkgColorCommand(this, oldColor, bkgColor));
}

void UndoWidget::changeFont()
{
    QList<QTableWidgetItem*> selected = selectedItems();
    if (selected.count() == 0)
        return;
    bool ok = false;
    QFont oldFont = currentItem()->font();
    QFont font = QFontDialog::getFont(&ok, oldFont, this);
    if (!ok)
        return;
    foreach(QTableWidgetItem *item, selected)
        if (item) {
        	ignore = true;
        	item->setFont(font);
        }
    
    undoStack->push(new FontCommand(this, oldFont, font));
}

//void UndoWidget::recordText(QTableWidgetItem *current, QTableWidgetItem* /*previous*/)
void UndoWidget::recordText(QTableWidgetItem *current)
{
	QMessageBox::information(this, "title", "text");
	if(current)
		currentText = current->text();
	else
		currentText.clear();
}

void UndoWidget::itemEdited(QTableWidgetItem *item)
{
	if(ignore)	// 避免UndoRedo操作再次再次产生压栈命令
	{
		ignore = false;
		return;
	}
	undoStack->push(new EditCommand(item, currentText, item->text()));
}

void UndoWidget::undo()
{
	ignore = true;
	undoStack->undo();
}

void UndoWidget::redo()
{
	ignore = true;
	undoStack->redo();
}
