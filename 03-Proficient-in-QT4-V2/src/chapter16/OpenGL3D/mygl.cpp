#include <QtGui>
#include <QtOpenGL>

#include "mygl.h"


MyGLWidget::MyGLWidget(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
{
	rTri = 0.0;
	rQuad = 0.0;
	setMinimumSize(320,240);
	resize(640,480);
	setWindowTitle(tr("OpenGL 3D"));
}

MyGLWidget::~MyGLWidget()
{
	glDeleteLists(list, 2);
}

	
void MyGLWidget::initializeGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.5);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	makeList();
	startTimer(500);
}

void MyGLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	glLoadIdentity();
	glTranslatef( -1.5,  0.0, -6.0 );
	glRotatef( rTri,  0.0,  1.0,  0.0 );
    glCallList(list);
    
    glLoadIdentity();
	glTranslatef(  1.5,  0.0, -7.0 );
	glRotatef( rQuad,  1.0,  1.0,  1.0 );
	glCallList(list + 1);
}

void MyGLWidget::makeList()
{
	list = glGenLists(2);
	glNewList(list, GL_COMPILE);
		glBegin( GL_TRIANGLES );
		    glColor3f( 1.0, 0.0, 0.0 );
		    glVertex3f(  0.0,  1.0,  0.0 );
		    glColor3f( 0.0, 1.0, 0.0 );
		    glVertex3f( -1.0, -1.0,  1.0 );
		    glColor3f( 0.0, 0.0, 1.0 );
		    glVertex3f(  1.0, -1.0,  1.0 );
		    
		    glColor3f( 1.0, 0.0, 0.0 );
		    glVertex3f(  0.0,  1.0,  0.0 );
		    glColor3f( 0.0, 0.0, 1.0 );
		    glVertex3f(  1.0, -1.0,  1.0 );
		    glColor3f( 0.0, 1.0, 0.0 );
		    glVertex3f(  1.0, -1.0, -1.0 );
	
		    glColor3f( 1.0, 0.0, 0.0 );
		    glVertex3f(  0.0,  1.0,  0.0 );
		    glColor3f( 0.0, 1.0, 0.0 );
		    glVertex3f(  1.0, -1.0, -1.0 );
		    glColor3f( 0.0, 0.0, 1.0 );
		    glVertex3f( -1.0, -1.0, -1.0 );
		    
		    glColor3f( 1.0, 0.0, 0.0 );
		    glVertex3f(  0.0,  1.0,  0.0 );
		    glColor3f( 0.0, 0.0, 1.0 );
		    glVertex3f( -1.0, -1.0, -1.0 );
		    glColor3f( 0.0, 1.0, 0.0 );
		    glVertex3f( -1.0, -1.0,  1.0 );
		glEnd();	    
	glEndList();
	
	glNewList(list + 1, GL_COMPILE);
		glBegin( GL_QUADS );
		    glColor3f( 0.0, 1.0, 0.0 );
		    glVertex3f(  1.0,  1.0, -1.0 );
		    glVertex3f( -1.0,  1.0, -1.0 );
		    glVertex3f( -1.0,  1.0,  1.0 );
		    glVertex3f(  1.0,  1.0,  1.0 );
		    
		    glColor3f( 1.0, 0.5, 0.0 );
		    glVertex3f(  1.0, -1.0,  1.0 );
		    glVertex3f( -1.0, -1.0,  1.0 );
		    glVertex3f( -1.0, -1.0, -1.0 );
		    glVertex3f(  1.0, -1.0, -1.0 );    
	  
		    glColor3f( 1.0, 0.0, 0.0 );
		    glVertex3f(  1.0,  1.0,  1.0 );
		    glVertex3f( -1.0,  1.0,  1.0 );
		    glVertex3f( -1.0, -1.0,  1.0 );
		    glVertex3f(  1.0, -1.0,  1.0 );  
	 
		    glColor3f( 1.0, 1.0, 0.0 );
		    glVertex3f(  1.0, -1.0, -1.0 );
		    glVertex3f( -1.0, -1.0, -1.0 );
		    glVertex3f( -1.0,  1.0, -1.0 );
		    glVertex3f(  1.0,  1.0, -1.0 );
	
		    glColor3f( 0.0, 0.0, 1.0 );
		    glVertex3f( -1.0,  1.0,  1.0 );
		    glVertex3f( -1.0,  1.0, -1.0 );
		    glVertex3f( -1.0, -1.0, -1.0 );
		    glVertex3f( -1.0, -1.0,  1.0 );
	
		    glColor3f( 1.0, 0.0, 1.0 );
		    glVertex3f(  1.0,  1.0, -1.0 );
		    glVertex3f(  1.0,  1.0,  1.0 );
		    glVertex3f(  1.0, -1.0,  1.0 );
		    glVertex3f(  1.0, -1.0, -1.0 );
		glEnd();  	
	glEndList();
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
