#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string = tr("标题太长，需要进行省略！");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight,180);
    ui->label->setText(str);

    ui->label->setPixmap(QPixmap("F:/GithubRepository/WeiMuYang/skill-learning-improve/01-qtcreator/01-Qt-creator-quick-start/src/03/3-8/logo.png"));
//    QMovie *movie = new QMovie("F:/GithubRepository/WeiMuYang/skill-learning-improve/01-qtcreator/01-Qt-creator-quick-start/src/03/3-8/donghua.gif");
//    ui->label->setMovie(movie);
//    movie->start();
}

MyWidget::~MyWidget()
{
    delete ui;
}
