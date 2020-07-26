#include <QtGui>
#include <QtDebug>

#include "palette.h"
#include "penstyledelegate.h"

Palette::Palette(QWidget *parent)
	: QWidget(parent)
{
	penColorComboBox = new QComboBox;
	createColorComboBox(penColorComboBox);

	penColorLabel = new QLabel(tr("Pen Color:"));
	penColorLabel->setBuddy(penColorComboBox);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

	createStyleComboBox();

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

	brushColorComboBox = new QComboBox();
	createColorComboBox(brushColorComboBox);

	brushColorLabel = new QLabel(tr("Brush Color:"));
	brushColorLabel->setBuddy(brushColorComboBox);

    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("None"), Qt::NoBrush);
    brushStyleComboBox->addItem(tr("Solid"), Qt::SolidPattern);
    brushStyleComboBox->addItem(tr("Horizontal"), Qt::HorPattern);
    brushStyleComboBox->addItem(tr("Vertical"), Qt::VerPattern);
    brushStyleComboBox->addItem(tr("Cross"), Qt::CrossPattern);
    brushStyleComboBox->addItem(tr("Backward Diagonal"), Qt::BDiagPattern);
    brushStyleComboBox->addItem(tr("Forward Diagonal"), Qt::FDiagPattern);
    brushStyleComboBox->addItem(tr("Diagonal Cross"), Qt::DiagCrossPattern);
    brushStyleComboBox->addItem(tr("Dense 1"), Qt::Dense1Pattern);
    brushStyleComboBox->addItem(tr("Dense 2"), Qt::Dense2Pattern);
    brushStyleComboBox->addItem(tr("Dense 3"), Qt::Dense3Pattern);
    brushStyleComboBox->addItem(tr("Dense 4"), Qt::Dense4Pattern);
    brushStyleComboBox->addItem(tr("Dense 5"), Qt::Dense5Pattern);
    brushStyleComboBox->addItem(tr("Dense 6"), Qt::Dense6Pattern);
    brushStyleComboBox->addItem(tr("Dense 7"), Qt::Dense7Pattern);
    brushStyleComboBox->addItem(tr("Linear Gradient"),
            Qt::LinearGradientPattern);
    brushStyleComboBox->addItem(tr("Radial Gradient"),
            Qt::RadialGradientPattern);
    brushStyleComboBox->addItem(tr("Conical Gradient"),
            Qt::ConicalGradientPattern);
    brushStyleComboBox->addItem(tr("Texture"), Qt::TexturePattern);

    brushStyleLabel = new QLabel(tr("&Brush Style:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);

	preLabel = new PreviewLabel(this);

    connect(penColorComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(penChanged()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(penChanged()));
    connect(penStyleComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(penChanged()));
    connect(brushColorComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(brushChanged()));
    connect(brushStyleComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(brushChanged()));
	connect(this, SIGNAL(penChanged(QPen&)), preLabel, SLOT(penChanged(QPen&)));
	connect(this, SIGNAL(brushChanged(QBrush&)), preLabel, SLOT(brushChanged(QBrush&)));


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(penColorLabel, 0, 0, Qt::AlignRight);
    mainLayout->addWidget(penColorComboBox, 0, 1);
    mainLayout->addWidget(penWidthLabel, 1, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 1, 1);
    mainLayout->addWidget(penStyleLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 2, 1);
    mainLayout->addWidget(brushColorLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(brushColorComboBox, 3, 1);
    mainLayout->addWidget(brushStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 1);
    mainLayout->addWidget(preLabel, 5, 0, 6, 2);
    setLayout(mainLayout);

    penChanged();
    brushChanged();

    setWindowTitle(tr("Basic Drawing"));
}

void Palette::penChanged()
{
	QPen pen;

    int width = penWidthSpinBox->value();
	pen.setWidth(width);

    QColor color = penColorComboBox->itemData(
		penColorComboBox->currentIndex(), Qt::UserRole).value<QColor>();
	pen.setColor(color);

    Qt::PenStyle penStyle = (Qt::PenStyle)penStyleComboBox->itemData(
		penStyleComboBox->currentIndex(), Qt::UserRole).toInt();
	pen.setStyle(penStyle);

	emit penChanged(pen);
}

void Palette::brushChanged()
{
	QBrush brush;

    QColor color = brushColorComboBox->itemData(
		brushColorComboBox->currentIndex(), Qt::UserRole).value<QColor>();
	qDebug() << color;

    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(
            brushStyleComboBox->currentIndex(), Qt::UserRole).toInt());

    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        brush = linearGradient;
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        brush = radialGradient;
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        brush = conicalGradient;
    } else if (style == Qt::TexturePattern) {
        brush = QBrush(QPixmap(":/images/ellipse.png"));
    } else {
		brush.setColor(color);
		brush.setStyle(style);
    }
	qDebug() << brush;
	emit brushChanged(brush);
}

void Palette::createColorComboBox(QComboBox *comboBox)
{
    QPixmap pix(16, 16);

    QPainter pt(&pix);
    pt.fillRect(0, 0, 16, 16, Qt::black);
	comboBox->addItem(QIcon(pix), tr("black"), Qt::black);
    pt.fillRect(0, 0, 16, 16, Qt::red);
	comboBox->addItem(QIcon(pix), tr("red"), Qt::red);
    pt.fillRect(0, 0, 16, 16, Qt::green);
	comboBox->addItem(QIcon(pix), tr("green"), Qt::green);
    pt.fillRect(0, 0, 16, 16, Qt::blue);
	comboBox->addItem(QIcon(pix), tr("blue"), Qt::blue);
    pt.fillRect(0, 0, 16, 16, Qt::yellow);
	comboBox->addItem(QIcon(pix), tr("yellow"), Qt::yellow);
    pt.fillRect(0, 0, 16, 16, Qt::cyan);
	comboBox->addItem(QIcon(pix), tr("cyan"), Qt::cyan);
    pt.fillRect(0, 0, 16, 16, Qt::magenta);
	comboBox->addItem(QIcon(pix), tr("magenta"), Qt::magenta);
}

void Palette::createStyleComboBox()
{
    penStyleComboBox = new QComboBox;
	penStyleComboBox->setItemDelegate(new QPenStyleDelegate((QObject *)penStyleComboBox));
    penStyleComboBox->addItem(tr("Solid"), Qt::SolidLine);
    penStyleComboBox->addItem(tr("Dash"), Qt::DashLine);
    penStyleComboBox->addItem(tr("Dot"), Qt::DotLine);
    penStyleComboBox->addItem(tr("Dash Dot"), Qt::DashDotLine);
    penStyleComboBox->addItem(tr("Dash Dot Dot"), Qt::DashDotDotLine);
    penStyleComboBox->addItem(tr("None"), Qt::NoPen);
}
