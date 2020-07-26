#include <QtGui>

#include "mainwindow.h"
#include "uihandler.h"

MainWindow::MainWindow()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(14);

	textEdit = new QTextEdit;
	textEdit->setFont(font);
    setCentralWidget(textEdit);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"));

    setWindowTitle(tr("SAX UI parser"));
    resize(800, 600);
	highlighter = new Highlighter(textEdit->document());
// 	open();
}

void MainWindow::open()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Qt 4 UI File"),
                                         QDir::currentPath(),
                                         tr("UI Files (*.ui)"));
// 	QString fileName = "test.ui";
    if (fileName.isEmpty())
        return;

    textEdit->clear();

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SAX UI Process"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QXmlInputSource xmlInputSource(&file);

	int index = fileName.lastIndexOf("/");
	if(index > 0)
    	fileName =  fileName.mid(index + 1);
    UiHandler handler(textEdit, fileName);
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);

    if (reader.parse(xmlInputSource))
        statusBar()->showMessage(fileName + tr("File loaded"));
}

void MainWindow::saveAs()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Save .h File"),
                                         QDir::currentPath(),
                                         tr("C++ header file (*.h)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
        statusBar()->showMessage(fileName + tr("File saved"), 2000);
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About SAX UI Parser"),
            tr("The <b>SAX UI Parser</b>."));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAsAct = new QAction(tr("&Save As..."), this);
    saveAsAct->setShortcut(tr("Ctrl+S"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(exitAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}
