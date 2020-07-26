#include <QtGui>
#include "ConvertWidget.h"

ConvertWidget::ConvertWidget(QWidget *parent)
 : QWidget(parent)
{
	setupUi(this);
	txtSource->setText(QDir::currentPath());
	srcCodec = QTextCodec::codecForName("GB18030-0");
	destCodec = QTextCodec::codecForName("UTF-8");
}

ConvertWidget::~ConvertWidget()
{
}

void ConvertWidget::on_btnConvert_clicked()
{
	/*QString filter = txtFilter->text();
	QStringList filters = filter.split(",", QString::SkipEmptyParts);
	QDirIterator it(txtSource->text(), filters, QDir::AllEntries, QDirIterator::Subdirectories);*/
	
	QFile srcFile, dstFile;
	QTextStream in, out;
	QString fileName, dstFileName, tmpStr;
	QDirIterator it(txtSource->text(), QDirIterator::Subdirectories);
	 while (it.hasNext()) {
	     fileName = it.next();
	     //QDirIterator���Ƿ���/�ָ���
	     fileName.replace("/", QDir::separator());
	     if(fileName.endsWith(".h") || fileName.endsWith(".cpp"))
	     {
	         srcFile.setFileName(fileName);
	         if (!srcFile.open(QFile::ReadOnly | QFile::Text)) {
	             QMessageBox::warning(this, tr("����"),
	                                  tr("���ܴ��ļ�%1:\n%2")
	                                  .arg(fileName)
	                                  .arg(srcFile.errorString()));
	             return;
	         }

	         in.setDevice(&srcFile);
	         in.setAutoDetectUnicode(false);
	         in.setCodec(srcCodec);
	         tmpStr = in.readAll();

	         dstFileName = txtDest->text() + QDir::separator() + 
    		 	fileName.mid(fileName.lastIndexOf(QDir::separator())+1);
	         dstFileName.replace("/", QDir::separator());
	         dstFile.setFileName(dstFileName);
	         if (!dstFile.open(QFile::WriteOnly | QIODevice::Truncate | QFile::Text)) {
	             QMessageBox::warning(this, tr("����"),
	                                  tr("���ܴ��ļ�%1:\n%2")
	                                  .arg(dstFileName)
	                                  .arg(dstFile.errorString()));
	             return;
	         }
	         
	         out.setDevice(&dstFile);
	         out.setCodec(destCodec);
	         out << tmpStr;
	         srcFile.close();
	         dstFile.close();
	     }
	 }
	 QMessageBox::information(this, tr("��ʾ"), tr("ת�����!"));
}

void ConvertWidget::on_btnExit_clicked()
{
	close();
}

void ConvertWidget::on_btnSource_clicked()
{
	 QString dir = QFileDialog::getExistingDirectory(this, tr("ѡ��ԴĿ¼"),
	                                                 txtSource->text(),
	                                                 QFileDialog::ShowDirsOnly
	                                                 | QFileDialog::DontResolveSymlinks);
	 txtSource->setText(dir);
}

void ConvertWidget::on_btnDest_clicked()
{
	 QString dir = QFileDialog::getExistingDirectory(this, tr("ѡ��Ŀ��Ŀ¼"),
	                                                 txtDest->text(),
	                                                 QFileDialog::ShowDirsOnly
	                                                 | QFileDialog::DontResolveSymlinks);
	 txtDest->setText(dir);	
}

void ConvertWidget::on_radioGBToUTF_clicked()
{
	srcCodec = QTextCodec::codecForName("GB18030-0");
	destCodec = QTextCodec::codecForName("UTF-8");
}

void ConvertWidget::on_radioUTFToGB_clicked()
{
	srcCodec = QTextCodec::codecForName("UTF-8");
	destCodec = QTextCodec::codecForName("GB18030-0");	
}

