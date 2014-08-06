#!/bin/bash
gcc -o libusb_test libusb_test.c /usr/include/libusb-1.0/libusb.h -L /usr/lib/libusbmuxd.so.1 -lusb-1.0; sudo ./libusb_test -o
