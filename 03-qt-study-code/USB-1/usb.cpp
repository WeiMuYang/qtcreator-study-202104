#include "usb.h"
#include "ui_usb.h"
#include <lusb0_usb.h>
#include "QDebug"

USB::USB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::USB)
{

    usb_init(); /* initialize the library */
    //usb_set_debug(255);
    usb_find_busses(); /* find all busses */
    usb_find_devices(); /* find all connected devices */

    my_usb_get_device_list();

    ui->setupUi(this);

}

void USB::my_usb_get_device_list(void)
{
    struct usb_bus *bus;
    struct usb_device *dev;

    for (bus = usb_get_busses(); bus; bus = bus->next) {
        for (dev = bus->devices; dev; dev = dev->next) {
            qDebug("VID:VID = %x:%x\n", dev->descriptor.idVendor, dev->descriptor.idProduct);

        }
    }

}


usb_dev_handle *USB::open_dev(void)
{
    struct usb_bus *bus;

    for(bus = usb_get_busses(); bus; bus = bus->next) {
        for(dev = bus->devices; dev; dev = dev->next) {
            if((dev->descriptor.idVendor == MY_VID) && (dev->descriptor.idProduct == MY_PID)) {
                    return usb_open(dev);
            }
        }
    }
    return 0;
}

void USB::printf_device_descriptor(usb_device_descriptor *desc)
{
        qDebug("bLength:             %u",     desc->bLength);
        qDebug("bDescriptorType:     %02Xh",  desc->bDescriptorType);
        qDebug("bcdUSB:              %04Xh",  desc->bcdUSB);
        qDebug("bDeviceClass:        %02Xh",  desc->bDeviceClass);
        qDebug("bDeviceSubClass:     %02Xh",  desc->bDeviceSubClass);
        qDebug("bDeviceProtocol:     %02Xh",  desc->bDeviceProtocol);
        qDebug("bMaxPacketSize0:     %02Xh",  desc->bMaxPacketSize0);
        qDebug("idVendor:            %04Xh",  desc->idVendor);
        qDebug("idProduct:           %04Xh",  desc->idProduct);
        qDebug("bcdDevice:           %04Xh",  desc->bcdDevice);
        qDebug("iManufacturer:       %u",     desc->iManufacturer);
        qDebug("iProduct:            %u",     desc->iProduct);
        qDebug("iSerialNumber:       %u",     desc->iSerialNumber);
        qDebug("bNumConfigurations:  %u",     desc->bNumConfigurations);
}


USB::~USB()
{
    delete ui;
}

