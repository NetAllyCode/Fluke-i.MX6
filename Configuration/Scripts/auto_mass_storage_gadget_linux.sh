#!/bin/ash
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/arcotg_udc.ko
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/g_mass_storage.ko file=/root/bb.bin stall=0 removable=1
