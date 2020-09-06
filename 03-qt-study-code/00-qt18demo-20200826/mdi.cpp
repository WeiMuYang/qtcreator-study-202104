#include "mdi.h"
#include "ui_mdi.h"
#include <QFileDialog>

Mdi::Mdi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mdi)
{

    ui->setupUi(this);
    MdiInit();
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openConfig()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeShowTable()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(save()));
    connect(ui->actionSaveAs,SIGNAL(triggered(bool)),this,SLOT(saveAs()));
}

Mdi::~Mdi()
{
    delete ui;
}
void Mdi::MdiInit(){

    hasRead=false;
    ui->toolBar->addAction(ui->actionNew);
    ui->toolBar->addAction(ui->actionOpen);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionSave);
    ui->toolBar->addAction(ui->actionSaveAs);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(ui->cobwidget);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
void Mdi::openConfig(){
    QString filePathName=QFileDialog::getOpenFileName(this,"Load Dialog","",("*.conf"));
    if(filePathName.isEmpty()){
        return;
    }
    MdiConfig.Read(filePathName);
    hasPath=filePathName;
    hasRead=true;
}
void Mdi::loadTable(){

}
//保存
void Mdi::save(){
    if(hasRead==false)
        return;
    tableSave();
    MdiConfig.Write(hasPath);
}
//另存为
void Mdi::saveAs(){
    tableSave();
    QString filePathName;
    QString defaultFileName="DeFaultName.conf";
    QFileDialog * Dialog =new QFileDialog(this,"Save Dialog","");
    QFileInfo fileinfo(defaultFileName);
    Dialog->setAcceptMode(QFileDialog::AcceptSave);
    Dialog->selectFile(defaultFileName);
    Dialog->setNameFilter("Config Flies(*.conf)");
    Dialog->setDefaultSuffix(".conf");


    if(Dialog->exec()==QDialog::Accepted){
        filePathName=Dialog->selectedFiles().at(0);
    }
    if(filePathName.isEmpty()){
        return;
    }
    fileinfo=QFileInfo(filePathName);
    if(fileinfo.suffix()!="conf")
        filePathName+=".conf";
    MdiConfig.Write(filePathName);
}
void Mdi::newConfig(){

}
void Mdi::tableClear(){
    ui->tableWidget->clear();
    QStringList horizonHead;
    horizonHead<<("名称")<<("备注");
    ui->tableWidget->setHorizontalHeaderLabels(horizonHead);
}
void Mdi::tableSave(){
    switch(lastArea){
    case A:{
        for(int i=0;i<6;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.ASelect[i]=tempSave;
        }
        break;
    }
    case B1:{
        for(int i=0;i<12;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.B1Select[i]=tempSave;
        }
        break;
    }
    case B2:{
        for(int i=0;i<12;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.B2Select[i]=tempSave;
        }
        break;
    }
    case B3:{
        for(int i=0;i<12;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.B3Select[i]=tempSave;
        }
        break;
    }
    case B4:{
        for(int i=0;i<12;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.B4Select[i]=tempSave;
        }
        break;
    }
    case B5:{
        for(int i=0;i<12;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.B5Select[i]=tempSave;
        }
        break;
    }
    case B6:{
        for(int i=0;i<12;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.B2Select[i]=tempSave;
        }
        break;
    }
    case C:{
        for(int i=0;i<15;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.CSelect[i]=tempSave;
        }
        break;
    }
    case D:{
        for(int i=0;i<30;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.DSelect[i]=tempSave;
        }
        break;
    }
    case S:{
        for(int i=0;i<18;i++){
            QString tempSave=ui->tableWidget->item(i,0)->text();
            MdiConfig.SSelect[i]=tempSave;
        }
        break;
    }
    }
}
void Mdi::tableShow(area selectArea){
    switch(selectArea){
    case A:{
        tableSave();
        tableClear();
        QString head("A-");
        for(int i=0;i<MdiConfig.ASelect.count();i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.ASelect.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);

        }
        setUnableSelect(selectArea);
        break;
    }
    case B1:{
        tableSave();
        tableClear();
        int Count=MdiConfig.B1Select.count();
        QString head("B-1-");
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.B1Select.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);

        }
        setUnableSelect(selectArea);
        break;
    }
    case B2:{
        tableSave();
        tableClear();
        int Count=MdiConfig.B2Select.count();
        QString head("B-2-");
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.B2Select.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);

        }
        setUnableSelect(selectArea);
        break;
    }
    case B3:{
        tableSave();
        tableClear();
        int Count=MdiConfig.B3Select.count();
        QString head="B-3-";
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.B3Select.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);

        }
        setUnableSelect(selectArea);
        break;
    }
    case B4:{
        tableSave();
        tableClear();
        int Count=MdiConfig.B4Select.count();
        QString head="B-4-";
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.B4Select.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
        setUnableSelect(selectArea);
        break;
    }
    case B5:{
        tableSave();
        tableClear();
        int Count=MdiConfig.B5Select.count();
        QString head="B-5-";
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.B5Select.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
        setUnableSelect(selectArea);
        break;
    }
    case B6:{
        tableSave();
        tableClear();
        int Count=MdiConfig.B6Select.count();
        QString head="B-6-";
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.B6Select.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
        setUnableSelect(selectArea);
        break;
    }
    case C:{
        tableSave();
        tableClear();
        int Count=MdiConfig.CSelect.count();
        QString head="C-";
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.CSelect.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
        setUnableSelect(selectArea);
        break;
    }
    case D:{
        tableSave();
        tableClear();
        int Count=MdiConfig.DSelect.count();
        QString head="D-";
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.DSelect.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            QString temp=head+QString::number(i+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
        setUnableSelect(selectArea);
        break;
    }
    case S:{
        tableSave();
        tableClear();
        int Count=MdiConfig.SSelect.count();
        QString head="S1-";
        int tempCount=0;
        for(int i=0;i<Count;i++){
            QTableWidgetItem *item=new QTableWidgetItem;
            item->setText(QString(MdiConfig.SSelect.at(i)));
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
            if( i == 4 ){
                head = "S2-";
                tempCount = 0;
            }
            else if(i==6){
                head = "S3-";
                tempCount = 0;
            }
            else if(i == 9){
                head = "S4-";
                tempCount = 0;
            }
            else if(i == 11){
                head = "S5-";
                tempCount=0;
            }
            else if(i == 12){
                head = "S6-";
                tempCount=0;
            }
            else if(i == 14){
                head = "S7-";
                tempCount=0;
            }
            else if(i == 16){
                head = "S8-";
                tempCount=0;
            }
            QString temp=head+QString::number(tempCount+1);
            QTableWidgetItem *item2=new QTableWidgetItem;
            item2->setText(temp);
            item2->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,1,item2);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
            tempCount++;
        }
        setUnableSelect(selectArea);
        break;
    }
    case Null:{
        tableSave();
        tableClear();
        break;
    }
    }



}
void Mdi::changeShowTable(){
    if(hasRead==false)
        return;
    int index=ui->comboBox->currentIndex();
    switch(index){
    case 0:

        tableShow(Null);
        lastArea=Null;
        break;
    case 1:
        tableShow(A);
        lastArea=A;
        break;
    case 2:
        tableShow(B1);
        lastArea=B1;
        break;
    case 3:
        tableShow(B2);
        lastArea=B2;
        break;
    case 4:
        tableShow(B3);
        lastArea=B3;
        break;
    case 5:
        tableShow(B4);
        lastArea=B4;
        break;
    case 6:
        tableShow(B5);
        lastArea=B5;
        break;
    case 7:
        tableShow(B6);
        lastArea=B6;
        break;
    case 8:
        tableShow(C);
        lastArea=C;
        break;
    case 9:
        tableShow(D);
        lastArea=D;
        break;
    case 10:
        tableShow(S);
        lastArea=S;
        break;
    }

}
void Mdi::on_actionNew_triggered()
{
    newConfig();
}
void Mdi::setUnableSelect(area Select){
    int Count;
    switch(Select){
    case A:{
        Count=6;
        break;
    }
    case B1:{
        Count=12;
        break;
    }
    case B2:{
        Count=12;
        break;
    }
    case B3:{
        Count=12;
        break;
    }
    case B4:{
        Count=12;
        break;
    }
    case B5:{
        Count=12;
        break;
    }
    case B6:{
        Count=12;
        break;
    }
    case C:{
        Count=15;
        break;
    }
    case D:{
        Count=30;
        break;
    }
    case S:{
        Count=18;
        break;
    }
    }
    //qDebug()<<"here"<<Count;
    for(int i=Count;i<30;i++){
        for(int j=0;j<2;j++){
            QTableWidgetItem *item=new QTableWidgetItem();
            item->setFlags(item->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget->setItem(i,j,item);
        }

    }
}
