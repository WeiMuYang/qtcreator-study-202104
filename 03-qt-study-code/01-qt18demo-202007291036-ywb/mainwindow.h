#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include "wellsdata.h"
#include "changesyncstatus.h"
#include "mdi.h"
#include "settingconfig.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void magicTime();
    // 将对应控装入容器
    void mainWindowInit();
    // 对控件进行初始化赋值
    //  void mainWindowAssign();
    // 起始运行状态
    void PreProcess();
    void Process1();
    // 由按钮C2触发，或者通过指令
    void Process2();
    // 由按钮C3触发，或者通过指令
    void Process3();
    // 通过指令
    void Process4();

    void MySleep(double sec); // 延迟sec秒
    void mainWindowAssignNull();
    void mainWindowAssignText();
    QString getTimeNowMDHMS();
    QString getTimeNowHMS();
    void Pause();
    void settingMenu();
    void CheckPattern();

public slots:

    void on_pushButton_12_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_110002_clicked();
    void on_pushButton_110003_clicked();
    void getWell_11Pattern();
    void getWell_12Pattern();
    void getWell_21Pattern();
    void getWell_22Pattern();
    void getWell_31Pattern();
    void getWell_32Pattern();
    void getWell_41Pattern();
    void getWell_42Pattern();
    void getWell_51Pattern();
    void getWell_52Pattern();
    void getWell_61Pattern();
    void refresh();
    void getWell_62Pattern();
    void Start();
    void OPenMdi();


private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_110001_clicked();

private:
    Ui::MainWindow *ui;
    bool m_state;
    QScrollArea *m_ScrollArea;          // 打算装进度条
    QStackedLayout * m_pStackedLayout;  // 存放六个井的 widget
    int m_ArrOfWell[6];                // 井的编号 m_indexOfWell

    ChangeSyncStatus m_ChangeStatus;
    QVector <WellsData> m_wellsOfSix;     // 6个井的容器
    QLabel *m_aixLabel;
    bool m_Pause;                       // 如果是1 则暂停  是 0 继续
    bool m_PushButton_1;
    bool m_PushButton_2;
    bool m_PushButton_3;
    bool m_PushButton_4;
    bool m_PushButton_5;
    bool m_PushButton_6;

    QLabel *m_perimg1;
    QLabel *m_perimg2;
    QLabel *m_per1;
    QLabel *m_per2;

    QMenu * menu_1;
    QMenu * menu_2;
    QMenu * menu_3;
    QMenu * menu_4;
    QMenu * menu_5;
    QMenu * menu_6;

    QVector <QString> m_MenuStringArr;

    Mdi *m_mdi;
    SettingConfig *m_SetConfig;

};

#endif // MAINWINDOW_H
