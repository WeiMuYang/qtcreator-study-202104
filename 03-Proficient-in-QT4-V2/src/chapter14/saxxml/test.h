/********************************************************************************
** Form generated from reading ui file 'test.ui'
**
** Created: Mon May 7 19:55:02 2007
**      by: Qt User Interface Compiler version 4.2.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QToolButton>

class Ui_czm
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QRadioButton *radioButton;
    QCheckBox *checkBox;

    void setupUi(QDialog *czm)
    {
    czm->setObjectName(QString::fromUtf8("czm"));
    buttonBox = new QDialogButtonBox(czm);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(30, 240, 341, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);
    pushButton = new QPushButton(czm);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(70, 60, 75, 25));
    toolButton = new QToolButton(czm);
    toolButton->setObjectName(QString::fromUtf8("toolButton"));
    toolButton->setGeometry(QRect(220, 60, 25, 24));
    radioButton = new QRadioButton(czm);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));
    radioButton->setGeometry(QRect(110, 120, 85, 21));
    checkBox = new QCheckBox(czm);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));
    checkBox->setGeometry(QRect(250, 120, 73, 20));

    retranslateUi(czm);

    QSize size(400, 300);
    size = size.expandedTo(czm->minimumSizeHint());
    czm->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), czm, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), czm, SLOT(reject()));

    QMetaObject::connectSlotsByName(czm);
    } // setupUi

    void retranslateUi(QDialog *czm)
    {
    czm->setWindowTitle(QApplication::translate("czm", "Dialog", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("czm", "PushButton", 0, QApplication::UnicodeUTF8));
    toolButton->setText(QApplication::translate("czm", "...", 0, QApplication::UnicodeUTF8));
    radioButton->setText(QApplication::translate("czm", "RadioButton", 0, QApplication::UnicodeUTF8));
    checkBox->setText(QApplication::translate("czm", "CheckBox", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(czm);
    } // retranslateUi

};

namespace Ui {
    class czm: public Ui_czm {};
} // namespace Ui

#endif // UI_TEST_H
