#include <QtGui>
#include "DirWidget.h"

DirWidget::DirWidget()
{	
	model = new QDirModel;
	tree = new QTreeView;
	tree->setModel(model);
	index = model->index(QDir::currentPath());
	tree->expand(index);
	tree->scrollTo(index);
	tree->header()->setResizeMode(QHeaderView::ResizeToContents);
	
    completer = new QCompleter(this);
    completer->setModel(model);
	dirEdit = new QLineEdit;
	dirEdit->setText(QDir::currentPath());
    dirEdit->setCompleter(completer);
	connect(dirEdit, SIGNAL(editingFinished()), this, SLOT(pathChanged())); 

	layout = new QVBoxLayout;
	layout->addWidget(tree);
	layout->addWidget(dirEdit);
	setLayout(layout);

    resize(640, 480);
    setWindowTitle(QObject::tr("Ä¿Â¼ä¯ÀÀ"));
}

DirWidget::~DirWidget()
{
}

void DirWidget::pathChanged()
{
	index = model->index(dirEdit->text());
	tree->expand(index);
	tree->scrollTo(index);	
}
