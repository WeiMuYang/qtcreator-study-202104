#include <QtGui>
#include <QtScript>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QScriptEngine engine;

	// QTextBrowser
    QTextEdit textEdit;
    QScriptValue scriptWindow = engine.newQObject(&textEdit);
    engine.globalObject().setProperty("txtEdit", scriptWindow);

	QScriptValue text(&engine,  QObject::tr("<b><font color=#FF0000 size=5>��һ��QtScript����<font></b>"));
    scriptWindow.setProperty("html", text);
    engine.evaluate(QObject::tr("txtEdit.append('׷�ӵ�����')"));
/*    engine.evaluate(QObject::tr("txtEdit.insertPlainText('���������')"));
    engine.evaluate(QObject::tr("txtEdit.insertPlainText('�ڶ���')"));*/
    engine.evaluate("txtEdit.show()");
   
    if(engine.hasUncaughtException()) {
    	QScriptValue value = engine.uncaughtException();
    	QMessageBox::information(NULL, QObject::tr("Exception"), value.toString());
    }

    return app.exec();
}
