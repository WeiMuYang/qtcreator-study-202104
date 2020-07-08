// chapter2/builtin/src/builtindlg.cpp.
#include <QtGui/QtGui>
#include "builtindlg.h"

CBuiltinDlg::CBuiltinDlg(QWidget* parent)
 :	QDialog(parent)
{
	displayTextEdit = new QTextEdit(tr("Qt的标准通用对话框。"));

	QGridLayout* gridLayout = new QGridLayout;
	colorPushBtn 	= new QPushButton(tr("颜色对话框"));
	errorPushBtn 	= new QPushButton(tr("错误信息框"));
	filePushBtn 	= new QPushButton(tr("文件对话框"));
	fontPushBtn 	= new QPushButton(tr("字体对话框"));
	inputPushBtn 	= new QPushButton(tr("输入对话框"));
	pagePushBtn 	= new QPushButton(tr("页设置对话框"));
	progressPushBtn 	= new QPushButton(tr("进度对话框"));
	printPushBtn	= new QPushButton(tr("打印对话框"));
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
	setWindowTitle(tr("內建对话框"));
	resize(400, 300);
}
void CBuiltinDlg::doPushBtn()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());
	if(btn == colorPushBtn)
	{// 颜色对话框.
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
	{// 错误信息框.
		QErrorMessage box(this);
		box.setWindowTitle(tr("错误信息框"));
		box.showMessage(tr("错误信息框实例xx。"));
		box.showMessage(tr("错误信息框实例xx。"));
		box.showMessage(tr("错误信息框实例xx。"));
		box.showMessage(tr("错误信息框实例yy。"));
		box.showMessage(tr("错误信息框实例zz。"));
		box.exec();
	}
	else if(btn == filePushBtn)
	{// 文件对话框.
		QString fileName = QFileDialog::getOpenFileName(this, 
												tr("打开文件"),
                                                "/usr/local/Trolltech",
                                                tr("任何文件(*.*)"
													";;文本文件(*.txt)"
													";;XML文件(*.xml)"));
		displayTextEdit->setText(fileName);
	}
	else if(btn == fontPushBtn)
	{// 字体对话框.
		bool ok;
		const QFont& font = QFontDialog::getFont(&ok,
									displayTextEdit->font(),
									this,
									tr("字体对话框"));
		if(ok)
		{// 如果<确定>,设置字体.
			displayTextEdit->setFont(font);
		}
	}
	else if(btn == inputPushBtn)
	{// 输入对话框.
		bool ok;
     	QString text = QInputDialog::getText(this, 
											tr("输入对话框"),
                                          	tr("输入文本："), 
											QLineEdit::Normal,
                                          	QDir::home().dirName(), 
&ok);
     if (ok && !text.isEmpty())
         displayTextEdit->setText(text);
	}
	else if(btn == pagePushBtn)
	{// 页设置对话框.
		QPrinter printer;
		QPageSetupDialog dlg(&printer, this);
		dlg.setWindowTitle(tr("页设置对话框"));
		if (dlg.exec() == QDialog::Accepted) 
		{
			// 进行下一步的处理。
 		}	
	} 
	else if(btn == progressPushBtn)
	{// 进度对话框.
		QProgressDialog progress(tr("正在复制文件..."), tr("取消"), 0, 10000, this);
		progress.setWindowModality(Qt::WindowModal);
		progress.setWindowTitle(tr("进度对话框"));
		progress.show();
		for (int i = 0; i < 10000; i++) 
{
			progress.setValue(i);
			qApp->processEvents();	
			if (progress.wasCanceled())
				break;
			//... 复制文件处理。
			qDebug() << i;
		}
		progress.setValue(10000);
	}

	else if(btn == printPushBtn)
	{// 打印对话框.
		QPrinter printer;
		QPrintDialog dlg(&printer, this);
		dlg.setWindowTitle(tr("打印对话框"));
		if (dlg.exec() == QDialog::Accepted) 
		{
			// 进行下一步的处理。
 		}
	}
}
