#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class MySortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MySortFilterProxyModel(QObject *parent = 0);

    void setMinChinese(const int chinese);
    void setMaxChinese(const int chinese);

    void setMinMath(const int math);
    void setMaxMath(const int math);

    void setMinEnglish(const int english);
    void setMaxEnglish(const int english);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
    int minChinese;
    int maxChinese;
    int minMath;
    int maxMath;
    int minEnglish;
    int maxEnglish;
};

#endif
