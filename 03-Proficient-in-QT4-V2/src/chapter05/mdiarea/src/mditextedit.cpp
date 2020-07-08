#include <QtGui>
#include "mditextedit.h"

int CMDITextEdit::count	= 0;
CMDITextEdit::CMDITextEdit(bool untitled, const QString& fileName)
 :	isUntitled(untitled),
 	curFile(fileName)
{
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle(fileName + "[*]");
	connect(document(), SIGNAL(contentsChanged()), 
		this, SLOT(doModified()));
}

CMDITextEdit::~CMDITextEdit()
{
	emit counted(--count);
}

QString CMDITextEdit::fileName()
{
	return curFile;	
}

bool CMDITextEdit::save()
{
	if (isUntitled) 
	{
         saveAs();
     } else 
	 {
         saveFile(curFile);
		 document()->setModified(false);
		 setWindowModified(false);
     }
}
bool CMDITextEdit::saveAs()
{
	QString fileName = 
		QFileDialog::getSaveFileName(this, tr("���Ϊ"), curFile);
     if (!fileName.isEmpty())
	 {
		saveFile(fileName);	
		setCurrentFile(fileName); 
	 }	 		
}
bool CMDITextEdit::loadFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("��ȡ�ļ�"),
							tr("�޷���ȡ�ļ� %1:\n%2.")
							.arg(fileName)
							.arg(file.errorString()));
		return false;
	}

	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	setText(in.readAll());
	QApplication::restoreOverrideCursor();
	setCurrentFile(fileName);

	return true;
}

bool CMDITextEdit::saveFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, 
							tr("�����ļ�"),
							tr("�޷������ļ� %1:\n%2.")
							.arg(fileName)
							.arg(file.errorString()));
		return false;
	}

	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out << toPlainText();
	QApplication::restoreOverrideCursor();
			
	return true;
}

void CMDITextEdit::closeEvent(QCloseEvent *event)
{
	if (maybeSave()) 
		event->accept();
	else 
		event->ignore();
}
void CMDITextEdit::doModified()
{
	setWindowModified(document()->isModified());
}

bool CMDITextEdit::maybeSave()
{
	if(document()->isModified())
	{
		QMessageBox box;
		box.setWindowTitle(tr("����"));		
		box.setIcon(QMessageBox::Warning);
		box.setText(tr("�ĵ�û�б��棬�Ƿ񱣴棿"));
		box.setStandardButtons(QMessageBox::Yes 
								| QMessageBox::No
								| QMessageBox::Cancel);
		switch(box.exec())
		{
		case QMessageBox::Yes :
			save();
			return true;
		case QMessageBox::No :
			return true;
		case QMessageBox::Cancel :
			return false;
		}
	}
	else
		return true;
}
void CMDITextEdit::setCurrentFile(const QString &fileName)
{
	curFile = QFileInfo(fileName).canonicalFilePath();
	isUntitled = false;
	setWindowTitle(curFile + "[*]");
	document()->setModified(false);
	setWindowModified(false);
	
	QSettings settings("709", "MDI example");
	QStringList files = settings.value("recentFiles").toStringList();
	files.removeAll(fileName);
	files.prepend(fileName);
	while (files.size() > MaxRecentFiles)
		files.removeLast();
	settings.setValue("recentFiles", files);

	emit updateRecentFiels();
}
