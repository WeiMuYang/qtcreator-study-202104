#include <math.h>
#include <QtGui>
#include <QtOpenGL>

#include "mygl.h"

const short n = 50;
const GLfloat PI = 3.1415926536f; 	

MyGLWidget::MyGLWidget(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
{
	setMinimumSize(320,240);
	resize(640,480);
	setWindowTitle(tr("OpenGL×ÅÉ«"));
}

MyGLWidget::~MyGLWidget()
{
}

	
void MyGLWidget::initializeGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void MyGLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glTranslatef( -1.5,  0.0, -6.0 );
	glBegin( GL_TRIANGLES );
		glColor3f( 0.0, 0.0, 1.0 );		// blue
		glVertex3f(  0.0,  1.0,  0.0 );
		glColor3f( 1.0, 0.0, 0.0 );		// red
	    glVertex3f( -1.0, -1.0,  0.0 );
		glColor3f( 0.0, 1.0, 0.0 );		// green
	    glVertex3f(  1.0, -1.0,  0.0 );
	glEnd();
	glTranslatef(  3.0,  0.0,  0.0 );
	
	glBegin(GL_POLYGON);
		GLfloat part;
    	for(short i=0; i<n; ++i) {
    		part = 1.0/n * i;
    		glColor3f(1.0, part, part);
        	glVertex3f(1*cos(2*PI*part), 1*sin(2*PI*part), 0.0);
    	}
    glEnd();
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

	
