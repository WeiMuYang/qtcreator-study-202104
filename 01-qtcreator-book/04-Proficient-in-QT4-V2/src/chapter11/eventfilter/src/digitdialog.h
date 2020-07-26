
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

class QLineEdit;
class Button;

class Digital : public QDialog
{
    Q_OBJECT

public:
    Digital(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *target, QEvent *event);

private slots:
    void digitClicked();

private:
    Button *createButton(const QString &text, const QColor &color,
                         const char *member);
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif
