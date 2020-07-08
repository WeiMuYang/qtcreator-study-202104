#ifndef _MDITEXTEDIT_H_
#define _MDITEXTEDIT_H_

#include <QTextEdit>
class CMDITextEdit : public QTextEdit
{
	Q_OBJECT
public:
	CMDITextEdit(bool , const QString &);
	virtual ~CMDITextEdit();
	bool loadFile(const QString &fileName);
	bool save();
	bool saveAs();
	bool saveFile(const QString &fileName);
	QString fileName();

	static int count;
protected:
	void closeEvent(QCloseEvent *event);
private:
	bool maybeSave();
	void setCurrentFile(const QString &fileName);

	QString curFile;
	bool isUntitled;
	enum{MaxRecentFiles = 9};
signals:
	void updateRecentFiels();
	void counted(int);
private slots:
	void doModified();
};
#endif
