#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QElapsedTimer>
#include <QTime>
#include <QDebug>





enum PanType{
    GrayP = 0, Green30 = 1, Green60 = 2, Green100 = 3, Red100 = 4
};

enum SwitchType{
    GrayClose = 0, GreenOpen = 1, RedClose = 2
};


enum LightType{
    GrayL = 0,  Green = 1, Yellow = 2, Red = 3
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = true;
    this->resize(1600,1120);
    m_mdi = new Mdi(NULL);
    m_mdi->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::Dialog);
    m_mdi->setWindowModality(Qt::ApplicationModal);

    m_aixLabel = new QLabel("指控备心跳正常");
    m_perimg1 = new QLabel(" ", this);
    m_perimg2 = new QLabel(" ", this);
    m_per1 = new QLabel("数据库连接成功", this);
    m_per2 = new QLabel("传输连接成功", this);
    for(int i = 0; i < 6; ++i)
        m_ArrOfWell[i] = -1;
    m_Pause = true;
    settingMenu();
    m_PushButton_1 = false;
    m_PushButton_1 = false;
    m_PushButton_2 = false;
    m_PushButton_3 = false;
    m_PushButton_4 = false;
    m_PushButton_5 = false;
    m_PushButton_6 = false;

    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this, SLOT(OPenMdi()));


    PreProcess();
}


