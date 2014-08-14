To prepare a new SD card for use with i.MX6:
=====================================================
cd to and Erase SD card. Replace with contents of rootfs.tar.bz2:
	cd /media/i.mx6
	sudo cp /home/USERNAME/projects/snackers/system/buildroot/buildroot-2014.05/output/images/rootfs.tar.bz2 .
	sudo tar -jxvf rootfs.tar.bz2
	sudo rm rootfs.tar.bz2
Create directory "boot" and copy Linux image:
	sudo mkdir boot
	sudo cp /home/USERNAME/projects/snackers/system/kernel/linux-imx6/arch/arm/boot/uImage boot
Copy and extract modules.tar.gz in the /lib/ folder
	sudo cp -R /home/USERNAME/projects/snackers/system/kernel/tmp/lib/modules lib
	sudo tar -xzvf modules.tar.gz
Sync and remove SD card:
	sync