#include <QtGui>
#include <QtOpenGL>

#include "mygl.h"


MyGLWidget::MyGLWidget(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
{
	rTri = 0.0;
	rQuad = 0.0;
	setMinimumSize(320,240);
	resize(640,480);
	setWindowTitle(tr("OpenGLÐý×ª"));
	startTimer(500);
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
	glEnable(GL_LINE_SMOOTH_HINT);
	glEnable(GL_POLYGON_SMOOTH_HINT);
	glDepthFunc(GL_LEQUAL);
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

void MyGLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glTranslatef( -1.5,  0.0, -6.0 );
	glRotatef(rTri, 0.0, 1.0, 0.0);
	glBegin( GL_TRIANGLES );
		glColor3f( 0.0, 0.0, 1.0 );		// blue
		glVertex3f(  0.0,  1.0,  0.0 );
		glColor3f( 1.0, 0.0, 1.0 );		// red
	    glVertex3f( -1.0, -1.0,  0.0 );
		glColor3f( 0.0, 1.0, 1.0 );		// green
	    glVertex3f(  1.0, -1.0,  0.0 );
	glEnd();
	
	glTranslatef(  3.0,  0.0,  0.0 );
	glRotatef(rQuad, 1.0, 0.0, 0.0);
	glBegin( GL_QUADS );
		glColor3f( 1.0, 1.0, 0.0 );		// yellow
		glVertex3f( -1.0,  1.0,  0.0 );
		glColor3f( 0.0, 1.0, 1.0 );		//cyan
		glVertex3f(  1.0,  1.0,  0.0 );
		glColor3f( 1.0, 0.0, 1.0 );		// magenta
		glVertex3f(  1.0, -1.0,  0.0 );
		glColor3f( 1.0, 1.0, 1.0 );		// white
		glVertex3f( -1.0, -1.0,  0.0 );
	glEnd();	
}

void MyGLWidget::timerEvent(QTimerEvent *event)
{
	rTri += 1;
	rQuad -= 0.15;	
	update();
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

	