void MainWindow::Pause()
{
    QTime dieTime = QTime::currentTime().addMSecs(10000000);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::PreProcess(){

    mainWindowInit();
    mainWindowAssignNull();
    mainWindowAssignText();
    m_aixLabel->setText("指控备心跳正常");


    QImage imTrue;
    imTrue.load(":/img/true.png");
    m_aixLabel->setFont(QFont("宋体", 11, QFont::Bold));
    //Optional
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
    statusBar()->setSizeGripEnabled(false); //设置是否显示右边的大小控制点
    statusBar()->addWidget(m_aixLabel);


    m_perimg1->setText(" ");
    m_perimg2->setText(" ");
    m_per1->setText("数据库连接成功");
    m_per1->setFont(QFont("宋体", 11, QFont::Bold));
    m_per2->setText("传输连接成功");
    m_per2->setFont(QFont("宋体", 11, QFont::Bold));
    m_perimg1->setPixmap(QPixmap::fromImage(imTrue));
    m_perimg2->setPixmap(QPixmap::fromImage(imTrue));
    QPixmap pixmap = QPixmap::fromImage(imTrue);
    QPixmap fitpixmap = pixmap.scaled(10, 10, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    m_perimg1->setPixmap(fitpixmap);
    m_perimg2->setPixmap(fitpixmap);

    statusBar()->addPermanentWidget(m_perimg1); //现实永久信息
    statusBar()->addPermanentWidget(m_per1);
    statusBar()->addPermanentWidget(m_perimg2 ); //现实永久信息
    statusBar()->addPermanentWidget(m_per2);
}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::settingMenu(){

    menu_1=new QMenu;
    menu_1->addAction("测试模式",this,SLOT(getWell_11Pattern()));
    menu_1->addSeparator();
    menu_1->addAction("作战模式",this,SLOT(getWell_12Pattern()));
    ui->pushButton_11->setContextMenuPolicy(Qt::CustomContextMenu);


    menu_2=new QMenu;
    menu_2->addAction("测试模式",this,SLOT(getWell_21Pattern()));
    menu_2->addSeparator();
    menu_2->addAction("作战模式",this,SLOT(getWell_22Pattern()));
    ui->pushButton_12->setContextMenuPolicy(Qt::CustomContextMenu);

    menu_3=new QMenu;
    menu_3->addAction("测试模式",this,SLOT(getWell_31Pattern()));
    menu_3->addSeparator();
    menu_3->addAction("作战模式",this,SLOT(getWell_32Pattern()));

    ui->pushButton_13->setContextMenuPolicy(Qt::CustomContextMenu);

    menu_4=new QMenu;
    menu_4->addAction("测试模式",this,SLOT(getWell_41Pattern()));
    menu_4->addSeparator();
    menu_4->addAction("作战模式",this,SLOT(getWell_42Pattern()));
    ui->pushButton_21->setContextMenuPolicy(Qt::CustomContextMenu);

    menu_5=new QMenu;
    menu_5->addAction("测试模式",this,SLOT(getWell_51Pattern()));
    menu_5->addSeparator();
    menu_5->addAction("作战模式",this,SLOT(getWell_52Pattern()));
    ui->pushButton_22->setContextMenuPolicy(Qt::CustomContextMenu);

    menu_6=new QMenu;
    menu_6->addAction("测试模式",this,SLOT(getWell_61Pattern()));
    menu_6->addSeparator();
    menu_6->addAction("作战模式",this,SLOT(getWell_62Pattern()));
    ui->pushButton_23->setContextMenuPolicy(Qt::CustomContextMenu);


    connect(menu_1,SIGNAL(triggered(QAction*)),this,SLOT(onMenuTriggered(QAction*)));
    connect(ui->pushButton_11,&QPushButton::customContextMenuRequested,[=](const QPoint &pos){
        menu_1->exec(QCursor::pos());

    });
    connect(ui->pushButton_12,&QPushButton::customContextMenuRequested,[=](const QPoint &pos){
        menu_2->exec(QCursor::pos());

    });
    connect(ui->pushButton_13,&QPushButton::customContextMenuRequested,[=](const QPoint &pos){
        menu_3->exec(QCursor::pos());
    });
    connect(ui->pushButton_21,&QPushButton::customContextMenuRequested,[=](const QPoint &pos){
        menu_4->exec(QCursor::pos());
    });
    connect(ui->pushButton_22,&QPushButton::customContextMenuRequested,[=](const QPoint &pos){
        menu_5->exec(QCursor::pos());
    });
    connect(ui->pushButton_23,&QPushButton::customContextMenuRequested,[=](const QPoint &pos){
        menu_6->exec(QCursor::pos());
    });
}

void MainWindow::mainWindowInit(){

    WellsData Well;

    //////////////////////    将第 1 个井标签装入井中    ///////////////////
    Well.m_LabelOfWell_22.append(ui->label_101);
    Well.m_LabelOfWell_22.append(ui->label_102);
    Well.m_LabelOfWell_22.append(ui->label_103);
    Well.m_LabelOfWell_22.append(ui->label_104);
    Well.m_LabelOfWell_22.append(ui->label_105);
    Well.m_LabelOfWell_22.append(ui->label_106);
    Well.m_LabelOfWell_22.append(ui->label_107);
    Well.m_LabelOfWell_22.append(ui->label_108);
    Well.m_LabelOfWell_22.append(ui->label_109);
    Well.m_LabelOfWell_22.append(ui->label_110);
    Well.m_LabelOfWell_22.append(ui->label_111);
    Well.m_LabelOfWell_22.append(ui->label_112);
    Well.m_LabelOfWell_22.append(ui->label_113);
    Well.m_LabelOfWell_22.append(ui->label_114);
    Well.m_LabelOfWell_22.append(ui->label_115);
    Well.m_LabelOfWell_22.append(ui->label_116);
    Well.m_LabelOfWell_22.append(ui->label_117);
    Well.m_LabelOfWell_22.append(ui->label_118);
    Well.m_LabelOfWell_22.append(ui->label_119);
    Well.m_LabelOfWell_22.append(ui->label_120);
    Well.m_LabelOfWell_22.append(ui->label_121);
    Well.m_LabelOfWell_22.append(ui->label_122);

    // 3 个按钮
    Well.m_DetailPushButtonOfWell_3.append(ui->pushButton_110001);
    Well.m_DetailPushButtonOfWell_3.append(ui->pushButton_110002);
    Well.m_DetailPushButtonOfWell_3.append(ui->pushButton_110003);
    //  添加 3 个文本
    Well.m_DetailTextLineOfWell_3.append(ui->lineEdit_110001);
    Well.m_DetailTextLineOfWell_3.append(ui->lineEdit_110002);
    Well.m_DetailTextLineOfWell_3.append(ui->lineEdit_110003);

    //  添加 2 个Tab
    Well.m_DetailTableOfWell_2.append(ui->tableWidget_110001);
    // 添加界面左下方的任务表
    Well.m_DetailTableOfWell_2.append(ui->tableWidget_110002);


    // 添加井最上面一个Table


    //下半部分label标签添加操作-2020/07/20-wxy
    //区块00-4个label
    Well.m_DetailLabelOfWell_00.append(ui->label_110001);
    Well.m_DetailLabelOfWell_00.append(ui->label_110002);
    Well.m_DetailLabelOfWell_00.append(ui->label_110003);
    Well.m_DetailLabelOfWell_00.append(ui->label_110004);
    Well.m_DetailLabelOfWell_00.append(ui->label_110005);

    //区块01-16个label
    Well.m_DetailLabelOfWell_01.append(ui->label_110101);
    Well.m_DetailLabelOfWell_01.append(ui->label_110102);
    Well.m_DetailLabelOfWell_01.append(ui->label_110103);
    Well.m_DetailLabelOfWell_01.append(ui->label_110104);
    Well.m_DetailLabelOfWell_01.append(ui->label_110105);
    Well.m_DetailLabelOfWell_01.append(ui->label_110106);
    Well.m_DetailLabelOfWell_01.append(ui->label_110107);
    Well.m_DetailLabelOfWell_01.append(ui->label_110108);
    Well.m_DetailLabelOfWell_01.append(ui->label_110109);
    Well.m_DetailLabelOfWell_01.append(ui->label_110110);
    Well.m_DetailLabelOfWell_01.append(ui->label_110111);
    Well.m_DetailLabelOfWell_01.append(ui->label_110112);
    Well.m_DetailLabelOfWell_01.append(ui->label_110113);
    Well.m_DetailLabelOfWell_01.append(ui->label_110114);
    Well.m_DetailLabelOfWell_01.append(ui->label_110115);
    Well.m_DetailLabelOfWell_01.append(ui->label_110116);

    //区块02-6个label
    Well.m_DetailLabelOfWell_02.append(ui->label_110201);
    Well.m_DetailLabelOfWell_02.append(ui->label_110202);
    Well.m_DetailLabelOfWell_02.append(ui->label_110203);
    Well.m_DetailLabelOfWell_02.append(ui->label_110204);
    Well.m_DetailLabelOfWell_02.append(ui->label_110205);
    Well.m_DetailLabelOfWell_02.append(ui->label_110206);

    //区块03-6个label
    Well.m_DetailLabelOfWell_03.append(ui->label_110301);
    Well.m_DetailLabelOfWell_03.append(ui->label_110302);
    Well.m_DetailLabelOfWell_03.append(ui->label_110303);
    Well.m_DetailLabelOfWell_03.append(ui->label_110304);
    Well.m_DetailLabelOfWell_03.append(ui->label_110305);
    Well.m_DetailLabelOfWell_03.append(ui->label_110306);
    //区块04-6个label
    Well.m_DetailLabelOfWell_04.append(ui->label_110401);
    Well.m_DetailLabelOfWell_04.append(ui->label_110402);
    Well.m_DetailLabelOfWell_04.append(ui->label_110403);
    Well.m_DetailLabelOfWell_04.append(ui->label_110404);
    Well.m_DetailLabelOfWell_04.append(ui->label_110405);
    Well.m_DetailLabelOfWell_04.append(ui->label_110406);

    //区块05-6个label
    Well.m_DetailLabelOfWell_05.append(ui->label_110501);
    Well.m_DetailLabelOfWell_05.append(ui->label_110502);
    Well.m_DetailLabelOfWell_05.append(ui->label_110503);
    Well.m_DetailLabelOfWell_05.append(ui->label_110504);
    Well.m_DetailLabelOfWell_05.append(ui->label_110505);
    Well.m_DetailLabelOfWell_05.append(ui->label_110506);

    //区块06-8个label
    Well.m_DetailLabelOfWell_06.append(ui->label_110601);
    Well.m_DetailLabelOfWell_06.append(ui->label_110602);
    Well.m_DetailLabelOfWell_06.append(ui->label_110603);
    Well.m_DetailLabelOfWell_06.append(ui->label_110604);
    Well.m_DetailLabelOfWell_06.append(ui->label_110605);
    Well.m_DetailLabelOfWell_06.append(ui->label_110606);
    Well.m_DetailLabelOfWell_06.append(ui->label_110607);
    Well.m_DetailLabelOfWell_06.append(ui->label_110608);

    //区块07-6个label
    Well.m_DetailLabelOfWell_07.append(ui->label_110701);
    Well.m_DetailLabelOfWell_07.append(ui->label_110702);
    Well.m_DetailLabelOfWell_07.append(ui->label_110703);
    Well.m_DetailLabelOfWell_07.append(ui->label_110704);
    Well.m_DetailLabelOfWell_07.append(ui->label_110705);
    Well.m_DetailLabelOfWell_07.append(ui->label_110706);

    //区块08-5个label
    Well.m_DetailLabelOfWell_08.append(ui->label_110801);
    Well.m_DetailLabelOfWell_08.append(ui->label_110802);
    Well.m_DetailLabelOfWell_08.append(ui->label_110803);
    Well.m_DetailLabelOfWell_08.append(ui->label_110804);
    Well.m_DetailLabelOfWell_08.append(ui->label_110805);

    //区块09-5个label
    Well.m_DetailLabelOfWell_09.append(ui->label_110901);
    Well.m_DetailLabelOfWell_09.append(ui->label_110902);
    Well.m_DetailLabelOfWell_09.append(ui->label_110903);
    Well.m_DetailLabelOfWell_09.append(ui->label_110904);
    Well.m_DetailLabelOfWell_09.append(ui->label_110905);

    //区块10-5个label
    Well.m_DetailLabelOfWell_10.append(ui->label_111001);
    Well.m_DetailLabelOfWell_10.append(ui->label_111002);
    Well.m_DetailLabelOfWell_10.append(ui->label_111003);
    Well.m_DetailLabelOfWell_10.append(ui->label_111004);
    Well.m_DetailLabelOfWell_10.append(ui->label_111005);

    Well.m_TableOfWell_2.append(ui->tableWidget_1);
    // 添加井最内部一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_11);


    m_wellsOfSix.append(Well);
    Well.m_LabelOfWell_22.clear();
    Well.m_TableOfWell_2.clear();


    //////////////////////    将第 2 个井标签装入井中    ///////////////////


    Well.m_LabelOfWell_22.append(ui->label_201);
    Well.m_LabelOfWell_22.append(ui->label_202);
    Well.m_LabelOfWell_22.append(ui->label_203);
    Well.m_LabelOfWell_22.append(ui->label_204);
    Well.m_LabelOfWell_22.append(ui->label_205);
    Well.m_LabelOfWell_22.append(ui->label_206);
    Well.m_LabelOfWell_22.append(ui->label_207);
    Well.m_LabelOfWell_22.append(ui->label_208);
    Well.m_LabelOfWell_22.append(ui->label_209);
    Well.m_LabelOfWell_22.append(ui->label_210);
    Well.m_LabelOfWell_22.append(ui->label_211);
    Well.m_LabelOfWell_22.append(ui->label_212);
    Well.m_LabelOfWell_22.append(ui->label_213);
    Well.m_LabelOfWell_22.append(ui->label_214);
    Well.m_LabelOfWell_22.append(ui->label_215);
    Well.m_LabelOfWell_22.append(ui->label_216);
    Well.m_LabelOfWell_22.append(ui->label_217);
    Well.m_LabelOfWell_22.append(ui->label_218);
    Well.m_LabelOfWell_22.append(ui->label_219);
    Well.m_LabelOfWell_22.append(ui->label_220);
    Well.m_LabelOfWell_22.append(ui->label_221);
    Well.m_LabelOfWell_22.append(ui->label_222);

    // 添加井最上面一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_2);
    // 添加井最内部一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_12);

    m_wellsOfSix.append(Well);
    Well.m_LabelOfWell_22.clear();
    Well.m_TableOfWell_2.clear();

    //////////////////////    将第 3 个井标签装入井中    ///////////////////
    Well.m_LabelOfWell_22.append(ui->label_301);
    Well.m_LabelOfWell_22.append(ui->label_302);
    Well.m_LabelOfWell_22.append(ui->label_303);
    Well.m_LabelOfWell_22.append(ui->label_304);
    Well.m_LabelOfWell_22.append(ui->label_305);
    Well.m_LabelOfWell_22.append(ui->label_306);
    Well.m_LabelOfWell_22.append(ui->label_307);
    Well.m_LabelOfWell_22.append(ui->label_308);
    Well.m_LabelOfWell_22.append(ui->label_309);
    Well.m_LabelOfWell_22.append(ui->label_310);
    Well.m_LabelOfWell_22.append(ui->label_311);
    Well.m_LabelOfWell_22.append(ui->label_312);
    Well.m_LabelOfWell_22.append(ui->label_313);
    Well.m_LabelOfWell_22.append(ui->label_314);
    Well.m_LabelOfWell_22.append(ui->label_315);
    Well.m_LabelOfWell_22.append(ui->label_316);
    Well.m_LabelOfWell_22.append(ui->label_317);
    Well.m_LabelOfWell_22.append(ui->label_318);
    Well.m_LabelOfWell_22.append(ui->label_319);
    Well.m_LabelOfWell_22.append(ui->label_320);
    Well.m_LabelOfWell_22.append(ui->label_321);
    Well.m_LabelOfWell_22.append(ui->label_322);
    // 添加井最上面一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_3);
    // 添加井最内部一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_13);
    m_wellsOfSix.append(Well);
    Well.m_LabelOfWell_22.clear();
    Well.m_TableOfWell_2.clear();


    //////////////////////    将第 4 个井标签装入井中    ///////////////////
    Well.m_LabelOfWell_22.append(ui->label_401);
    Well.m_LabelOfWell_22.append(ui->label_402);
    Well.m_LabelOfWell_22.append(ui->label_403);
    Well.m_LabelOfWell_22.append(ui->label_404);
    Well.m_LabelOfWell_22.append(ui->label_405);
    Well.m_LabelOfWell_22.append(ui->label_406);
    Well.m_LabelOfWell_22.append(ui->label_407);
    Well.m_LabelOfWell_22.append(ui->label_408);
    Well.m_LabelOfWell_22.append(ui->label_409);
    Well.m_LabelOfWell_22.append(ui->label_410);
    Well.m_LabelOfWell_22.append(ui->label_411);
    Well.m_LabelOfWell_22.append(ui->label_412);
    Well.m_LabelOfWell_22.append(ui->label_413);
    Well.m_LabelOfWell_22.append(ui->label_414);
    Well.m_LabelOfWell_22.append(ui->label_415);
    Well.m_LabelOfWell_22.append(ui->label_416);
    Well.m_LabelOfWell_22.append(ui->label_417);
    Well.m_LabelOfWell_22.append(ui->label_418);
    Well.m_LabelOfWell_22.append(ui->label_419);
    Well.m_LabelOfWell_22.append(ui->label_420);
    Well.m_LabelOfWell_22.append(ui->label_421);
    Well.m_LabelOfWell_22.append(ui->label_422);
    // 添加井最上面一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_4);
    // 添加井最内部一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_21);
    m_wellsOfSix.append(Well);
    Well.m_LabelOfWell_22.clear();
    Well.m_TableOfWell_2.clear();

    //////////////////////    将第 5 个井标签装入井中    ///////////////////
    Well.m_LabelOfWell_22.append(ui->label_501);
    Well.m_LabelOfWell_22.append(ui->label_502);
    Well.m_LabelOfWell_22.append(ui->label_503);
    Well.m_LabelOfWell_22.append(ui->label_504);
    Well.m_LabelOfWell_22.append(ui->label_505);
    Well.m_LabelOfWell_22.append(ui->label_506);
    Well.m_LabelOfWell_22.append(ui->label_507);
    Well.m_LabelOfWell_22.append(ui->label_508);
    Well.m_LabelOfWell_22.append(ui->label_509);
    Well.m_LabelOfWell_22.append(ui->label_510);
    Well.m_LabelOfWell_22.append(ui->label_511);
    Well.m_LabelOfWell_22.append(ui->label_512);
    Well.m_LabelOfWell_22.append(ui->label_513);
    Well.m_LabelOfWell_22.append(ui->label_514);
    Well.m_LabelOfWell_22.append(ui->label_515);
    Well.m_LabelOfWell_22.append(ui->label_516);
    Well.m_LabelOfWell_22.append(ui->label_517);
    Well.m_LabelOfWell_22.append(ui->label_518);
    Well.m_LabelOfWell_22.append(ui->label_519);
    Well.m_LabelOfWell_22.append(ui->label_520);
    Well.m_LabelOfWell_22.append(ui->label_521);
    Well.m_LabelOfWell_22.append(ui->label_522);
    // 添加井最上面一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_5);
    // 添加井最内部一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_22);
    m_wellsOfSix.append(Well);
    Well.m_LabelOfWell_22.clear();
    Well.m_TableOfWell_2.clear();

    //////////////////////    将第 6 个井标签装入井中    ///////////////////
    Well.m_LabelOfWell_22.append(ui->label_601);
    Well.m_LabelOfWell_22.append(ui->label_602);
    Well.m_LabelOfWell_22.append(ui->label_603);
    Well.m_LabelOfWell_22.append(ui->label_604);
    Well.m_LabelOfWell_22.append(ui->label_605);
    Well.m_LabelOfWell_22.append(ui->label_606);
    Well.m_LabelOfWell_22.append(ui->label_607);
    Well.m_LabelOfWell_22.append(ui->label_608);
    Well.m_LabelOfWell_22.append(ui->label_609);
    Well.m_LabelOfWell_22.append(ui->label_610);
    Well.m_LabelOfWell_22.append(ui->label_611);
    Well.m_LabelOfWell_22.append(ui->label_612);
    Well.m_LabelOfWell_22.append(ui->label_613);
    Well.m_LabelOfWell_22.append(ui->label_614);
    Well.m_LabelOfWell_22.append(ui->label_615);
    Well.m_LabelOfWell_22.append(ui->label_616);
    Well.m_LabelOfWell_22.append(ui->label_617);
    Well.m_LabelOfWell_22.append(ui->label_618);
    Well.m_LabelOfWell_22.append(ui->label_619);
    Well.m_LabelOfWell_22.append(ui->label_620);
    Well.m_LabelOfWell_22.append(ui->label_621);
    Well.m_LabelOfWell_22.append(ui->label_622);
    // 添加井最上面一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_6);

    // 添加井最内部一个Table
    Well.m_TableOfWell_2.append(ui->tableWidget_23);
    m_wellsOfSix.append(Well);
    Well.m_TableOfWell_2.clear();
    Well.m_LabelOfWell_22.clear();
}

void MainWindow::mainWindowAssignNull(){
    refresh ();

    // 第1号井的赋值
    for(int j = 0; j < 6; ++j){
        m_ChangeStatus.ChangeTable(m_wellsOfSix.at(j), "title", 0, 0, " ",QColor(0,0,0));
        for(int i = 1; i < 3; ++i){
            //去字
            m_ChangeStatus.ChangeTable(m_wellsOfSix.at(j), "title", 0, i, " ",QColor(222,231,239));
        }

    }

    /////    刷新详细的灯
    QString pathGif = ":/img/false.gif";
    QSize si1(m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(0)->width(),m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(0)->height());
    QMovie *movie[7];
    for(int i = 0; i < 7; ++i){
        movie[i] = new QMovie(pathGif);
        movie[i]->setScaledSize(si1);
    }

    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(0)->setMovie(movie[0]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(0)->show();
    movie[0]->start();
    m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(0)->setMovie(movie[1]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(0)->show();
    movie[1]->start();
    m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(0)->setMovie(movie[2]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(0)->show();
    movie[2]->start();
    m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(0)->setMovie(movie[3]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(0)->show();
    movie[3]->start();
    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(0)->setMovie(movie[4]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(0)->show();
    movie[4]->start();
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(0)->setMovie(movie[5]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(0)->show();
    movie[5]->start();
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(0)->setMovie(movie[6]);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(0)->show();
    movie[6]->start();







}

void MainWindow::mainWindowAssignText(){


    //上半部分-wxy-2020/07/20
    //第一井

    m_wellsOfSix.at(0).m_LabelOfWell_22.at(3)->setText("B-1-1");
    m_wellsOfSix.at(0).m_LabelOfWell_22.at(5)->setText("B-1-2");
    m_wellsOfSix.at(0).m_LabelOfWell_22.at(7)->setText("B-1-3");
    m_wellsOfSix.at(0).m_LabelOfWell_22.at(11)->setText("B-1-4");
    m_wellsOfSix.at(0).m_LabelOfWell_22.at(13)->setText("B-1-5");
    m_wellsOfSix.at(0).m_LabelOfWell_22.at(15)->setText("B-1-6");
    m_wellsOfSix.at(0).m_LabelOfWell_22.at(17)->setText("B-1-12");


    //第二井
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(3)->setText("B-2-1");
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(5)->setText("B-2-2");
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(7)->setText("B-2-3");
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(11)->setText("B-2-4");
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(13)->setText("B-2-5");
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(15)->setText("B-2-6");
    m_wellsOfSix.at(1).m_LabelOfWell_22.at(17)->setText("B-2-12");

    //第三井
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(3)->setText("B-3-1");
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(5)->setText("B-3-2");
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(7)->setText("B-3-3");
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(11)->setText("B-3-4");
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(13)->setText("B-3-5");
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(15)->setText("B-3-6");
    m_wellsOfSix.at(2).m_LabelOfWell_22.at(17)->setText("B-3-12");

    //第四井
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(3)->setText("B-4-1");
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(5)->setText("B-4-2");
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(7)->setText("B-4-3");
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(11)->setText("B-4-4");
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(13)->setText("B-4-5");
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(15)->setText("B-4-6");
    m_wellsOfSix.at(3).m_LabelOfWell_22.at(17)->setText("B-4-12");

    //第五井
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(3)->setText("B-5-1");
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(5)->setText("B-5-2");
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(7)->setText("B-5-3");
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(11)->setText("B-5-4");
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(13)->setText("B-5-5");
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(15)->setText("B-5-6");
    m_wellsOfSix.at(4).m_LabelOfWell_22.at(17)->setText("B-5-12");

    //第六井
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(3)->setText("B-6-1");
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(5)->setText("B-6-2");
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(7)->setText("B-6-3");
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(11)->setText("B-6-4");
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(13)->setText("B-6-5");
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(15)->setText("B-6-6");
    m_wellsOfSix.at(5).m_LabelOfWell_22.at(17)->setText("B-6-12");



    // 将所有6个井的灯泡变灰
    for(int i = 0; i < 6; ++i){
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(2)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(4)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(6)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(10)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(12)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(14)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(16)->setStyleSheet(QStringLiteral("border-image: url(:/img/pie-NF.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(18)->setStyleSheet(QStringLiteral("border-image: url(:/img/Off-NP.png);"));
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(20)->setStyleSheet(QStringLiteral("border-image: url(:/img/Off-NP.png);"));
        m_wellsOfSix.at(i).m_TableOfWell_2.at(1)->clear();
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(8)->setText("");       // ----------------------------------------有个 clear
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(1)->setText("集控");
    }





    //下半部分-wxy
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(1)->setText("C-13");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(2)->setText("C-14");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(3)->setText("C-15");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(1)->setText("D-1");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(2)->setText("D-2");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(4)->setText("D-3");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(6)->setText("D-4");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(8)->setText("D-5");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(10)->setText("D-6");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(12)->setText("D-7");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(14)->setText("D-8");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(1)->setText("D-9");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(2)->setText("D-10");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(4)->setText("D-11");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(1)->setText("D-12");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(2)->setText("D-13");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(4)->setText("D-14");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(1)->setText("D-15");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(2)->setText("D-16");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(4)->setText("D-17");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(1)->setText("D-18");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(2)->setText("D-19");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(4)->setText("D-20");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(1)->setText("D-21");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(2)->setText("D-22");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(4)->setText("D-23");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(6)->setText("D-24");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(1)->setText("D-25");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(2)->setText("D-26");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(4)->setText("D-27");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_08.at(0)->setText("D-20");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_09.at(0)->setText("D-29");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_10.at(0)->setText("D-30");




    // 添加菜单内容
    m_MenuStringArr.append("S1-1");
    m_MenuStringArr.append("S1-2");
    m_MenuStringArr.append("S1-3");
    m_MenuStringArr.append("S1-4");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("S2-1");
    m_MenuStringArr.append("S2-2");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("一二三四五六七八九十S3-1");
    m_MenuStringArr.append("S3-2");
    m_MenuStringArr.append("S3-3");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("S4-1");
    m_MenuStringArr.append("S4-2");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("S5-1");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("S6-1");
    m_MenuStringArr.append("S6-2");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("S7-1");
    m_MenuStringArr.append("S7-2");
    m_MenuStringArr.append("----");
    m_MenuStringArr.append("S8-1");
    m_MenuStringArr.append("S8-2");

}

void MainWindow::MySleep(double sec){ // 延迟sec秒
    int msec = sec * 1000;
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::Process1(){

    refresh();

    // 修改 title 第一个单元
    // 加入循环的是：所有带图片的标签，m_LabelOfWell_22.at(1)，m_LabelOfWell_22.at(8)
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeTable(m_wellsOfSix.at(m_indexOfWell), "title", 0, 0, "阵地编号：" + QString::number(m_ArrOfWell[m_indexOfWell]),QColor(0, 0, 0));
            m_wellsOfSix.at(m_indexOfWell).m_LabelOfWell_22.at(1)->setText("集控(主机)");
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-15", Green);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_04.at(3)->setText("：指令启动未定");
            // D 29
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-29", Yellow);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_09.at(3)->setText("闭锁");
        }


    MySleep(2);
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            // D 9
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-9", Green);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_02.at(3)->setText("：自检正常");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_02.at(5)->setText("：主链路工作");
            // D 18
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-18", Yellow);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_05.at(3)->setText("：正常");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_05.at(5)->setText("：未建立");
        }

    MySleep(2);
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            // D 12
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-12", Green);

            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_03.at(3)->setText("：自检正常");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_03.at(5)->setText("：主链路工作");

            // D 30
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-30", RedClose);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_10.at(3)->setText("：闭锁");


            // D 21
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-21", Yellow);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_06.at(3)->setText("：0");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_06.at(5)->setText("：正常");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_06.at(7)->setText("：未建立");
        }


    MySleep(1);     // D 25    -------------------------------------------------------------------    D-25 不变黄
    // m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-25", Yellow);
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_07.at(3)->setText("：0");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_07.at(5)->setText("：未建立");
        }


    MySleep(5);     //D 1
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-1", Yellow);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_01.at(3)->setText("：心跳正常(当班)");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_01.at(5)->setText("：自检正常");

            // D 28
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-28", Red100);
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_08.at(3)->setText("：未验证");
        }

    // 默认选择作战
    CheckPattern();



}

void MainWindow::CheckPattern(){

    ///////////////////      测试  或者  作战     ////////////
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            if(0 == m_wellsOfSix.at(m_indexOfWell).m_Pattern){
                for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
                    if(m_ArrOfWell[m_indexOfWell] >= 0){
                        m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_01.at(7)->setText("：测试");
                    }
            }else{
                for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
                    if(m_ArrOfWell[m_indexOfWell] >= 0){
                        m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_01.at(7)->setText("：作战");
                    }
            }
        }



    // 修改 title 第2个单元     ----------------------------------------------------------------------------  作战模式颜色不变
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            if(0 == m_wellsOfSix.at(m_indexOfWell).m_Pattern){
                m_ChangeStatus.ChangeTable(m_wellsOfSix.at(m_indexOfWell), "title", 0, 1, "测试模式",QColor(255, 170, 0));
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 标签 隐藏
                m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_00.at(2)->setVisible(false);
                m_wellsOfSix.at(m_indexOfWell).m_DetailTextLineOfWell_3.at(1)->setVisible(false);
            }else{
                m_ChangeStatus.ChangeTable(m_wellsOfSix.at(m_indexOfWell), "title", 0, 1, "作战模式",QColor(255, 170, 0));
                m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_00.at(2)->setVisible(true);
                m_wellsOfSix.at(m_indexOfWell).m_DetailTextLineOfWell_3.at(1)->setVisible(true);
            }
        }
    MySleep(2);

    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(9)->setText("：未收到");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(11)->setText("：无指令");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(13)->setText("：无指令");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(15)->setText("：无指令");

}

void MainWindow::Process2()
{
    // 修改 title 第3个单元
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeTable(m_wellsOfSix.at(m_indexOfWell), "title", 0, 2, "热戒备",QColor(255, 170, 0));
            m_wellsOfSix.at(m_indexOfWell).m_DetailTableOfWell_2.at(0)->item(0,2)->setText("进入热戒备");
            m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_00.at(4)->setText("发送热戒备指令成功");
        }

    MySleep(0.5);

    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(4)->setText("发送可行通道建立许可指令成功");

    MySleep(2.5);     //D 18
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-18", Green);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(5)->setText("：已建立");

    // D 21
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-21", Green);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(7)->setText("：已建立");

    MySleep(1);      // D 1
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-1", Green);
        }

    MySleep(0.5);
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(4)->setText("收到可行通道建立结果");
}

void MainWindow::Process3()
{
    if(0 == m_wellsOfSix.at(0).m_Pattern){
        m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(2)->setText("下达完成");
        m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(0)->setText("1");
    }else{
        m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(2)->setText("下达完成");
        m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(0)->setText("1");
        m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(1)->setText("1");
    }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(4)->setText("发送体诸元数据完成");
    MySleep(0.1);

    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(4)->setText("收到体诸元接受结果");



    if(0 == m_wellsOfSix.at(0).m_Pattern){
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(9)->setText("：模飞诸元接受正确");
    }else{
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(9)->setText("：作战诸元接受正确");
    }
    MySleep(5);
    // D 28
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-28", Green30);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_08.at(3)->setText("：诸元验证量计算成功");


}

void MainWindow::Process4(){

    // 修改 title 第3个单元  -----------------------------------------------第4步  进入发射，和测试  作战无关
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_ChangeStatus.ChangeTable(m_wellsOfSix.at(m_indexOfWell), "title", 0, 2, "发射",QColor(255, 170, 0));
        }

    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(3,2,new QTableWidgetItem("  " + getTimeNowMDHMS())); // 7-09 19:
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(4,1,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(4,2,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(4,3,new QTableWidgetItem(" 下达成功 "+ getTimeNowHMS()));

    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_wellsOfSix.at(m_indexOfWell).m_TableOfWell_2.at(1)->setItem(2,1,new QTableWidgetItem(" 下达成功 "));
            m_wellsOfSix.at(m_indexOfWell).m_TableOfWell_2.at(1)->setItem(2,2,new QTableWidgetItem(" 下达成功 "));
            m_wellsOfSix.at(m_indexOfWell).m_TableOfWell_2.at(1)->setItem(2,3,new QTableWidgetItem(" 下达成功 "));
        }

    MySleep(0.7);

    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(5,1,new QTableWidgetItem(" 通过 " + getTimeNowHMS()));
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(5,2,new QTableWidgetItem(" 通过 " + getTimeNowHMS()));
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(5,3,new QTableWidgetItem(" 通过 " + getTimeNowHMS()));


    if(0 == m_wellsOfSix.at(0).m_Pattern){
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(11)->setText("：测试授权指令验证正确");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(13)->setText("：测试授权指令验证正确");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(15)->setText("：测试授权指令验证正确");
    }else{
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(11)->setText("：作战授权指令验证正确");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(13)->setText("：作战授权指令验证正确");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(15)->setText("：作战授权指令验证正确");
    }

    if(0 == m_wellsOfSix.at(0).m_Pattern)
        m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(0)->setText("授权指令成功(测试)");
    else
        m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(0)->setText("授权指令成功(作战)");
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            m_wellsOfSix.at(0).m_LabelOfWell_22.at(8)->setText("授权指令");
        }


    MySleep(3);
    // D 28
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-28", Green60);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_08.at(3)->setText("：诸元验证成功");

    MySleep(2);
    // D 25
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-25", Green);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(3)->setText("：11121");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(5)->setText("：已建立");

    MySleep(1);



    // D 28
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-28", Green100);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_08.at(3)->setText("：弹上下传诸元验证通过");

    // D 29
    if(0 == m_wellsOfSix.at(0).m_Pattern)
        m_wellsOfSix.at(0).m_DetailLabelOfWell_09.at(3)->setText("：指令执行正确(测试)");
    else
        m_wellsOfSix.at(0).m_DetailLabelOfWell_09.at(3)->setText("：指令执行正确(作战)");

    MySleep(0.5);

    // D 29
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-29", GreenOpen);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_09.at(3)->setText("：开锁");

    MySleep(1);
    // D 29  -----------------------------------------------------------------------------------开锁后  不用闭锁
    //    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-29", RedClose);
    //    m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_09.at(3)->setText("闭锁");

    if(0 == m_wellsOfSix.at(0).m_Pattern)
    {
        for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
            if(m_ArrOfWell[m_indexOfWell] >= 0){
                m_wellsOfSix.at(m_indexOfWell).m_LabelOfWell_22.at(8)->setText("授权成功(测试)");
            }

    }
    else{
        for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
            if(m_ArrOfWell[m_indexOfWell] >= 0){
                m_wellsOfSix.at(m_indexOfWell).m_LabelOfWell_22.at(8)->setText("授权成功(作战)");
            }
    }

    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(6,2,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));

    MySleep(2);
    // D 30
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-30", GreenOpen);
        }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_10.at(3)->setText("：开锁");

    MySleep(1);
    // D 30   -----------------------------------------------------------------------------------开锁后  不用闭锁
    //    m_ChangeStatus.ChangeBulb(m_wellsOfSix.at(m_indexOfWell),"D-30", RedClose);
    //    m_wellsOfSix.at(m_indexOfWell).m_DetailLabelOfWell_10.at(3)->setText("闭锁");
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(6,1,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));

    m_aixLabel->setText("发送HAK准备好消息");
}

