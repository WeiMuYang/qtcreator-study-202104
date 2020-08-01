#include "changesyncstatus.h"


ChangeSyncStatus::ChangeSyncStatus()
{

//    m_MovieArr[70];
//    for(int i = 0; i < 70; ++i)
//        m_MovieArr[i] = 0;

//    m_indexOfMovieArr = 0;
}

bool ChangeSyncStatus::ChangeBulb(WellsData well, const QString bulbName, int status)
{
    QString temp=bulbName;
    temp.remove(0,2);
    int Num=temp.toInt();
    if(Num==28){
        ChangePanBulb(well,status);
    }
    else if(Num>28){
        ChangeSwitchBulb(well,Num,status);
    }
    else{
        ChangeLightBulb(well,Num,status);
    }
    return true;
}
void ChangeSyncStatus::ChangePanBulb(WellsData well, int status){
    QString path;
    switch(status)
    {
    case 0:{
        //灰色
        path=QStringLiteral("border-image: url(:/img/pie-NF.png);");
        break;
    }
    case 1:{
        //绿30
        path=QStringLiteral("border-image: url(:/img/pie30.png);");
        break;
    }
    case 2:{
        //绿60
        path=QStringLiteral("border-image: url(:/img/pie60.png);");
        break;
    }
    case 3:{
        //绿100
        path=QStringLiteral("border-image: url(:/img/pie100.png);");
        break;
    }
    case 4:{
        //红100
        path=QStringLiteral("border-image: url(:/img/pie100-red.png);");
        break;
    }
    }
    well.m_DetailLabelOfWell_08.at(1)->setStyleSheet(path);
    well.m_LabelOfWell_22.at(16)->setStyleSheet(path);
}
void ChangeSyncStatus::ChangeSwitchBulb(WellsData well, int Num, int status)
{   QString path;
    switch(status){
    case 0:{
        //灰关闭
        path=QStringLiteral("border-image: url(:/img/Off-NP.png);");
        break;
    }
    case 1:{
        //绿开
        path=QStringLiteral("border-image: url(:/img/On.png);");
        break;
    }
    case 2:{
        //红关闭
        path=QStringLiteral("border-image: url(:/img/Off.png);");
        break;
    }
    }

    if(Num==29){
        well.m_DetailLabelOfWell_09.at(1)->setStyleSheet(path);
        well.m_LabelOfWell_22.at(18)->setStyleSheet(path);
    }
    else{
        well.m_DetailLabelOfWell_10.at(1)->setStyleSheet(path);
        well.m_LabelOfWell_22.at(20)->setStyleSheet(path);
    }
}

bool ChangeSyncStatus::ChangeTable(WellsData well, const QString TableName, const int row, const int col, const QString text, QColor background)
{

    //  TableName: title   content
    int red = background.red();
    int green = background.green();
    int blue = background.blue();

    if(TableName=="title"){
        if(red!=0 || green!=0 || blue!=0){
            well.m_TableOfWell_2.at(0)->item(row,col)->setBackground(background);
            well.m_DetailTableOfWell_2.at(0)->item(row,col)->setBackground(background);
        }
        well.m_TableOfWell_2.at(0)->item(row,col)->setText(text);
        well.m_DetailTableOfWell_2.at(0)->item(row,col)->setText(text);

    }
    else{
        //Detai Table表的对应关系更改
        if(row==2&&col>0){
            QTableWidgetItem *item2=new QTableWidgetItem(text);
            well.m_DetailTableOfWell_2.at(1)->setItem(row+1,col-1,item2);
        }
        QTableWidgetItem *item=new QTableWidgetItem(text);
        well.m_TableOfWell_2.at(1)->setItem(row,col,item);

    }
    return true;
}
void ChangeSyncStatus::ChangeLightBulb(WellsData well, int Num, int status){
    QString pathGif, pathPng;
    switch(status){
    case 0:{
        //灰
        pathGif = ":/img/false.gif";
        pathPng=QStringLiteral("border-image: url(:/img/false.png);");
        break;
    }
    case 1:{
        //绿
        pathGif = ":/img/true.gif";
        pathPng=QStringLiteral("border-image: url(:/img/true.png);");
        break;
    }
    case 2:{
        //黄
        pathGif = ":/img/warning.gif";
        pathPng=QStringLiteral("border-image: url(:/img/warning.png);");
        break;
    }
    case 3:{
        //红
        pathGif = ":/img/error.gif";
        pathPng=QStringLiteral("border-image: url(:/img/error.png);");

        break;
    }
    }
    QSize si1(well.m_DetailLabelOfWell_01.at(0)->width(),well.m_DetailLabelOfWell_01.at(0)->height());
//    QSize si2(well.m_LabelOfWell_22.at(0)->width(),well.m_LabelOfWell_22.at(0)->height());
    QMovie *movie1 = new QMovie(pathGif);
//    QMovie *movie2 = new QMovie(pathGif);
    movie1->setScaledSize(si1);
//    movie2->setScaledSize(si2);

    switch(Num){
    case 1:{
        //D-1
        well.m_DetailLabelOfWell_01.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_01.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(0)->setStyleSheet(pathPng);

        break;
    }
    case 9:{
        //D-9
        well.m_DetailLabelOfWell_02.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_02.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(2)->setStyleSheet(pathPng);
        break;
    }
    case 12:{
        //D-12
        well.m_DetailLabelOfWell_03.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_03.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(4)->setStyleSheet(pathPng);
        break;
    }
    case 15:{
        //D-15
        well.m_DetailLabelOfWell_04.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_04.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(6)->setStyleSheet(pathPng);
        break;
    }
    case 18:{
        //D-18
        well.m_DetailLabelOfWell_05.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_05.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(10)->setStyleSheet(pathPng);
        break;
    }
    case 21:{
        //D-21
        well.m_DetailLabelOfWell_06.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_06.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(12)->setStyleSheet(pathPng);
        break;
    }
    case 25:{
        //D-25
        well.m_DetailLabelOfWell_07.at(0)->setMovie(movie1);
        well.m_DetailLabelOfWell_07.at(0)->show();
        movie1->start();
        well.m_LabelOfWell_22.at(14)->setStyleSheet(pathPng);
        break;
    }
    }

}
