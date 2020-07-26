#include <QtGui>
#include <QtOpenGL>
#include <math.h>

#include "mygl.h"

const GLfloat PI = 3.1415926536f;

MyGLWidget::MyGLWidget(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
{
	setMinimumSize(320,240);
	resize(640,480);
	setWindowTitle(tr("第一个OpenGL程序"));
	short angle = 18;
   	for(short i=0; i<5; i++) {
		Point[i][0] = cos(angle * PI/180);
		Point[i][1] = sin(angle * PI/180);
		Point[i][2] = 0.0;
		angle += 72;
   	}
}

MyGLWidget::~MyGLWidget()
{
}

	
void MyGLWidget::initializeGL()
{
	//glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Point);
}

void MyGLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glTranslatef( -1.5,  0.0, -6.0 );
	glBegin( GL_TRIANGLES );
		glVertex3f(  0.0,  1.0,  0.0 );
	    glVertex3f( -1.0, -1.0,  0.0 );
	    glVertex3f(  1.0, -1.0,  0.0 );
	glEnd();
	glTranslatef(  3.0,  0.0,  0.0 );
	
	//glDrawArrays(GL_LINE_LOOP, 0, 5);
	
	glBegin(GL_LINE_LOOP);
		glArrayElement(1);
		glArrayElement(4);
		glArrayElement(2);
		glArrayElement(0);
		glArrayElement(3);
	glEnd();
	
	/*glBegin(GL_LINE_LOOP);
		glVertex3f(Point[1][0], Point[1][1], Point[1][2]);
		glVertex3f(Point[4][0], Point[4][1], Point[4][2]);
		glVertex3f(Point[2][0], Point[2][1], Point[2][2]);
		glVertex3f(Point[0][0], Point[0][1], Point[0][2]);
		glVertex3f(Point[3][0], Point[3][1], Point[3][2]);
    glEnd();*/
	
	/*glBegin( GL_QUADS );
		glVertex3f( -1.0,  1.0,  0.0 );
		glVertex3f(  1.0,  1.0,  0.0 );
		glVertex3f(  1.0, -1.0,  0.0 );
		glVertex3f( -1.0, -1.0,  0.0 );
	glEnd();*/
}

void MyGLWidget::resizeGL(int width, int height)
{
	glViewport( 0, 0, (GLint)width, (GLint)height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();	
}

void MyGLWidget::mouseDoubleClickEvent( QMouseEvent * event )
{
	if(windowState() &  Qt::WindowFullScreen)
		showNormal();
	else
		showFullScreen();
}

	