void MainWindow::on_pushButton_110002_clicked()
{
    Process2();
}

void MainWindow::on_pushButton_110003_clicked()
{
    Process3();
    Process4();
}

QString MainWindow::getTimeNowMDHMS(){

    QDateTime time= QDateTime::currentDateTime();
    QString date=time.toString("MM-dd hh:mm:ss");

    return date;
}

QString MainWindow::getTimeNowHMS(){

    QDateTime time= QDateTime::currentDateTime();
    QString date=time.toString(" hh:mm:ss");

    return date;
}



void MainWindow::getWell_11Pattern()
{
    if(m_ArrOfWell[0] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 0;
        CheckPattern();
    }
}

void MainWindow::getWell_12Pattern()
{
    if(m_ArrOfWell[0] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 1;
        CheckPattern();
    }
}

void MainWindow::getWell_21Pattern()
{
    if(m_ArrOfWell[1] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 0;
        CheckPattern();
    }
}

void MainWindow::getWell_22Pattern()
{
    if(m_ArrOfWell[1] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 1;
        CheckPattern();
    }
}

void MainWindow::getWell_31Pattern()
{
    if(m_ArrOfWell[2] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 0;
        CheckPattern();
    }
}

void MainWindow::getWell_32Pattern()
{
    if(m_ArrOfWell[2] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 1;
        CheckPattern();
    }
}

