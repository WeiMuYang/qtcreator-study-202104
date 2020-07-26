#include <QtGui>
#include <QtUiTools>
#include <QtScript>

#include "rtfedit.h"

class RTFUiLoader : public QUiLoader
{
public:
    RTFUiLoader(QObject *parent = 0)
        : QUiLoader(parent)
        { }
        
    virtual QWidget *createWidget(const QString &className, QWidget *parent = 0,
                                  const QString &name = QString())
    {
        if (className == QLatin1String("RTFEdit")) {
            QWidget *rtf = new RTFEdit(parent);
            rtf->setObjectName(name);
            return rtf;
        }
        return QUiLoader::createWidget(className, parent, name);
    }
};

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(rtfedit);
	
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QScriptEngine engine;

    QFile scriptFile(":/rtfedit.js");
    scriptFile.open(QIODevice::ReadOnly);
    engine.evaluate(QObject::tr(scriptFile.readAll()));
    scriptFile.close();

    RTFUiLoader loader;
    QFile uiFile(":/rtfedit.ui");
    uiFile.open(QIODevice::ReadOnly);
    QWidget *ui = loader.load(&uiFile);
    uiFile.close();

    QScriptValue func = engine.evaluate("RTF");
    QScriptValue scriptUi = engine.newQObject(ui);
    QScriptValue table = func.construct(QScriptValueList() << scriptUi);
    if(engine.hasUncaughtException()) {
    	QScriptValue value = engine.uncaughtException();
    	QString lineNumber = QString("\nLine Number:%1\n").arg(engine.uncaughtExceptionLineNumber());
    	QStringList btList = engine.uncaughtExceptionBacktrace();
    	QString trace;
    	for(short i=0; i<btList.size(); ++i)
    		trace += btList.at(i);
    	QMessageBox::information(NULL, QObject::tr("Exception"), value.toString() + lineNumber + trace );
    }

    ui->show();
    return app.exec();
}
