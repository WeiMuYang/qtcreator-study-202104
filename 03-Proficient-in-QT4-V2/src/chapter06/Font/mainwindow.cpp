#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{
	fontColor = Qt::black;
	fontSize = 16;

	createActions();
	createToolBars();
	createMenus();

	updateColor();

	fontEdit = new QTextEdit();
	setCentralWidget(fontEdit);	

	resize(800,600);

	listAllFonts();
}

void MainWindow::changeFontColor()
{
    QColor color = QColorDialog::getColor(fontColor, this);
    if (color.isValid()) {
		fontColor = color;
		updateColor();
		listAllFonts();
    }
}

void MainWindow::fontSizeChanged(const QString &text)
{
	fontSize = text.toUInt();
	if(fontSize > 0)
		listAllFonts();
}

void MainWindow::createActions()
{
    fontColorAct = new QAction(QPixmap(32, 32), tr("Change Color..."), this);
    connect(fontColorAct, SIGNAL(triggered()), this, SLOT(changeFontColor()));
}

void MainWindow::createMenus()
{
    fontMenu = menuBar()->addMenu(tr("&Font"));
    fontMenu->addAction(fontColorAct);
}

void MainWindow::createToolBars()
{
    fontToolBar = addToolBar(tr("FontColor"));
    fontToolBar->addAction(fontColorAct);
	fontToolBar->addSeparator();
    QStringList fontSizes;
	fontSizes << "32" << "24" << "16" << "14" << "12" << "8" << "4" << "2";
	sizeComboBox = new QComboBox();
	sizeComboBox->setMinimumWidth(100);
	sizeComboBox->setEditable(true);
	sizeComboBox->addItems(fontSizes);
	sizeComboBox->setValidator(new QIntValidator(1, 65535, this));
	sizeComboBox->setCurrentIndex(2);
    fontToolBar->addWidget(sizeComboBox);
	connect(sizeComboBox, SIGNAL(editTextChanged(const QString&)), this, SLOT(fontSizeChanged(const QString&)));
}

void MainWindow::listAllFonts()
{
	QFont font;
	QTextCharFormat textFormat;
    QFontDatabase database;
	QTextCursor cursor;

	textFormat.setForeground(fontColor);
	fontEdit->clear();
    foreach (QString family, database.families()) {
        const QStringList styles = database.styles(family);
		foreach(QString style, styles) {
			font = QFont(family, fontSize, database.weight(family, style), database.italic(family, style));
			textFormat.setFont(font);
			cursor = fontEdit->textCursor();
	        cursor.insertText(QString("%1 %2").arg(family).arg(style), textFormat);
 			cursor.insertBlock();
		}
    }
}

void MainWindow::updateColor()
{
    QPixmap pixmap(32, 32);
    QPainter painter(&pixmap);
    painter.fillRect(0, 0, 32, 32, fontColor);

    QColor lighter = fontColor.light();
    painter.setPen(lighter);
    QPoint lightFrame[] = { QPoint(0, 31), QPoint(0, 0), QPoint(31, 0) };
    painter.drawPolyline(lightFrame, 3);

    painter.setPen(fontColor.dark());
    QPoint darkFrame[] = { QPoint(1, 31), QPoint(31, 31), QPoint(31, 1) };
    painter.drawPolyline(darkFrame, 3);

    painter.end();

    fontColorAct->setIcon(pixmap);
}
