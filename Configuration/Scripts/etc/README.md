To enable touchscreen use in QT, replace /etc/profile with the file in this directory, replacing "/dev/input/event1" with the event corresponding to your touch screen device.

To enable eth0 or set up USB gadget device on boot, add the location of your startup script to /etc/inittab under ::sysinit.