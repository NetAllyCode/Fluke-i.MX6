#!/bin/ash
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/arcotg_udc.ko
insmod /lib/modules/3.0.35-g1c8e659-dirty/kernel/drivers/usb/gadget/g_ether.ko dev_addr=12:3c:9c:0e:f1:fa host_addr=00:19:b8:01:3f:9a
ifconfig usb0 192.168.1.9 up
#/root/tcp_server 8999
