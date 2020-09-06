#include "settingconfig.h"

SettingConfig::SettingConfig()
{

}

void SettingConfig::Read(QString path){
    QString disPlayString;
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"Open failed";
    }
    QTextStream fioStream(&file);
    fioStream.setCodec("GBK");
    QString line =fioStream.readLine();
    //QString str(line);
    while(line.mid(60,13)!="END OF HEADER"){
        line=fioStream.readLine();
    }

    while(!fioStream.atEnd()){

        line =fioStream.readLine();
        if(line.mid(0,13)=="[Select Well]"){
            line =fioStream.readLine();
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!="\n"){
                    SelectWell.append(QString(line.at(i)));
                }
            }
            continue;
        }
        if(line.mid(0,17)=="[Select Position]"){
            line =fioStream.readLine();
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!="\n"){
                    SelectPosition.append(QString(line.at(i)));
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[A  Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    ASelect.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[B1 Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    B1Select.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[B2 Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    B2Select.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[B3 Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    B3Select.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[B4 Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    B4Select.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[B5 Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    B5Select.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[B6 Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    B6Select.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[C  Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    CSelect.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[D  Section]"){
            line = fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","&&QString(line.at(i))!=";"){
                    temp.append(line.at(i));
                }
                else{
                    DSelect.append(temp);
                    temp.clear();
                }
            }
            continue;
        }
        if(line.mid(0,12)=="[S  Section]"){
            line=fioStream.readLine();
            QString temp;
            for(int i=0;i<line.count();i++){
                if(QString(line.at(i))!=","){
                    temp.append(line.at(i));
                }
                else{
                    SSelect.append(temp);
                    temp.clear();
                }
            }
            continue;
        }

    }
    qDebug()<<"finished";
}
void SettingConfig::test(){
    qDebug()<<SelectWell.count()<<SelectPosition.count()<<ASelect.count()<<B1Select.count()<<B2Select.count()<<B3Select.count()<<B4Select.count()<<B5Select.count()<<B6Select.count()<<CSelect.count()<<DSelect.count()<<SSelect.count();

    for(int j=0;j<B1Select.count();j++){
        QString temp=B1Select.at(j);
        qDebug()<<temp;
    }
    for(int j=0;j<SelectWell.count();j++){
        QString temp=SelectWell.at(j);
        qDebug()<<temp;
    }
    for(int j=0;j<SelectPosition.count();j++){
        QString temp=SelectPosition.at(j);
        qDebug()<<temp;
    }

}
void SettingConfig::Write(QString path){

    QFile openfile(path);
    if(!openfile.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        qDebug()<<"cant open";
    }

    QTextStream saveText(&openfile);
    //前面写头
    saveText<<qSetFieldWidth(73)<<QString("END OF HEADER")<<endl<<qSetFieldWidth(0);
    saveText<<QString("[Select Well]")<<endl;
    for(int i=0;i<SelectWell.count();i++){
        saveText<<QString(SelectWell.at(i))<<",";
    }
    saveText<<endl<<QString("[Select Position]")<<endl;
    for(int i=0;i<SelectPosition.count();i++){
        saveText<<QString(SelectPosition.at(i))<<",";
    }
    saveText<<endl<<QString("[A  Section]")<<endl;
    for(int i=0;i<ASelect.count();i++){
        saveText<<QString(ASelect.at(i))<<",";
    }
    saveText<<endl<<QString("[B1 Section]")<<endl;
    for(int i=0;i<B1Select.count();i++){
        saveText<<QString(B1Select.at(i))<<",";
    }
    saveText<<endl<<QString("[B2 Section]")<<endl;
    for(int i=0;i<B2Select.count();i++){
        saveText<<QString(B2Select.at(i))<<",";
    }
    saveText<<endl<<QString("[B3 Section]")<<endl;
    for(int i=0;i<B3Select.count();i++){
        saveText<<QString(B3Select.at(i))<<",";
    }
    saveText<<endl<<QString("[B4 Section]")<<endl;
    for(int i=0;i<B4Select.count();i++){
        saveText<<QString(B4Select.at(i))<<",";
    }
    saveText<<endl<<QString("[B5 Section]")<<endl;
    for(int i=0;i<B5Select.count();i++){
        saveText<<QString(B5Select.at(i))<<",";
    }
    saveText<<endl<<QString("[B6 Section]")<<endl;
    for(int i=0;i<B6Select.count();i++){
        saveText<<QString(B6Select.at(i))<<",";
    }
    saveText<<endl<<QString("[C  Section]")<<endl;
    for(int i=0;i<CSelect.count();i++){
        saveText<<QString(CSelect.at(i))<<",";
    }
    saveText<<endl<<QString("[D  Section]")<<endl;
    for(int i=0;i<DSelect.count();i++){
        saveText<<QString(DSelect.at(i))<<",";
    }
    saveText<<endl<<QString("[S  Section]")<<endl;
    for(int i=0;i<SSelect.count();i++){
        saveText<<QString(SSelect.at(i))<<",";
    }
}

