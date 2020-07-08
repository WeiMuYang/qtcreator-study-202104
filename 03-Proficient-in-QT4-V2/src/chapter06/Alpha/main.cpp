#include <QApplication>
#include <QtGui>
#include <QTextCodec>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
protected:
	void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    int x,y;
    QPixmap pixmap;
    QPixmap background;
};
// 在构造函数中装入背景图
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
	resize(800,600);
	pixmap = QPixmap(100,50);
	background = QPixmap("background.jpg");
	x = -1;
	y = -1;
}
// 鼠标移动时形成一个pixmap
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
	x = event->x();
	y = event->y();
	pixmap.fill(QColor(255,255,255,127));
	QPainter painter(&pixmap);
	painter.setPen(QColor(255,0,0));
	painter.drawText(20, 40, QString("%1").arg(x) + "," + 
		QString("%1").arg(y));
	update();	
}
// 绘制背景图和透明的pixmap
void MyWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, background);
	painter.drawPixmap(x, y, pixmap);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    MyWidget widget;
    widget.setMouseTracking(true);
    widget.show();
    return app.exec();
}
