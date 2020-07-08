#include <QtGui>

#include "mapwidget.h"
#include "mapdelegate.h"

MapWidget::MapWidget(QWidget *parent)
    : QWidget(parent)
{
    populateModel();

    companyLabel = new QLabel(tr("公司"));
    typeLabel = new QLabel(tr("车型"));
    displacementLabel = new QLabel(tr("排量"));
    nationLabel = new QLabel(tr("原产国"));

    companyCombo = new QComboBox;
    companyCombo->addItems(companies);
    typeEdit = new QLineEdit;
    displacementSpin = new QDoubleSpinBox;
    displacementSpin->setSingleStep(0.1);
    flagLabel = new QLabel;

    btnNext = new QPushButton(tr("下一条"));
    btnPrev = new QPushButton(tr("前一条"));
    btnSubmit = new QPushButton(tr("提交"));
    btnRevert = new QPushButton(tr("放弃"));

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(model);
    mapper->addMapping(companyCombo, 0);
    mapper->addMapping(typeEdit, 1);
    mapper->addMapping(displacementSpin, 2);
    QByteArray property("pixmap");
    mapper->addMapping(flagLabel, 3, property);
    MapDelegate *delegate = new MapDelegate(this);
    mapper->setItemDelegate(delegate);
    
    connect(btnPrev, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(btnNext, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(btnSubmit, SIGNAL(clicked()), mapper, SLOT(submit()));
    connect(btnRevert, SIGNAL(clicked()), mapper, SLOT(revert()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUI(int)));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(companyLabel, 0, 0);
    layout->addWidget(companyCombo, 0, 1, 1, 2);
    layout->addWidget(typeLabel, 1, 0);
    layout->addWidget(typeEdit, 1, 1, 1, 2);
    layout->addWidget(displacementLabel, 2, 0);
    layout->addWidget(displacementSpin, 2, 1, 1, 2);
    layout->addWidget(nationLabel, 3, 0);    
    layout->addWidget(flagLabel, 3, 1, 1, 2);

    layout->addWidget(btnPrev, 4, 0);
    layout->addWidget(btnNext, 4, 1);
    layout->addWidget(btnSubmit, 4, 2);
    layout->addWidget(btnRevert, 4, 3);
    setLayout(layout);

    leftShortCut = new QShortcut(QKeySequence::MoveToNextLine, this, SLOT(toNext()));
    rightShortCut = new QShortcut(QKeySequence::MoveToPreviousLine, this ,SLOT(toPrevious()));
    
    setWindowTitle(tr("数据映射"));
    mapper->toFirst();
}

void MapWidget::populateModel()
{
    model = new QStandardItemModel(7, 4, this);

    companies << tr("奇瑞") << tr("标致雪铁龙") << tr("福特") << tr("本田") 
    		  << tr("大众") << tr("现代") << tr("菲亚特"); 

    QStringList types;
    types << tr("旗云") << tr("标致307") << tr("福克斯") << tr("思域") 
    	  << tr("宝来") << tr("伊兰特") << tr("西耶那");

    QList<qreal> displacements;
    displacements << 1.3 << 2.0 << 2.0 << 1.6 << 1.8 << 1.6 << 1.5;
    
    QList<QPixmap> flags;
    flags << QPixmap(":images/china.png")  << QPixmap(":images/france.png") << QPixmap(":images/usa.png")
    	<< QPixmap(":images/japan.png") << QPixmap(":images/germany.png") << QPixmap(":images/korea.png") 
    	<< QPixmap(":images/italy.png");
    
    QStandardItem *item;
    for (int row = 0; row < 7; ++row) {
      item = new QStandardItem(companies[row]);
      model->setItem(row, 0, item);
      item = new QStandardItem(types[row]);
      model->setItem(row, 1, item);
      model->setData(model->index(row, 2, QModelIndex()), displacements[row]);
      model->setData(model->index(row, 3, QModelIndex()), flags[row]);
    }
}

void MapWidget::updateUI(int row)
{
    btnPrev->setEnabled(row > 0);
    btnNext->setEnabled(row < model->rowCount() - 1);
}
