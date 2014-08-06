
PATH := ${PWD}/toolchain/bin:${PATH}
NFSDIR := ${HOME}/nfs/imx6root
TFTPDIR := ${HOME}/tftp

BUILDROOT_VER := buildroot-2014.05
BUILDROOT_DIR := buildroot/${BUILDROOT_VER}

all: buildroot

.PHONY: buildroot kernel

buildroot:
	cd ${BUILDROOT_DIR} && make
buildroot-clean:
	cd ${BUILDROOT_DIR} && make clean
buildroot-defconfig:
	cd ${BUILDROOT_DIR} && make nitrogen6x_defconfig
buildroot-menuconfig:
	cd ${BUILDROOT_DIR} && make menuconfig
buildroot-install-nfs:
	sudo rm -rf ${NFSDIR}
	sudo mkdir -p ${NFSDIR}
	sudo tar jxvf ${BUILDROOT_DIR}/output/images/rootfs.tar.bz2 -C ${NFSDIR}

busybox-menuconfig:
	cd ${BUILDROOT_DIR} && make busybox-menuconfig

KERNEL_DIR := kernel/linux-imx6
COPROC := -j12
ARCH := "ARCH=arm"
CROSSC := "CROSS_COMPILE=arm-buildroot-linux-uclibcgnueabi-"
MODULES_DIR := ../tmp

kernel:
	cd ${KERNEL_DIR} && make ${COPROC} ${ARCH} ${CROSSC} uImage modules
kernel-clean:
	cd ${KERNEL_DIR} && make ${ARCH} ${CROSSC} clean
kernel-defconfig:
	cd ${KERNEL_DIR} && make ${ARCH} ${CROSSC} nitrogen6x_defconfig
kernel-menuconfig:
	cd ${KERNEL_DIR} && make ${ARCH} ${CROSSC} menuconfig
kernel-modules_install:
	cd ${KERNEL_DIR} && make ${ARCH} ${CROSSC} INSTALL_MOD_PATH=${MODULES_DIR} modules_install
kernel-install-tftp:
	cp -f ${KERNEL_DIR}/arch/arm/boot/uImage ${TFTPDIR}/uImage.imx6

