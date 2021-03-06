README
------
Put here the stuff to work with the RT7550

FIRST STEPS - Connect to the RT7750 with serial cable
=====================================================

* Install minicom
* Run sudo minicom -s
* Set in Serial Port Setup
    ** Serial Device: /dev/ttyUSB0 (or /dev/ttyUSB1)
    ** Bps: 115200 8N1
    ** Hardware Flow Control: No


Documentation URLs
======================
In here put the cites with documentation for the little arms:

* http://tech.groups.yahoo.com/group/ts-7000/

Sites to discover what chipset is in what wireless card

* http://wireless.kernel.org/en/users/Drivers/
* http://linux-wless.passys.nl/

Establishing AD-HOC Communication
=================================

PC1 - LGs laptops from INESC
PC2 - TS-7550s

Run in PC1
##########
* ifconfig eth1 down
* ifconfig eth1 up
* iwconfig eth1 essid teste mode Ad-Hoc channel 1 ap 02:0c:f1:b5:8f:01 key off
* ifconfig eth1 192.168.0.1

Run in PC2
#########
* Edit the file /etc/modprobe.d/blacklist and add rt73usb
* Copy the file "rt73_ts7500.ko" to "/lib/modules/2.6.24.4/kernel/drivers/net/wireless/rt2x00". You may find the rt_ts7500.ko file in this zip file: "ftp://ftp.embeddedarm.com/ts-arm-sbc/ts-7500-linux/binaries/wifi-g-usb-2_rt2501usb-binaries.tar.gz"
* Run depmod -a
* Restart (don't really now if it is necessary)
* ifconfig rausbwifi up
* iwconfig rausbwifi essid teste mode Ad-Hoc channel 1 ap 02:0C:F1:B5:CC:5D key off
* ifconfig rausbwifi 192.168.0.25

Autostart interfaces in the TS7550
##################################
I added the following lines to /etc/network/interfaces:

auto rausbwifi
iface rausbwifi inet static
    address 192.168.0.25
    netmask 255.255.255.0
    pre-up /root/adhoc.sh

Note that the /root/adhoc.sh is a script with the previous instructions (don't forget to markit executable)

Placa Wireless IOGEAR (Can't make it work in adhoc)
====================================================

*Modulos:*
zd1211 -> Old module developed by the company (available in sourceforge)
zd1211rw -> New module developed by the community (available since 2.6.18-rc1)

*Referencias:*
Site of the module:
http://wiki.debian.org/zd1211rw

Site to compile the module + arguments of the iwconfig:
https://docs.google.com/viewer?url=http://www.linuxowl.com/ffs/DocsSoftware/SWMULZ-5400-Linux-UserGuide.pdf

Automatically boot into Debian linux
====================================
In linux busy-box in the root directory issue:
ln -sf linuxrc-sdroot linuxrc; save

Translation table
=================
card |        ip       | Register
-------------------------------
  1  | 192.168.0.1     | MV-25
  2  | 192.168.0.2     | MV-26
  3  | 192.168.0.3     | MV-27

How to compile kernel in the TS-7500 node
=========================================

* Download the kernel from: ftp://ftp.embeddedarm.com/ts-arm-sbc/ts-7500-linux/sources/linux-2.6.24-ts-src-aug102009.tar.gz
* Put the source in some other disk as there is no space in the normal card
* Change makefile (Put the last option)
    KBUILD_CFLAGS   := -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs \
                       -fno-strict-aliasing -fno-common \
                       -Werror-implicit-function-declaration \
                       -fno-tree-scev-cprop

* Use the .config file in this directory to compile the kernel
