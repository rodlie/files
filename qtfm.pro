TEMPLATE = subdirs
CONFIG += ordered
exists(libdisks/libdisks.pro): SUBDIRS += libdisks
SUBDIRS += fm
OTHER_FILES += README.md LICENSE