void MainWindow::getWell_41Pattern()
{
    if(m_ArrOfWell[3] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 0;
        CheckPattern();
    }
}

void MainWindow::getWell_42Pattern()
{
    if(m_ArrOfWell[3] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 1;
        CheckPattern();
    }
}

void MainWindow::getWell_51Pattern()
{
    if(m_ArrOfWell[4] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 0;
        CheckPattern();
    }
}

void MainWindow::getWell_52Pattern()
{
    if(m_ArrOfWell[4] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 1;
        CheckPattern();
    }
}

void MainWindow::getWell_61Pattern()
{
    if(m_ArrOfWell[5] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 0;
        CheckPattern();
    }
}

void MainWindow::getWell_62Pattern()
{
    if(m_ArrOfWell[5] >= 0){
        int &rp0 = const_cast<int &>(m_wellsOfSix.at(0).m_Pattern);
        int &rp1 = const_cast<int &>(m_wellsOfSix.at(1).m_Pattern);
        int &rp2 = const_cast<int &>(m_wellsOfSix.at(2).m_Pattern);
        int &rp3 = const_cast<int &>(m_wellsOfSix.at(3).m_Pattern);
        int &rp4 = const_cast<int &>(m_wellsOfSix.at(4).m_Pattern);
        int &rp5 = const_cast<int &>(m_wellsOfSix.at(5).m_Pattern);
        rp0 = rp1 = rp2 = rp3 = rp4 = rp5 = 1;
        CheckPattern();
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    if(m_ArrOfWell[0] >= 0)
        m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(0)->item(0,0)->setText("阵地编号：" + QString::number(m_ArrOfWell[0]));

}

void MainWindow::on_pushButton_12_clicked()
{
    if(m_ArrOfWell[1] >= 0)
        m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(0)->item(0,0)->setText("阵地编号：" + QString::number(m_ArrOfWell[1]));
}

void MainWindow::on_pushButton_13_clicked()
{
    if(m_ArrOfWell[2] >= 0)
        m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(0)->item(0,0)->setText("阵地编号：" + QString::number(m_ArrOfWell[2]));
}

void MainWindow::on_pushButton_21_clicked()
{
    if(m_ArrOfWell[3] >= 0)
        m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(0)->item(0,0)->setText("阵地编号：" + QString::number(m_ArrOfWell[3]));
}

void MainWindow::on_pushButton_22_clicked()
{
    if(m_ArrOfWell[4] >= 0)
        m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(0)->item(0,0)->setText("阵地编号：" + QString::number(m_ArrOfWell[4]));

}

void MainWindow::on_pushButton_23_clicked()
{
    if(m_ArrOfWell[5] >= 0)
        m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(0)->item(0,0)->setText("阵地编号：" + QString::number(m_ArrOfWell[5]));
          //      setItem(0,0, new QTableWidgetItem("阵地编号：" + QString::number(m_ArrOfWell[5])));
}
// 刷新下半区域
void MainWindow::refresh(){
    for(int i = 3;i <= 15;){
        m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(i)->setText(" ");
        i += 2;
    }

    for(int i=3;i<=5;){
        m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(i)->setText(" ");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(i)->setText(" ");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(i)->setText(" ");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(i)->setText(" ");
        m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(i)->setText(" ");
        i+=2;
    }
    for(int i = 3;i <= 7;){
        m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(i)->setText(" ");
        i += 2;
    }
    for(int i = 0;i < 5;i++){
        if(i!=1){
            m_wellsOfSix.at(0).m_DetailLabelOfWell_08.at(i)->setText(" ");
            m_wellsOfSix.at(0).m_DetailLabelOfWell_09.at(i)->setText(" ");
            m_wellsOfSix.at(0).m_DetailLabelOfWell_10.at(i)->setText(" ");
        }
    }
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(0)->setText("");
    m_wellsOfSix.at(0).m_DetailLabelOfWell_00.at(4)->setText("");

    m_wellsOfSix.at(0).m_DetailLabelOfWell_01.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_02.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_03.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_04.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_05.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_06.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_07.at(0)->setStyleSheet(QStringLiteral("border-image: url(:/img/false.png);"));

    m_wellsOfSix.at(0).m_DetailLabelOfWell_08.at(1)->setStyleSheet(QStringLiteral("border-image: url(:/img/pie-NF.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_09.at(1)->setStyleSheet(QStringLiteral("border-image: url(:/img/Off-NP.png);"));
    m_wellsOfSix.at(0).m_DetailLabelOfWell_10.at(1)->setStyleSheet(QStringLiteral("border-image: url(:/img/Off-NP.png);"));

    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->clear();
    QTableWidgetItem* temp=new QTableWidgetItem("C-4");
    QTableWidgetItem* temp2=new QTableWidgetItem("C-5");
    QTableWidgetItem* temp3=new QTableWidgetItem("C-6");
    QTableWidgetItem* temp4=new QTableWidgetItem("C-7");
    QTableWidgetItem* temp5=new QTableWidgetItem("C-8");
    QTableWidgetItem* temp6=new QTableWidgetItem("C-9");
    QTableWidgetItem* temp7=new QTableWidgetItem("C-10");
    QTableWidgetItem* temp8=new QTableWidgetItem("C-11");
    QTableWidgetItem* temp9=new QTableWidgetItem("C-12");
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(0,1,temp);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(0,2,temp2);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(0,3,temp3);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(1,0,temp4);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(2,0,temp5);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(3,0,temp6);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(4,0,temp7);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(5,0,temp8);
    m_wellsOfSix.at(0).m_DetailTableOfWell_2.at(1)->setItem(6,0,temp9);

    m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(2)->setText("");
    m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(0)->setText("");
    m_wellsOfSix.at(0).m_DetailTextLineOfWell_3.at(1)->setText("");

    // 修改 H引爆
    for(int i = 0; i < 6; ++i){
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(19)->setText("H引爆");
        m_wellsOfSix.at(i).m_LabelOfWell_22.at(17)->setText("H引爆");
    }
    m_aixLabel->setText("指控备心跳正常");
}

void MainWindow::on_pushButton_110001_clicked()
{
    PreProcess();
    Process1();
}

void MainWindow::Start(){
    // 阵地编号赋值
    m_ArrOfWell[0] = 9;
    m_ArrOfWell[2] = 3;
    m_ArrOfWell[4] = 7;
    m_ArrOfWell[5] = 25;
    m_ArrOfWell[1] = 88;
    m_ArrOfWell[3] = 123;
    for(int m_indexOfWell = 0;m_indexOfWell < 6;m_indexOfWell++)
        if(m_ArrOfWell[m_indexOfWell] >= 0){
            switch (m_indexOfWell) {
            case 0:
                ui->verticalWidget_1->setStyleSheet("background-color: rgb(255, 255, 255)");
                break;
            case 1:
                ui->verticalWidget_2->setStyleSheet("background-color: rgb(255, 255, 255)");
                break;
            case 2:
                ui->verticalWidget_3->setStyleSheet("background-color: rgb(255, 255, 255)");
                break;
            case 3:
                ui->verticalWidget_4->setStyleSheet("background-color: rgb(255, 255, 255)");
                break;
            case 4:
                ui->verticalWidget_5->setStyleSheet("background-color: rgb(255, 255, 255)");
                break;
            case 5:
                ui->verticalWidget_6->setStyleSheet("background-color: rgb(255, 255, 255)");
                break;
            default:
                qDebug() << "Start error";
                break;
            }
        }
        //   10  改为了   5
        MySleep(5);
        Process1();
}

void MainWindow::OPenMdi()
{
    if(ui->comboBox->currentIndex() == 1){
        qDebug() << "OpenMdi";
        m_mdi->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::Dialog);
        m_mdi->setWindowModality(Qt::ApplicationModal);

        m_mdi->show();

        this->show();
        this->Start();
    }
    else
        qDebug() << "试试";
}
