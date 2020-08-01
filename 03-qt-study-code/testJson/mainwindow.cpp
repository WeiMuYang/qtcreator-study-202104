#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateJson();


    // 方法1：
    QTableWidgetItem *item = new QTableWidgetItem("你好");
    item->setBackgroundColor(QColor(255,255,255));
    item->setFont(QFont("宋体", 5));
    ui->tableWidget->setItem(1,1,item);

    // 方法2：
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("你好吗"));
    //  没有new 的话 Item 不能用
    ui->tableWidget->item(1,2)->setFont(QFont("宋体", 5));



//    columnHeaderItem0->setFont(QFont("宋体")); //设置字体



//    ui->tableWidget->item(1,1)->setText("你好");

//    ui->tableWidget->item(1,2)->setText("你好");










}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CreateJson(){


    m_JsonData.insert("Name", "Qt");
    m_JsonData.insert("From", 1991);
    m_JsonData.insert("Cross Platform", true);


    m_CS.insert("CS", m_JsonData);

    m_CCS.insert("CCS", m_CS);

    // 构建 JSON 文档

    m_document.setObject(m_CCS);
    QByteArray byteArray = m_document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    qDebug().noquote() << strJson;



    m_JsonData["Name"] = "99";

    // 多层结构需要分层查找，先找最外层
    QJsonValueRef RefPage = m_CCS.find("CCS").value();
    // 将查找到的内层，再转成Json对象，直到最内层
    QJsonObject obj = RefPage.toObject();

    // 找中间层
    QJsonValueRef RefPage1 = obj.find("CS").value();
    // 将中间层转成Json对象
    QJsonObject obj1 = RefPage1.toObject();


    // 将内层要修改的地方修改
    obj1["From"] = 1995;
    // 将修改好的内容赋值到中间层
    RefPage1 = obj1;

    // 将修改好的内容赋值到最外层
    RefPage = obj;



    qDebug().noquote() << strJson;
}
