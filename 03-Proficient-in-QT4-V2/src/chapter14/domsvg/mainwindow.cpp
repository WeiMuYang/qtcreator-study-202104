#include <QtGui>

#include "drawwidget.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
	drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"));

    setWindowTitle(tr("DOM SVG render"));
    resize(1024, 768);
	open();
}

void MainWindow::open()
{
/*    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Simple svg File"),
                                         QDir::currentPath(),
                                         tr("svg Files (*.svg)"));*/
 	QString fileName = "test.svg";
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("DOM SVG Render"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

	drawWidget->readSvg(fileName);
    statusBar()->showMessage(fileName + tr("File loaded"));
}

void MainWindow::saveAs()
{
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
