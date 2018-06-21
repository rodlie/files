QT+= core gui dbus
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(../qtfm.pri)

TARGET = $${QTFM_TARGET}
TARGET_NAME = $${QTFM_TARGET_NAME}
VERSION = $${QTFM_MAJOR}.$${QTFM_MINOR}.$${QTFM_PATCH}
TEMPLATE = app

DEPENDPATH += . src
INCLUDEPATH += . src ../libfm

HEADERS += src/mainwindow.h \
    src/mymodel.h \
    src/bookmarkmodel.h \
    src/progressdlg.h \
    src/icondlg.h \
    src/propertiesdlg.h \
    src/fileutils.h \
    src/tabbar.h \
    src/mymodelitem.h \
    src/settingsdialog.h \
    src/customactionsmanager.h \
    src/processdialog.h \
    src/desktopfile.h \
    src/applicationdialog.h \
    src/properties.h \
    src/mimeutils.h \
    src/aboutdialog.h \
    ../libfm/common.h
SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/mymodel.cpp \
    src/bookmarks.cpp \
    src/progressdlg.cpp \
    src/fileutils.cpp \
    src/icondlg.cpp \
    src/propertiesdlg.cpp \
    src/tabbar.cpp \
    src/mymodelitem.cpp \
    src/settingsdialog.cpp \
    src/customactionsmanager.cpp \
    src/processdialog.cpp \
    src/desktopfile.cpp \
    src/applicationdialog.cpp \
    src/properties.cpp \
    src/mimeutils.cpp \
    src/aboutdialog.cpp \
    src/actiondefs.cpp \
    src/actiontriggers.cpp

OTHER_FILES += $${TARGET}.desktop
RESOURCES += $${TARGET}.qrc

DEFINES += APP=\"\\\"$${TARGET}\\\"\"
DEFINES += APP_NAME=\"\\\"$${TARGET_NAME}\\\"\"
DEFINES += APP_VERSION=\"\\\"$${VERSION}\\\"\"

isEmpty(PREFIX) {
    PREFIX = /usr/local
}
isEmpty(DOCDIR) {
    DOCDIR = $$PREFIX/share/doc
}

target.path = $${PREFIX}/bin
desktop.files += $${TARGET}.desktop
desktop.path += $${PREFIX}/share/applications
docs.path += $${DOCDIR}/$${TARGET}-$${VERSION}
docs.files += ../LICENSE ../README.md
INSTALLS += target desktop docs

exists(../libdisks/libdisks.pro) {
    message("Using embedded libdisks")
    INCLUDEPATH += ../libdisks
    LIBS += -L../libdisks -lDisks
} else {
    message("Using external libdisks")
    CONFIG += link_pkgconfig
    PKGCONFIG += Disks
}

exists(../libpower/libpower.pro) {
    message("Using embedded libpower")
    INCLUDEPATH += ../libpower
    LIBS += -L../libpower -lPower
} else {
    message("Using external libpower")
    CONFIG += link_pkgconfig
    PKGCONFIG += Power
}

lessThan(QT_MAJOR_VERSION, 5): LIBS += -lmagic

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
