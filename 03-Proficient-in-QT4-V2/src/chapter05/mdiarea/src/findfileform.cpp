//findfileform.cpp
#include <QtGui>
#include "findfileform.h"
CFindFileForm::CFindFileForm(QWidget* parent)
 :	QWidget(parent),
 	m_bStoped(false),
	m_nCount(0)
{
	setupUi(this);	
	statusLabel->setText(tr("就绪"));	
	resultLabel->setText(tr("找到0个文件"));
	nameComboBox->setEditText("*");
	dirComboBox->setEditText(QDir::currentPath());
	dirComboBox->addItem(QDir::currentPath());
	sensitiveCheckBox->setEnabled(false);
	
	connect(findPushBtn, SIGNAL(clicked()), this, SLOT(find()));
	connect(stopPushBtn, SIGNAL(clicked()), this, SLOT(stop()));
	connect(closePushBtn, SIGNAL(clicked()), this, SLOT(close()));
	connect(browsePushBtn, SIGNAL(clicked()), this, SLOT(browse()));
	connect(txtLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(doTxtChange(const QString&)));
}

void CFindFileForm::browse()
{
     QString dir = QFileDialog::getExistingDirectory(this,
                                tr("选择查找路径"), 
								QDir::currentPath(),
								QFileDialog::ShowDirsOnly);
     if (!dir.isEmpty()) {
         dirComboBox->addItem(dir);
         dirComboBox->setCurrentIndex(dirComboBox->currentIndex() + 1);
     }
}

void CFindFileForm::find()
{
	 frame->setEnabled(false);
     findPushBtn->setEnabled(false);
	 stopPushBtn->setEnabled(true);
	 statusLabel->setText(tr("正在搜索..."));
	 resultTableWidget->setRowCount(0);

     QString fileName = nameComboBox->currentText();
     QString txt = txtLineEdit->text();
     QString path = dirComboBox->currentText();
	 m_bSubfolder = subfolderCheckBox->isChecked();
	 m_bSensitive = sensitiveCheckBox->isChecked();

     m_nCount = 0;
	 m_bStoped = false;
	 QDir dir = QDir(path);
     if (fileName.isEmpty())
         fileName = "*";	 
	tranvFolder(dir,fileName, txt);	 

	 if(m_bStoped)
	 	statusLabel->setText(tr("已中止"));
	else
		statusLabel->setText(tr("就绪"));
	findPushBtn->setEnabled(true);
	 stopPushBtn->setEnabled(false);
	 frame->setEnabled(true);
}


void CFindFileForm::tranvFolder(const QDir& dir, const QString& fileName, const QString txt)
{
	if(m_bSubfolder)
	{
		QStringList folders;
		folders = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
		for (int i = 0; i < folders.size(); ++i) 
		{			
			qApp->processEvents();
			if (m_bStoped)
				break;
				
			QString strDir = QString("%1/%2").arg(dir.absolutePath()).arg(folders[i]);
			tranvFolder(strDir, fileName, txt);
		}
	}
	QStringList files = findFiles(dir, fileName, txt);
	showFiles(dir, files);
	m_nCount += files.size();	
	resultLabel->setText(tr("找到%1个文件").arg(m_nCount));
						
}

QStringList CFindFileForm::findFiles(const QDir &dir, const QString &fileName,
                               const QString &txt)
{	
	 QStringList files = dir.entryList(QStringList(fileName),
                                 QDir::Files | QDir::NoSymLinks);
	if (txt.isEmpty())
         return files;
	QStringList foundFiles;
	Qt::CaseSensitivity sensitive = Qt::CaseInsensitive;
	if(m_bSensitive)
		sensitive = Qt::CaseSensitive;
 for (int i = 0; i < files.size(); ++i) 
	{
        qApp->processEvents();
        if (m_bStoped)
             break;

        QFile file(dir.absoluteFilePath(files[i]));
        if (file.open(QIODevice::ReadOnly)) 
		{
            QString line;
            QTextStream in(&file);
            while (!in.atEnd()) 
			{
				if (m_bStoped)
             		break;
                line = in.readLine();
                if (line.contains(txt, sensitive)) 
				{
                    foundFiles << files[i];
                    break;
                }
            }
        }
    }
    return foundFiles;
}


void CFindFileForm::showFiles(const QDir &dir, const QStringList &files)
{
	for (int i = 0; i < files.size(); ++i) {
		QString strFilePath = dir.absoluteFilePath(files[i]);
		QFile file(strFilePath);
		QFileInfo fileInfo(file);
		qint64 size = fileInfo.size();
		QDateTime dateTime = fileInfo.created();
		QString strDateTime = dateTime.toString(tr("yyyy MM月dd日hh:mm"));
		QString strPermission;
		if(fileInfo.isWritable())
			strPermission = ("w");
		if(fileInfo.isReadable())
			strPermission.append(" r");
		if(fileInfo.isExecutable())
			strPermission.append(" x");
	
		QTableWidgetItem *fileNameItem = new QTableWidgetItem(strFilePath);
		fileNameItem->setFlags(Qt::ItemIsEnabled);
		QTableWidgetItem *sizeItem = new QTableWidgetItem(tr("%1 KB")
											.arg(int((size + 1023) / 1024)));
		sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		sizeItem->setFlags(Qt::ItemIsEnabled);
		QTableWidgetItem* createdItem = new QTableWidgetItem(strDateTime);
		QTableWidgetItem* permissionItem = new QTableWidgetItem(strPermission);
	
		int row = resultTableWidget->rowCount();
		resultTableWidget->insertRow(row);
		resultTableWidget->setItem(row, 0, fileNameItem);
		resultTableWidget->setItem(row, 1, sizeItem);
		resultTableWidget->setItem(row, 2, createdItem);
		resultTableWidget->setItem(row, 3, permissionItem);
	}
}
void CFindFileForm::stop()
{
	m_bStoped = true;
}
void CFindFileForm::doTxtChange(const QString& txt)
{
	if(txt.isEmpty())
		sensitiveCheckBox->setEnabled(false);
	else
		sensitiveCheckBox->setEnabled(true);
}



