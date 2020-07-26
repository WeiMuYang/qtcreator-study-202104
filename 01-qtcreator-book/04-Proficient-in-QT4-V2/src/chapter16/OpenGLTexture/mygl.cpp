#include <QtGui>
#include <QtOpenGL>

#include "mygl.h"

MyGLWidget::MyGLWidget(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
{
	xRot = yRot = zRot =0.0;
	setMinimumSize(320,240);
	resize(640,480);
	setWindowTitle(tr("OpenGLŒ∆¿Ì"));
	startTimer(500);
}

MyGLWidget::~MyGLWidget()
{
}

	
void MyGLWidget::initializeGL()
{
	loadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.5);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void MyGLWidget::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glTranslatef( 0.0,  0.0, -5.0 );
	glRotatef( xRot,  1.0,  0.0,  0.0 );
	glRotatef( yRot,  0.0,  1.0,  0.0 );
	glRotatef( zRot,  0.0,  0.0,  1.0 );

	glBindTexture( GL_TEXTURE_2D, texture[0] );
	glBegin( GL_QUADS );
		// front
	    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
	    glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
	    glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
	    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
	glEnd();

	glBindTexture( GL_TEXTURE_2D, texture[1] );
	glBegin( GL_QUADS );
		// back
	    glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
	    glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
	    glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
	    glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
	glEnd();

	glBindTexture( GL_TEXTURE_2D, texture[2] );
	glBegin( GL_QUADS );
		// top
	    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
	    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0,  1.0,  1.0 );
	    glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0,  1.0,  1.0 );
	    glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
	glEnd();

	glBindTexture( GL_TEXTURE_2D, texture[3] );
	glBegin( GL_QUADS );
		// bottom
	    glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0, -1.0, -1.0 );
	    glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0, -1.0, -1.0 );
	    glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
	    glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
	glEnd();

	glBindTexture( GL_TEXTURE_2D, texture[4] );
	glBegin( GL_QUADS );
		// right 
	    glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
	    glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
	    glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
	    glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
	glEnd();

	glBindTexture( GL_TEXTURE_2D, texture[5] );
	glBegin( GL_QUADS );
		// left
	    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
	    glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
	    glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
	    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
	glEnd();  
}

void MyGLWidget::timerEvent(QTimerEvent *event)
{
	xRot += 0.3;
	yRot += 0.2;
	zRot += 0.4;
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

void MyGLWidget::loadGLTextures()
{
	QImage tex, buffer;
	QString fileName(":texture%1.bmp");

	glGenTextures(6, &texture[0]);

	for(short i=0; i<6; i++) {
		buffer.load(fileName.arg(i+1));
		tex = QGLWidget::convertToGLFormat( buffer );	
		glBindTexture( GL_TEXTURE_2D, texture[i] );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex.width(), tex.height(), 0,
	      GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
	 	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	  	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); 	      
	}
}

