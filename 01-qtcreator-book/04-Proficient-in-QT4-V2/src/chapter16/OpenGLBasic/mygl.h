#ifndef MYGL_H_
#define MYGL_H_

#include <QtGui>
#include <QtOpenGL>

class MyGLWidget : public QGLWidget
{
	Q_OBJECT
	
public:
	MyGLWidget(QWidget * parent = 0, const QGLWidget * shareWidget = 0, Qt::WindowFlags f = 0);
	~MyGLWidget();
	
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mouseDoubleClickEvent( QMouseEvent * event );

private:
	GLfloat Point[5][3];	
};

#endif /*MYGL_H_*/
