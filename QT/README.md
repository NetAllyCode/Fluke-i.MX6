Cross compiling for the i.MX6 is automatically set up in m.sh, but can also be achieved by the following:

../../system/buildroot/buildroot-2014.05/output/host/usr/bin/qmake -project   ### Generates .pro file with dependencies

../../system/buildroot/buildroot-2014.05/output/host/usr/bin/qmake   ### Generates Makefile

make   ### Cross compile and build executable


![QT UI](https://raw.githubusercontent.com/scdickson/Fluke-i.MX6/master/QT/qt_ui.jpg)
