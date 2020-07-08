#include <QtGui>

#include "mysortfilterproxymodel.h"

MySortFilterProxyModel::MySortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

void MySortFilterProxyModel::setMinChinese(const int chinese)
{
    minChinese = chinese;
    invalidateFilter();
}

void MySortFilterProxyModel::setMaxChinese(const int chinese)
{
    maxChinese = chinese;
    invalidateFilter();
}

void MySortFilterProxyModel::setMinMath(const int math)
{
    minMath = math;
    invalidateFilter();
}

void MySortFilterProxyModel::setMaxMath(const int math)
{
    maxMath = math;
    invalidateFilter();
}

void MySortFilterProxyModel::setMinEnglish(const int english)
{
    minEnglish = english;
    invalidateFilter();
}

void MySortFilterProxyModel::setMaxEnglish(const int english)
{
    maxEnglish = english;
    invalidateFilter();
}

bool MySortFilterProxyModel::filterAcceptsRow(int sourceRow,
        const QModelIndex &sourceParent) const
{
    QModelIndex indexChinese = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex indexMath = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex indexEnglish = sourceModel()->index(sourceRow, 3, sourceParent);

    int chinese = sourceModel()->data(indexChinese).toInt();
    if(chinese < minChinese || chinese > maxChinese)
    	return false;
    int math = sourceModel()->data(indexMath).toInt();
    if(math < minMath || math > maxMath)
    	return false;
    int english = sourceModel()->data(indexEnglish).toInt();
    if(english < minEnglish || english > maxEnglish)
    	return false;

    return true;
}