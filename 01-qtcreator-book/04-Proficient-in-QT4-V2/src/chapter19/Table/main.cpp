#include <QtGui>
#include <QtUiTools>
#include <QtScript>

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(table);
	
    QApplication app(argc, argv);
    QScriptEngine engine;

    QFile scriptFile(":/table.js");
    scriptFile.open(QIODevice::ReadOnly);
    engine.evaluate(scriptFile.readAll());
    scriptFile.close();

    QUiLoader loader;
    QFile uiFile(":/table.ui");
    uiFile.open(QIODevice::ReadOnly);
    QWidget *ui = loader.load(&uiFile);
    uiFile.close();

    QScriptValue func = engine.evaluate("Table");
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
