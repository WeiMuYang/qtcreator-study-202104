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

	QScriptValue text(&engine,  QObject::tr("<b><font color=#FF0000 size=5>第一个QtScript程序<font></b>"));
    scriptWindow.setProperty("html", text);
    engine.evaluate(QObject::tr("txtEdit.append('追加的文字')"));
/*    engine.evaluate(QObject::tr("txtEdit.insertPlainText('插入的文字')"));
    engine.evaluate(QObject::tr("txtEdit.insertPlainText('第二行')"));*/
    engine.evaluate("txtEdit.show()");
   
    if(engine.hasUncaughtException()) {
    	QScriptValue value = engine.uncaughtException();
    	QMessageBox::information(NULL, QObject::tr("Exception"), value.toString());
    }

    return app.exec();
}
