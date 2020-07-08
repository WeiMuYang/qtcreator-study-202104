#include <QtGui>
#include <QDebug>
#include "ctrlform.h"

CCtrlForm::CCtrlForm(QWidget* parent)
 :	QWidget(parent)
{
	setupUi(this);
	
	m_pWidget = new QWidget(0, Qt::Widget);
	QPushButton* btn = new QPushButton(tr("¹Ø±Õ"));
	connect(btn, SIGNAL(clicked()), m_pWidget, SLOT(close()));
	QTextEdit* edit = new QTextEdit(tr("Îäºº»¶Ó­Äú!"));
	
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(edit);
	layout->addWidget(btn);
	m_pWidget->setLayout(layout);
	m_pWidget->resize(200, 100);
	m_pWidget->move(400, 500);
	m_pWidget->show();
	
	widgetRadioBtn->setChecked(true);
	nullRadioBtn->setChecked(true);	
	xSpinBox->setRange(-100, 100);
	ySpinBox->setRange(-100, 100);
	
	
	connect(widgetRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(windowRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(dialogRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(sheetRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(drawerRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(popupRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(toolRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(tooltipRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(splashscreenRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(subwindowRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
		
	connect(fsdialogCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(owndcCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(managerCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(framelessCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));	
	connect(customizeCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(titleCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(menuCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(minCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));	
	connect(maxCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(minmaxCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(helpCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	connect(shadeCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));	
	connect(topCheckBox, SIGNAL(clicked()),
		this, SLOT(doClicked()));
	
	connect(nullRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
	connect(thisRadioBtn, SIGNAL(clicked()), 
		this, SLOT(doClicked()));
		
	connect(xSpinBox, SIGNAL(valueChanged(int)), 
		this, SLOT(doSpinBoxChanged(int)));
	connect(ySpinBox, SIGNAL(valueChanged(int)), 
		this, SLOT(doSpinBoxChanged(int)));
	
	move(500, 400);
	
}

void CCtrlForm::doClicked()
{	
	QPoint 	position = m_pWidget->pos();
	QSize	sz	= m_pWidget->size();
	
	QRadioButton* btn = qobject_cast<QRadioButton*>(sender());	
	if(btn == nullRadioBtn)
		m_pWidget->setParent(0);
	else if(btn == thisRadioBtn)
		m_pWidget->setParent(this);	
	
	Qt::WindowFlags flags = 0;
	if(widgetRadioBtn->isChecked())
		flags = Qt::Widget;
	else if(windowRadioBtn->isChecked())
		flags = Qt::Window;
	else if(dialogRadioBtn->isChecked())
		flags = Qt::Dialog;
	else if(sheetRadioBtn->isChecked())
		flags = Qt::Sheet;
	else if(drawerRadioBtn->isChecked())
		flags = Qt::Drawer;
	else if(popupRadioBtn->isChecked())
		flags = Qt::Popup;
	else if(toolRadioBtn->isChecked())
		flags = Qt::Tool;
	else if(tooltipRadioBtn->isChecked())
		flags = Qt::ToolTip;
	else if(splashscreenRadioBtn->isChecked())
		flags = Qt::SplashScreen;
	else if(subwindowRadioBtn->isChecked())
		flags = Qt::SubWindow;
	
	if(fsdialogCheckBox->isChecked())
		flags |= Qt::MSWindowsFixedSizeDialogHint;
	if(owndcCheckBox->isChecked())
		flags |= Qt::MSWindowsOwnDC;
	if(managerCheckBox->isChecked())
		flags |= Qt::X11BypassWindowManagerHint;
	if(framelessCheckBox->isChecked())
		flags |= Qt::FramelessWindowHint;
	if(customizeCheckBox->isChecked())
		flags |= Qt::CustomizeWindowHint;
	if(titleCheckBox->isChecked())
		flags |= Qt::WindowTitleHint;
	if(menuCheckBox->isChecked())
		flags |= Qt::WindowSystemMenuHint;
	if(minCheckBox->isChecked())
		flags |= Qt::WindowMinimizeButtonHint;
	if(maxCheckBox->isChecked())
		flags |= Qt::WindowMaximizeButtonHint;
	if(minmaxCheckBox->isChecked())
		flags |= Qt::WindowMinMaxButtonsHint;
	if(helpCheckBox->isChecked())
		flags |= Qt::WindowContextHelpButtonHint;
	if(shadeCheckBox->isChecked())
		flags |= Qt::WindowShadeButtonHint;
	if(topCheckBox->isChecked())
		flags |= Qt::WindowStaysOnTopHint;
	
	
	m_pWidget->setWindowFlags(flags);
	if(widgetRadioBtn->isChecked() 
		&& thisRadioBtn->isChecked())
	{
		position = QPoint(0, 0);
	}
	m_pWidget->show();
	m_pWidget->resize(sz);
	m_pWidget->move(position);	

	
}

void CCtrlForm::doSpinBoxChanged(int value)
{
	QSpinBox* box = qobject_cast<QSpinBox*>(sender());
	int x = m_pWidget->x();
	int y = m_pWidget->y();
	
	if(box == xSpinBox)
		x += value;	
	else if(box == ySpinBox)
		y += value;
		
	m_pWidget->move(x, y);
	m_pWidget->show();
}





