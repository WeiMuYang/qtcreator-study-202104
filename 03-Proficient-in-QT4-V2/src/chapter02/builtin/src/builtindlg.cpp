// chapter2/builtin/src/builtindlg.cpp.
#include <QtGui/QtGui>
#include "builtindlg.h"

CBuiltinDlg::CBuiltinDlg(QWidget* parent)
 :	QDialog(parent)
{
	displayTextEdit = new QTextEdit(tr("Qt�ı�׼ͨ�öԻ���"));

	QGridLayout* gridLayout = new QGridLayout;
	colorPushBtn 	= new QPushButton(tr("��ɫ�Ի���"));
	errorPushBtn 	= new QPushButton(tr("������Ϣ��"));
	filePushBtn 	= new QPushButton(tr("�ļ��Ի���"));
	fontPushBtn 	= new QPushButton(tr("����Ի���"));
	inputPushBtn 	= new QPushButton(tr("����Ի���"));
	pagePushBtn 	= new QPushButton(tr("ҳ���öԻ���"));
	progressPushBtn 	= new QPushButton(tr("���ȶԻ���"));
	printPushBtn	= new QPushButton(tr("��ӡ�Ի���"));
	gridLayout->addWidget(colorPushBtn, 0, 0, 1, 1);
	gridLayout->addWidget(errorPushBtn, 0, 1, 1, 1);
	gridLayout->addWidget(filePushBtn, 0, 2, 1, 1);
	gridLayout->addWidget(fontPushBtn, 1, 0, 1, 1);
	gridLayout->addWidget(inputPushBtn, 1, 1, 1, 1);
	gridLayout->addWidget(pagePushBtn, 1, 2, 1, 1);
	gridLayout->addWidget(progressPushBtn, 2, 0, 1, 1);
	gridLayout->addWidget(printPushBtn, 2, 1, 1, 1);
	gridLayout->addWidget(displayTextEdit, 3, 0, 3, 3);

	setLayout(gridLayout);

 	connect(colorPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
 	connect(errorPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
	connect(filePushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
 	connect(fontPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
	connect(inputPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
 	connect(pagePushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
	connect(progressPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
	connect(printPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
	setWindowTitle(tr("�Ƚ��Ի���"));
	resize(400, 300);
}
void CBuiltinDlg::doPushBtn()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());
	if(btn == colorPushBtn)
	{// ��ɫ�Ի���.
		QPalette palette = displayTextEdit->palette();	
		const QColor& color 
			= QColorDialog::getColor(palette.color(QPalette::Base), this);
		if(color.isValid())
		{
			palette.setColor(QPalette::Base, color);
			displayTextEdit->setPalette(palette);	
		}
	}
else if(btn == errorPushBtn)
	{// ������Ϣ��.
		QErrorMessage box(this);
		box.setWindowTitle(tr("������Ϣ��"));
		box.showMessage(tr("������Ϣ��ʵ��xx��"));
		box.showMessage(tr("������Ϣ��ʵ��xx��"));
		box.showMessage(tr("������Ϣ��ʵ��xx��"));
		box.showMessage(tr("������Ϣ��ʵ��yy��"));
		box.showMessage(tr("������Ϣ��ʵ��zz��"));
		box.exec();
	}
	else if(btn == filePushBtn)
	{// �ļ��Ի���.
		QString fileName = QFileDialog::getOpenFileName(this, 
												tr("���ļ�"),
                                                "/usr/local/Trolltech",
                                                tr("�κ��ļ�(*.*)"
													";;�ı��ļ�(*.txt)"
													";;XML�ļ�(*.xml)"));
		displayTextEdit->setText(fileName);
	}
	else if(btn == fontPushBtn)
	{// ����Ի���.
		bool ok;
		const QFont& font = QFontDialog::getFont(&ok,
									displayTextEdit->font(),
									this,
									tr("����Ի���"));
		if(ok)
		{// ���<ȷ��>,��������.
			displayTextEdit->setFont(font);
		}
	}
	else if(btn == inputPushBtn)
	{// ����Ի���.
		bool ok;
     	QString text = QInputDialog::getText(this, 
											tr("����Ի���"),
                                          	tr("�����ı���"), 
											QLineEdit::Normal,
                                          	QDir::home().dirName(), 
&ok);
     if (ok && !text.isEmpty())
         displayTextEdit->setText(text);
	}
	else if(btn == pagePushBtn)
	{// ҳ���öԻ���.
		QPrinter printer;
		QPageSetupDialog dlg(&printer, this);
		dlg.setWindowTitle(tr("ҳ���öԻ���"));
		if (dlg.exec() == QDialog::Accepted) 
		{
			// ������һ���Ĵ���
 		}	
	} 
	else if(btn == progressPushBtn)
	{// ���ȶԻ���.
		QProgressDialog progress(tr("���ڸ����ļ�..."), tr("ȡ��"), 0, 10000, this);
		progress.setWindowModality(Qt::WindowModal);
		progress.setWindowTitle(tr("���ȶԻ���"));
		progress.show();
		for (int i = 0; i < 10000; i++) 
{
			progress.setValue(i);
			qApp->processEvents();	
			if (progress.wasCanceled())
				break;
			//... �����ļ�����
			qDebug() << i;
		}
		progress.setValue(10000);
	}

	else if(btn == printPushBtn)
	{// ��ӡ�Ի���.
		QPrinter printer;
		QPrintDialog dlg(&printer, this);
		dlg.setWindowTitle(tr("��ӡ�Ի���"));
		if (dlg.exec() == QDialog::Accepted) 
		{
			// ������һ���Ĵ���
 		}
	}
}
