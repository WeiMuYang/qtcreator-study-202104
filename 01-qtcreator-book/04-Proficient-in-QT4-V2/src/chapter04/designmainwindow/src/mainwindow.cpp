#include <QtGui>

#include "mainwindow.h"
#include "findfileform.h"
CMainWindow::CMainWindow(QWidget* parent)
 :	QMainWindow(parent)
{
	setupUi(this);
	
	iniDockWidget();
	iniStatusBar();
	iniConnect();
	updateRecentFiles();
	showMaximized();
	
	isUntitled = true;
	curFile = tr("untitled");
	setWindowTitle(curFile + "[*]");	
}

void CMainWindow::iniDockWidget()
{
	CFindFileForm* findFileForm = new CFindFileForm;
	dockWidget = new QDockWidget(tr("查找文件"), this);
	dockWidget->setAllowedAreas(Qt::RightDockWidgetArea);
	dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
	dockWidget->setFloating(false);
	dockWidget->setWidget(findFileForm);
	dockWidget->setVisible(true);
	
	addDockWidget(Qt::RightDockWidgetArea, dockWidget);
}

void CMainWindow::iniStatusBar()
{
	QStatusBar* bar = statusBar();
	label1 = new QLabel;
	label1->setMinimumSize(200, 25);
	label1->setFrameShadow(QFrame::Sunken);
	label1->setFrameShape(QFrame::WinPanel);
	label2 = new QLabel;	
	label2->setMinimumSize(200, 25);
	label2->setFrameShadow(QFrame::Sunken);
	label2->setFrameShape(QFrame::WinPanel);
	bar->addWidget(label1);
	bar->addWidget(label2);
}

void CMainWindow::iniConnect()
{
	connect(textEdit, SIGNAL(cursorPositionChanged()), 
		this, SLOT(doCursorChanged()));
	connect(actNew, SIGNAL(triggered()), 
		this, SLOT(doNew()));
	connect(actOpen, SIGNAL(triggered()), 
		this, SLOT(doOpen()));
	connect(actClose, SIGNAL(triggered()), 
		this, SLOT(doClose()));
	connect(actSave, SIGNAL(triggered()), 
		this, SLOT(doSave()));
	connect(actASave, SIGNAL(triggered()), 
		this, SLOT(doASave()));
	connect(actQuit, SIGNAL(triggered()),
		this, SLOT(doQuit()));
	connect(actUndo, SIGNAL(triggered()), 
		this, SLOT(doUndo()));
	connect(actCut, SIGNAL(triggered()), 
		this, SLOT(doCut()));
	connect(actCopy, SIGNAL(triggered()), 
		this, SLOT(doCopy()));
	connect(actPaste, SIGNAL(triggered()), 
		this, SLOT(doPast()));
	connect(actAll, SIGNAL(triggered()), 
		this, SLOT(doAll()));
	connect(actFind, SIGNAL(triggered()), 
		this, SLOT(doFind()));
	connect(textEdit->document(), SIGNAL(contentsChanged()), 
		this, SLOT(doModified()));
	separatorAct = menu_F->insertSeparator(actQuit);
	separatorAct->setVisible(false);
	for (int i = 0; i < MaxRecentFiles; ++i) 
	{
         recentFileActs[i] = new QAction(this);
		 menu_F->insertAction(separatorAct, recentFileActs[i]);
         recentFileActs[i]->setVisible(false);
         connect(recentFileActs[i], SIGNAL(triggered()),
                 this, SLOT(openRecentFile()));
     }	 
	 
	actPrint = menu_T->addAction(tr("打印文档"));
	connect(actPrint, SIGNAL(triggered()), this, SLOT(doPrint()));
}

void CMainWindow::doCursorChanged()
{
	int pageNum = textEdit->document()->pageCount();
	const QTextCursor cursor = textEdit->textCursor();
	int colNum = cursor.columnNumber();
	int rowNum = textEdit->document()->blockCount();	
	label1->setText(tr("%1 页	%3 列").arg(pageNum).arg(colNum));
}

void CMainWindow::doFind()
{
	dockWidget->show();
	dockWidget->setFloating(false);
}

//////////////////////////////////////////////////////////////////
//单文档实现。
void CMainWindow::doNew()
{
	maybeSave();
	isUntitled = true;
	curFile = tr("untitled");
	setWindowTitle(curFile + "[*]");	
	textEdit->clear();	
	textEdit->setVisible(true);
	setWindowModified(false);
}

//////////////////////////////////////////////////////////////////
//多文档实现。
// void CMainWindow::doNew()
// {
// 	CMainWindow* mainWindow = new CMainWindow;
// 	mainWindow->setVisible(true);
// }

void CMainWindow::maybeSave()
{
	if(textEdit->document()->isModified())
	{
		QMessageBox box;
		box.setWindowTitle(tr("警告"));		
		box.setIcon(QMessageBox::Warning);
		box.setText(tr("文档没有保存，是否保存？"));
		box.setStandardButtons(QMessageBox::Yes 
								| QMessageBox::No);
		if(box.exec() == QMessageBox::Yes)
		{
			doSave();
		}
	}
}

void CMainWindow::doOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty()) 
	{		
		maybeSave();
		if (loadFile(fileName)) 
		{			
			label2->setText(tr("已经读取"));
		}
	}	
	textEdit->setVisible(true);	
}
bool CMainWindow::loadFile(const QString& fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, tr("读取文件"),
							tr("无法读取文件 %1:\n%2.")
							.arg(fileName)
							.arg(file.errorString()));
		return false;
	}
	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	textEdit->setText(in.readAll());
	QApplication::restoreOverrideCursor();
	setCurrentFile(fileName);

	return true;
}

//////////////////////////////////////////////////////////////////
//单文档实现。
void CMainWindow::setCurrentFile(const QString& fileName)
{
	curFile = QFileInfo(fileName).canonicalFilePath();
	isUntitled = false;
	setWindowTitle(curFile + "[*]");	
	textEdit->document()->setModified(false);
	setWindowModified(false);
	
	QSettings settings("709", "SDI example");
	QStringList files = settings.value("recentFiles").toStringList();
	files.removeAll(fileName);
	files.prepend(fileName);
	while (files.size() > MaxRecentFiles)
		files.removeLast();
	settings.setValue("recentFiles", files);

	updateRecentFiles();
}

////////////////////////////////////////////////////////////////////
// 多文档实现。
// void CMainWindow::setCurrentFile(const QString& fileName)
// {
// 	curFile = QFileInfo(fileName).canonicalFilePath();
// 	isUntitled = false;
// 	setWindowTitle(curFile + "[*]");
// 	textEdit->document()->setModified(false);
//	setWindowModified(false);
// 	
// 	QSettings settings("709", "SDI example");
// 	QStringList files = settings.value("recentFiles").toStringList();
// 	files.removeAll(fileName);
// 	files.prepend(fileName);
// 	while (files.size() > MaxRecentFiles)
// 		files.removeLast();
// 	settings.setValue("recentFiles", files);
// 
// 	foreach (QWidget *widget, QApplication::topLevelWidgets()) 
// 	{
// 		CMainWindow *mainWindow = qobject_cast<CMainWindow *>(widget);
// 		if (mainWindow)
// 			mainWindow->updateRecentFiles();
// 	}
// }

void CMainWindow::updateRecentFiles()
{
	QSettings settings("709", "SDI example");
	QStringList files = settings.value("recentFiles").toStringList();

	int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);
	for (int i = 0; i < numRecentFiles; ++i) 
	{
		QString text = tr("&%1 %2").arg(i + 1).arg(files[i]);
		recentFileActs[i]->setText(text);
		recentFileActs[i]->setData(files[i]);
		recentFileActs[i]->setVisible(true);
	}
	for (int i = numRecentFiles; i < MaxRecentFiles; ++i)
		recentFileActs[i]->setVisible(false);

	separatorAct->setVisible(numRecentFiles > 0);
}
void CMainWindow::doClose()
{
	maybeSave();
	textEdit->setVisible(false);
}

void CMainWindow::doSave()
{
	if (isUntitled) 
	{
         doASave();
     } else 
	 {
         saveFile(curFile);
     }
}
void CMainWindow::doASave()
{
	QString fileName = 
		QFileDialog::getSaveFileName(this, tr("另存为"), curFile);
     if (!fileName.isEmpty())
	 {
		saveFile(fileName);	 
	 }
}
void CMainWindow::doQuit()
{
	doClose();
	qApp->quit();
}

void CMainWindow::doUndo()
{
	textEdit->undo();
}

void CMainWindow::doCut()
{
	textEdit->cut();
}

void CMainWindow::doCopy()
{
	textEdit->copy();
}


void CMainWindow::doPast()
{
	textEdit->paste();
}

void CMainWindow::doAll()
{
	textEdit->selectAll();
}

bool CMainWindow::saveFile(const QString& fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, 
							tr("保存文件"),
							tr("无法保存文件 %1:\n%2.")
							.arg(fileName)
							.arg(file.errorString()));
		return false;
	}

	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out << textEdit->toPlainText();
	QApplication::restoreOverrideCursor();
	setCurrentFile(fileName);	
	label2->setText(tr("已经保存"));
	
	return true;
}

void CMainWindow::doModified()
{
	setWindowModified(textEdit->document()->isModified());
	label2->setText(tr("正在修改"));
}


void CMainWindow::openRecentFile()
{
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
		loadFile(action->data().toString());

}

void CMainWindow::doPrint()
{
	QTextDocument *document = textEdit->document();
	QPrinter printer;

	QPrintDialog dlg(&printer, this);
	dlg.setWindowTitle(tr("打印文档"));
	if (dlg.exec() != QDialog::Accepted)
		return;

	document->print(&printer);
}



