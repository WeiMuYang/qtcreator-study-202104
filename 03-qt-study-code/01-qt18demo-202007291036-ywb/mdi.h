#ifndef MDI_H
#define MDI_H

#include <QMainWindow>
#include "settingconfig.h"

#include <QDebug>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QMetaEnum>
#include <QScreen>
enum area{
    A=0,B1,B2,B3,B4,B5,B6,C,D,S,Null
};

namespace Ui {
class Mdi;
}

class Mdi : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mdi(QWidget *parent = 0);
    ~Mdi();
    void MdiInit();
    void tableClear();
    void tableShow(area selectArea);
    void loadTable();
    void setUnableSelect(area Select);
    void tableSave();
    bool hasRead;
    QString hasPath;
    SettingConfig MdiConfig;
    //void setlabel;
private slots:
    void save();
    void saveAs();
    void openConfig();
    void newConfig();
    void changeShowTable();
    void on_actionNew_triggered();

private:
    Ui::Mdi *ui;
    area lastArea;
};

#endif // MDI_H
