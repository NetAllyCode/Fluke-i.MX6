#!/bin/ash
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/arcotg_udc.ko
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/g_mass_storage.ko idVendor=0x0f7e idProduct=0x0007 iManufacturer=\"Fluke Networks\" iProduct=\"LIBUSB-TEST\" iSerial=\"00001\"
