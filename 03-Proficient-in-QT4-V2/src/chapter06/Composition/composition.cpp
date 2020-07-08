#include <QtDebug>

#include "composition.h"

CompositionWidget::CompositionWidget(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	QStringList compositionList;
	compositionList << "Source Over" << "Destionation Over" << "Clear" << "Source" 
		<< "Destination" << "Source In" << "Destination In" << "Source Out" 
		<< "Destination Out" << "Source Atop" << "Destionation Atop" << "Xor"
		<< "Plus" << "Multiply" << "Screen" << "Overylay"
		<< "Darken" << "Lighten" << "ColorDodge" << "ColorBurn"
		<< "HardLight" << "SoftLight" << "Difference" << "Exclusion";
	list = new QListWidget;
	list->addItems( compositionList );
	canvas = new CompositionCanvas;
	
	aLabel = new QLabel(tr("<b>Alpha:</b>"));
	rLabel = new QLabel(tr("<b>Red:</b>"));
	gLabel = new QLabel(tr("<b>Green:</b>"));
	bLabel = new QLabel(tr("<b>Blue:</b>"));
	
	aSlider = new QSlider;
	aSlider->setOrientation(Qt::Horizontal);
	aSlider->setMinimum(0);
	aSlider->setMaximum(255);
	aSlider->setValue(255);
	
	rSlider = new QSlider;
	rSlider->setOrientation(Qt::Horizontal);
	rSlider->setMinimum(0);
	rSlider->setMaximum(255);
	rSlider->setValue(255);
	
	gSlider = new QSlider;
	gSlider->setOrientation(Qt::Horizontal);
	gSlider->setMinimum(0);
	gSlider->setMaximum(255);
	gSlider->setValue(0);
	
	bSlider = new QSlider;
	bSlider->setOrientation(Qt::Horizontal);
	bSlider->setMinimum(0);
	bSlider->setMaximum(255);
	bSlider->setValue(0);
	
	gridLayout = new QGridLayout;
	gridLayout->addWidget(aLabel, 0, 0);
	gridLayout->addWidget(aSlider, 0, 1);
	gridLayout->addWidget(rLabel, 1, 0);
	gridLayout->addWidget(rSlider, 1, 1);
	gridLayout->addWidget(gLabel, 2, 0);
	gridLayout->addWidget(gSlider, 2, 1);
	gridLayout->addWidget(bLabel, 3, 0);
	gridLayout->addWidget(bSlider, 3, 1);
	gridLayout->addWidget(list, 4, 0, 15, 2);

	hLayout = new QHBoxLayout;
	hLayout->addWidget(canvas);
	hLayout->addLayout(gridLayout);
	setLayout(hLayout);
	resize(1024, 768);
	
	connect(list, SIGNAL(currentRowChanged(int)), canvas, SLOT(compositeModeChanged(int)));
	connect(aSlider, SIGNAL(valueChanged(int)), canvas, SLOT(alphaChanged(int)));
	connect(rSlider, SIGNAL(valueChanged(int)), canvas, SLOT(redChanged(int)));
	connect(gSlider, SIGNAL(valueChanged(int)), canvas, SLOT(greenChanged(int)));
	connect(bSlider, SIGNAL(valueChanged(int)), canvas, SLOT(blueChanged(int)));
}

/**
 *  »æÖÆÇøÓò.
 */
CompositionCanvas::CompositionCanvas(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	pos.setX(400);
	pos.setY(550);
	setMinimumSize(700,700);
	srcImage = QImage(1000,1000, QImage::Format_ARGB32_Premultiplied);
	resultImage = QImage(1000,1000, QImage::Format_ARGB32_Premultiplied);
	srcImage.load("build.jpg");
	dstImage = QImage(100,100, QImage::Format_ARGB32_Premultiplied);
	currentMode = QPainter::CompositionMode_SourceOver;
	color = QColor(255,0,0,255);
}

void CompositionCanvas::paintEvent(QPaintEvent *event)
{
	QPainter painter(&resultImage);
	painter.fillRect(resultImage.rect(), Qt::transparent);
	painter.drawImage(0, 0, srcImage);
	painter.setCompositionMode(currentMode);
	dstImage.fill(color.rgb());
	painter.drawImage(pos, dstImage);
	
	QPainter p(this);
	p.drawImage(0,0,resultImage);
}

void CompositionCanvas::compositeModeChanged(int currentRow)
{
	currentMode = (QPainter::CompositionMode)currentRow;
	update();
}

void CompositionCanvas::alphaChanged(int value)
{
	color.setAlpha(value);
	update();
}

void CompositionCanvas::redChanged(int value)
{
	color.setRed(value);
	update();
}

void CompositionCanvas::greenChanged(int value)
{
	color.setGreen(value);
	update();
}

void CompositionCanvas::blueChanged(int value)
{
	color.setBlue(value);
	update();
}

void CompositionCanvas::mousePressEvent(QMouseEvent *event)
{
	pos = event->pos();
	update();
}

void CompositionCanvas::mouseMoveEvent(QMouseEvent *event)
{
}


