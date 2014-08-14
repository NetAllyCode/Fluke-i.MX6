#!/bin/ash
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/arcotg_udc.ko
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/g_ether.ko idVendor=0x0f7e idProduct=0x0006 iManufacturer=\"Fluke Networks\" iProduct=\"USBLAN\"
ifconfig usb0 169.254.222.5 up
