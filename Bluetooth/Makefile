
PATH := ${PWD}/../../system/toolchain/bin:${PATH}
BRDIR := ${PWD}/../../system/buildroot/buildroot-2014.05
NFSDIR := ${HOME}/nfs/root

CCPREFIX := arm-buildroot-linux-uclibcgnueabi

CPP := ${CCPREFIX}-gcc
INCLUDES := -I${BRDIR}/output/host/usr/arm-buildroot-linux-uclibcgnueabi/sysroot/usr/include/ \
            -I${BRDIR}/output/host/usr/arm-buildroot-linux-uclibcgnueabi/sysroot/usr/include/QtCore \
            -I${BRDIR}/output/host/usr/arm-buildroot-linux-uclibcgnueabi/sysroot/usr/include/QtGui
CPPFLAGS := -Wall -g ${INCLUDES}

LD := ${CCPREFIX}-gcc
LDFLAGS := -Lpath1 -Lpath2 -lm -lbluetooth -lpcap 

TARGET := pcapture_bt 
OBJECTS := pcapture_bt.o

all: ${TARGET}

clean:
	rm -f ${TARGET} ${OBJECTS}
install-nfs:
	sudo cp -f ${TARGET} ${NFSDIR}

${TARGET}: ${OBJECTS}
	${LD} -o $@ ${LDFLAGS} $?

pcapture_bt.o: pcapture_bt.c
	${CPP} -c ${CPPFLAGS} -o $@ $?

