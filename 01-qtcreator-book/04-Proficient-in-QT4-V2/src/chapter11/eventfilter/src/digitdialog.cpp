
#include <QtGui>

#include <math.h>

#include "button.h"
#include "digitdialog.h"

Digital::Digital(QWidget *parent)
    : QDialog(parent)
{
    display = new QLineEdit("");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    display->installEventFilter(this);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
    QColor digitColor(150, 205, 205);

    for (int i = 0; i < NumDigitButtons; ++i) {
	digitButtons[i] = createButton(QString::number(i), digitColor,
                                       SLOT(digitClicked()));
    }
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 4);
    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 5, 0,1,4);
    setLayout(mainLayout);

    setWindowTitle(tr("Êý×Ö"));
}

bool Digital::eventFilter(QObject *target, QEvent *event)
{
    if (target == display) {
        if (event->type() == QEvent::MouseButtonPress
                || event->type() == QEvent::MouseButtonDblClick
                || event->type() == QEvent::MouseButtonRelease
                || event->type() == QEvent::ContextMenu) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->buttons() & Qt::LeftButton) {
                QPalette newPalette = palette();
                newPalette.setColor(QPalette::Base,
                                    display->palette().color(QPalette::Text));
                newPalette.setColor(QPalette::Text,
                                    display->palette().color(QPalette::Base));
                display->setPalette(newPalette);
            } else {
                display->setPalette(palette());
            }
            return true;
        }
    }
    return QDialog::eventFilter(target, event);
}

void Digital::digitClicked()
{
    Button *clickedQButton = qobject_cast<Button *>(sender());
    int digitValue = clickedQButton->text().toInt();
    display->setText(display->text() + QString::number(digitValue));
}

Button *Digital::createButton(const QString &text, const QColor &color,
                                 const char *member)
{
    Button *button = new Button(text, color);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}
