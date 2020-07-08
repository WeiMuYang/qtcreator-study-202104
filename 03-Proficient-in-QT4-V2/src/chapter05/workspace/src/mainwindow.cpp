#include <QtGui>
#include <QDebug>
#include <QtCore>

#include "mainwindow.h"
#include "findfileform.h"
#include "mditextedit.h"

CMainWindow::CMainWindow(QWidget* parent)
 :	QMainWindow(parent)
{
	setupUi(this);
	
	workspace = new QWorkspace;
	setCentralWidget(workspace);
	connect(workspace, SIGNAL(windowActivated(QWidget *)),
             this, SLOT(updateMenu()));

//      mapper = new QSignalMapper(this);
//      connect(mapper, SIGNAL(mapped(QWidget *)),
//              workspace, SLOT(setActiveWindow(QWidget *)));
	
	iniDockWidget();
	iniStatusBar();
	iniConnect();	
	updateRecentFiles();
	updateMenu();
	
	showMaximized();
	showCount(0);
	
}

void CMainWindow::iniDockWidget()
{
	CFindFileForm* findFileForm = new CFindFileForm;
	dockWidget = new QDockWidget(tr("查找文件"), this);
	dockWidget->setAllowedAreas(Qt::RightDockWidgetArea);
	dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
	dockWidget->setFloating(false);
	dockWidget->setWidget(findFileForm);
	dockWidget->setVisible(false);
	
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
	connect(actNew, SIGNAL(triggered()), this, SLOT(doNew()));
	connect(actOpen, SIGNAL(triggered()), this, SLOT(doOpen()));
	connect(actClose, SIGNAL(triggered()), this, SLOT(doClose()));
	connect(actSave, SIGNAL(triggered()), this, SLOT(doSave()));
	connect(actASave, SIGNAL(triggered()), this, SLOT(doASave()));
	connect(actQuit, SIGNAL(triggered()), this, SLOT(doQuit()));
	connect(actUndo, SIGNAL(triggered()), this, SLOT(doUndo()));
	connect(actCut, SIGNAL(triggered()), this, SLOT(doCut()));
	connect(actCopy, SIGNAL(triggered()), this, SLOT(doCopy()));
	connect(actPaste, SIGNAL(triggered()), this, SLOT(doPast()));
	connect(actAll, SIGNAL(triggered()), this, SLOT(doAll()));
	connect(actFind, SIGNAL(triggered()), this, SLOT(doFind()));
	
	separatorAct = menu_F->insertSeparator(actQuit);
	separatorAct->setVisible(false);
	for (int i = 0; i < 9; ++i) 
	{
         recentFileActs[i] = new QAction(this);
		 menu_F->insertAction(separatorAct, recentFileActs[i]);
         recentFileActs[i]->setVisible(false);
         connect(recentFileActs[i], SIGNAL(triggered()),
                 this, SLOT(openRecentFile()));
     }
}


void CMainWindow::doFind()
{
	dockWidget->show();
	dockWidget->setFloating(false);
}


void CMainWindow::doNew()
{
	static int sequenceNum = 1;
	CMDITextEdit* textEdit 
		= createMDITextEdit(true, tr("untitled%1").arg(sequenceNum++));
	textEdit->setVisible(true);

}


void CMainWindow::doOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty()) 
	{		
		QWidgetList list = workspace->windowList();
		for(int i=0; i<list.count(); i++)
		{
			CMDITextEdit* textEdit = 
				qobject_cast<CMDITextEdit*>(list[i]);
			if(textEdit->fileName() == fileName)
			{
				workspace->setActiveWindow(textEdit);
				return ;
			}
		}

		CMDITextEdit* textEdit 
			= createMDITextEdit(false, fileName);
		if (textEdit->loadFile(fileName)) 
		{			
			label2->setText(tr("已经读取"));
		}
		textEdit->setVisible(true);
	}	
}


void CMainWindow::doClose()
{
	activeWindow()->close();	
}


void CMainWindow::doSave()
{
	activeWindow()->save();
}

void CMainWindow::doASave()
{
	activeWindow()->saveAs();	 
}

void CMainWindow::doQuit()
{
	QWidgetList list = workspace->windowList();
	for(int i=0; i<list.count(); i++)
	{
		CMDITextEdit* textEdit = 
			qobject_cast<CMDITextEdit*>(list[i]);
		textEdit->close();
	}
	qApp->quit();
}


void CMainWindow::doUndo()
{
	activeWindow()->undo();
}
void CMainWindow::doCut()
{
	activeWindow()->cut();
}
void CMainWindow::doCopy()
{
	activeWindow()->copy();
}
void CMainWindow::doPast()
{
	activeWindow()->paste();
}
void CMainWindow::doAll()
{
	activeWindow()->selectAll();
}

void CMainWindow::openRecentFile()
{
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
	{
		QString fileName = action->data().toString();
		CMDITextEdit* textEdit 
			= createMDITextEdit(false, fileName);
		textEdit->loadFile(fileName);	
		textEdit->setVisible(true);	
	}
}


void CMainWindow::updateRecentFiles()
{
	QSettings settings("709", "MDI example");
	QStringList files = settings.value("recentFiles").toStringList();

	int numRecentFiles = qMin(files.size(), (int)9);
	for (int i = 0; i < numRecentFiles; ++i) 
	{
		QString text = tr("&%1 %2").arg(i + 1).arg(files[i]);
		recentFileActs[i]->setText(text);
		recentFileActs[i]->setData(files[i]);
		recentFileActs[i]->setVisible(true);
	}
	for (int i = numRecentFiles; i < 9; ++i)
		recentFileActs[i]->setVisible(false);

	separatorAct->setVisible(numRecentFiles > 0);
}

CMDITextEdit* CMainWindow::activeWindow ()
{
	CMDITextEdit* textEdit 
		= qobject_cast<CMDITextEdit*>(workspace->activeWindow());
	return textEdit;	
}


void CMainWindow::updateMenu()
{
	bool hasChild = (activeWindow() != 0);
	actSave->setEnabled(hasChild);
	actASave->setEnabled(hasChild);
	actPaste->setEnabled(hasChild);
	actClose->setEnabled(hasChild);
	actUndo->setEnabled(hasChild);
	actCut->setEnabled(hasChild);
	
	bool selected = (activeWindow() 
		&& activeWindow()->textCursor().hasSelection());
	actCut->setEnabled(selected);
	actCopy->setEnabled(selected);
}


CMDITextEdit* CMainWindow::createMDITextEdit(bool untitled, const QString& fileName)
{
	CMDITextEdit* textEdit 
		= new CMDITextEdit(untitled, fileName);
	workspace->addWindow(textEdit);	
	connect(textEdit, SIGNAL(updateRecentFiels()), 
		this, SLOT(updateRecentFiles()));
	connect(textEdit, SIGNAL(copyAvailable(bool)),
		actCut, SLOT(setEnabled(bool)));
	connect(textEdit, SIGNAL(copyAvailable(bool)),
		actCopy, SLOT(setEnabled(bool)));
	connect(textEdit, SIGNAL(counted(int)), 
		this, SLOT(showCount(int)));
		
	showCount(++textEdit->count);
	return textEdit;
}

void CMainWindow::showCount(int count)
{
	label1->setText(tr("文档总数：%1").arg(count));
}
