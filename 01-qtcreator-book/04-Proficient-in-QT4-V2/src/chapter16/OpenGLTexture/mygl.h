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
	GLfloat xRot, yRot, zRot;
	GLuint texture[6];

	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void loadGLTextures();
	void timerEvent(QTimerEvent *event);
	void mouseDoubleClickEvent( QMouseEvent * event );	
};

#endif /*MYGL_H_*/
