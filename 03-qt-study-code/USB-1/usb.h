#ifndef USB_H
#define USB_H

#include <QMainWindow>
#include <lusb0_usb.h>

#define MY_VID 0x10c4
#define MY_PID 0xea60

QT_BEGIN_NAMESPACE
namespace Ui { class USB; }
QT_END_NAMESPACE

class USB : public QMainWindow
{
    Q_OBJECT

public:
    USB(QWidget *parent = nullptr);
    ~USB();
    usb_dev_handle * open_dev(void);
    void printf_device_descriptor(usb_device_descriptor *desc);
    void my_usb_get_device_list(void);
private:
    Ui::USB *ui;
    struct usb_device *dev;
    usb_dev_handle *udev;
};
#endif // USB_H
