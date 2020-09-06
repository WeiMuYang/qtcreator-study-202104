#ifndef WELLSDATA_H
#define WELLSDATA_H
#include <QVector>
#include <QLabel>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

class WellsData
{
public:
    WellsData();
    QVector <QLabel *> m_LabelOfWell_22;            // 井的标签，22个
    QVector <QTableWidget *> m_TableOfWell_2;       // 井的表，2个
    int m_Pattern;      // 模式，  0：测试    1：作战

    QString m_WellNum;  // 阵地编号

    QVector <QLineEdit *> m_DetailTextLineOfWell_3;// 井详细信息的00区域的text
    QVector <QPushButton *> m_DetailPushButtonOfWell_3; // 井详细信息的10区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_00; // 井详细信息的00区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_01; // 井详细信息的01区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_02; // 井详细信息的02区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_03; // 井详细信息的03区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_04; // 井详细信息的04区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_05; // 井详细信息的05区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_06; // 井详细信息的06区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_07; // 井详细信息的07区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_08; // 井详细信息的08区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_09; // 井详细信息的09区域的标签
    QVector <QLabel *> m_DetailLabelOfWell_10; // 井详细信息的10区域的标签
    QVector <QTableWidget *> m_DetailTableOfWell_2;  // 井详细信息的两个Table
};

#endif // WELLSDATA_H
