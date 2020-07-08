#include <QtGui>

#include "score.h"
#include "mysortfilterproxymodel.h"

Score::Score(QWidget * parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
    setupUi(this);   
    populateTable();
    connect(btnFilter, SIGNAL(clicked(bool)), this, SLOT(setFilter()));

    proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setDynamicSortFilter(true);
    
    proxyModel->setSourceModel(model);
    tableView->setAlternatingRowColors(true);
    tableView->setModel(proxyModel);
    setFilter();
}

Score::~Score()
{
}

void Score::populateTable()
{
    model = new QStandardItemModel(3, 4, this);

    model->setHeaderData(0, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(1, Qt::Horizontal, tr("语文"));
    model->setHeaderData(2, Qt::Horizontal, tr("数学"));
    model->setHeaderData(3, Qt::Horizontal, tr("英语"));

    model->setData(model->index(0, 0), tr("李逵"));
    model->setData(model->index(0, 1), 65);
    model->setData(model->index(0, 2), 68);
    model->setData(model->index(0, 3), 70);

    model->setData(model->index(1, 0), tr("武松"));
    model->setData(model->index(1, 1), 70);
    model->setData(model->index(1, 2), 75);
    model->setData(model->index(1, 3), 83);

    model->setData(model->index(2, 0), tr("宋江"));
    model->setData(model->index(2, 1), 88);
    model->setData(model->index(2, 2), 90);
    model->setData(model->index(2, 3), 93);
}

void Score::setFilter()
{
	proxyModel->setMinChinese(spinChineseFrom->value());
	proxyModel->setMaxChinese(spinChineseTo->value());
	proxyModel->setMinMath(spinMathFrom->value());
	proxyModel->setMaxMath(spinMathTo->value());
	proxyModel->setMinEnglish(spinEnglishFrom->value());
	proxyModel->setMaxEnglish(spinEnglishTo->value());
	tableView->update();	// 如果不update()，表格的列标题将显示混乱
}

