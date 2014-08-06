
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
LDFLAGS := -Lpath1 -Lpath2 -lm 

TARGET := tty_write 
OBJECTS := tty_write.o

all: ${TARGET}

clean:
	rm -f ${TARGET} ${OBJECTS}
install-nfs:
	sudo cp -f ${TARGET} ${NFSDIR}

${TARGET}: ${OBJECTS}
	${LD} -o $@ ${LDFLAGS} $?

tty_write.o: tty_write.c
	${CPP} -c ${CPPFLAGS} -o $@ $?

