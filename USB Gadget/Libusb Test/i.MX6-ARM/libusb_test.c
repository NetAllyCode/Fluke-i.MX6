#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <libusb-1.0/libusb.h>

void listUSBDevices();
void openUSBDevice();

int main(int argc, char **argv)
{
	if(!strcmp(argv[1], "-l"))
	{
		listUSBDevices();
	}
	else if(!strcmp(argv[1], "-o"))
	{
		openUSBDevice();
	}

	return 0;
}

void listUSBDevices()
{
	libusb_context *context;
	libusb_device **list;
	int ret = 0;
	ssize_t count = 0;

	ret = libusb_init(&context);
	count = libusb_get_device_list(context, &list);

	size_t i;

	fprintf(stderr, "%s\n", "VENDOR | DEVICE\n---------------");
	for(i = 0; i < count; i++)
	{
		libusb_device *dev = list[i];
		struct libusb_device_descriptor desc = {0};
		ret = libusb_get_device_descriptor(dev, &desc);
		fprintf(stderr, " %04x     %04x\n", desc.idVendor, desc.idProduct);
	}
}

void openUSBDevice()
{
	libusb_context *context;
	libusb_device **list;
	int ret = 0;
	ssize_t count = 0;

	ret = libusb_init(&context);
	count = libusb_get_device_list(context, &list);

	size_t i;

	fprintf(stderr, "%s\n", "# VENDOR | DEVICE\n---------------");
	for(i = 0; i < count; i++)
	{
		libusb_device *dev = list[i];
		struct libusb_device_descriptor desc = {0};
		ret = libusb_get_device_descriptor(dev, &desc);
		fprintf(stderr, "%d %04x     %04x\n", i, desc.idVendor, desc.idProduct);
	}
	
	int num = -1;
	fprintf(stderr, "%s ", "Device number to open:");
	scanf("%d", &num);

	fprintf(stderr, "Opening device #%d\n", num);
	libusb_device *dev = list[num];
	fprintf(stderr, "%s\n", "Got device from list...");
	libusb_device_handle *handle;
	fprintf(stderr, "%s\n", "Init Handle");
	ret = libusb_open(dev, &handle);
	fprintf(stderr, "%s\n", "Opened Device");
	libusb_free_device_list(list, 0);
	fprintf(stderr, "%s\n", "Freed Device List");

	/*IO HERE*/
	if(libusb_kernel_driver_active(handle, 0) == 1)
	{
		fprintf(stderr, "%s\n", "Kernel driver active...detaching it.");	
		if(libusb_detach_kernel_driver(handle, 0) == 0)
		{
			fprintf(stderr, "%s\n", "OK--kernel driver detached.");	
		}
		else
		{
			fprintf(stderr, "%s\n", "Error detaching kernel driver!");
		}
	}
	
	fprintf(stderr, "%s\n", "Claiming interface");
	ret = libusb_claim_interface(handle, 0);
	
	fprintf(stderr, "%s\n", "--WRITING DATA OUT--");
	char data[64];
	strncpy(data, "Hello World!", strlen("Hello World!"));
	int actual = 0;
	ret = libusb_bulk_transfer(handle, (2 | LIBUSB_ENDPOINT_OUT), data, strlen(data), &actual, 0);
	if(!ret)
	{
		fprintf(stderr, "Sucessfully(?) wrote %d bytes!\n", actual);
	}
	else
	{
		fprintf(stderr, "Write failed with ret=%d\n", ret);	
	}

	
	fprintf(stderr, "%s\n", "Releasing interface");
	ret = libusb_release_interface(handle, 0);

	libusb_close(handle);
	fprintf(stderr, "%s\n", "Closed Device");
	libusb_exit(context);
	fprintf(stderr, "%s\n", "Exit libusb");
}


