#include <QApplication>
#include <QTextCodec>
#include <QtGui>
#include <QtSvg>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

	QSvgGenerator svgGen;
	svgGen.setFileName("test.svg");

	QRectF rectangle(10.0, 20.0, 80.0, 60.0);
	QPainter painter;
	painter.begin(&svgGen);
	QPen pen(Qt::red);
	painter.setPen(pen);
	painter.drawEllipse(rectangle);
	rectangle.moveRight(100);
	painter.drawRect(rectangle);
	
	rectangle.moveRight(100);
 	QRectF source(0.0, 0.0, 70.0, 40.0);
 	QImage image("Greenstone.bmp");
	painter.drawImage(rectangle, image, source);
	 
	painter.end();
	
	return 0;
}
