#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <QtGui>
#include <QXmlDefaultHandler>

class UiHandler : public QXmlDefaultHandler
{
public:
    UiHandler(QTextEdit *textEdit, QString fileName);

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);
    QString errorString() const;

private:
	QString macroName;
	QString propName;
	QString currentText;
	QString topWidget;
	QString currentWidget;
	QString constructorText;
    QString errorStr;
	QString classAttr;
	QString	nameAttr;
	QString xTag;	
	QString yTag;	
	QString widthTag;	

	short	level;
	QTextEdit *txtEdit;
	QTextCursor cursor;
};

#endif
