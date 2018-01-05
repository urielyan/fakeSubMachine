INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qserialportglobal.h \
    $$PWD/qserialport.h \
    $$PWD/qserialportinfo.h \
    $$PWD/qtudev_p.h \
    $$PWD/qringbuffer_p.h \
    $$PWD/qobject_p.h \
    $$PWD/qiodevice_p.h \
    $$PWD/qcore_unix_p.h

HEADERS += \
    $$PWD/qserialport_p.h \
    $$PWD/qserialportinfo_p.h

SOURCES += \
    $$PWD/qserialport.cpp \
    $$PWD/qserialportinfo.cpp \
    $$PWD/qserialportinfo_unix.cpp
SOURCES += \
    $$PWD/qserialport_unix.cpp

SUBDIRS += \
    $$PWD/serialport.pro

DISTFILES +=

