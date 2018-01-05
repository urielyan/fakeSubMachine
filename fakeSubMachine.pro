#-------------------------------------------------
#
# Project created by QtCreator 2017-12-25T04:54:07
#
#-------------------------------------------------

#equals(5, $$QT_MAJOR_VERSION) {
#    QT += serialport
#}
#equals(4, $$QT_MAJOR_VERSION) {
#    include (serialport/serialport.pri)
#}
QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fakeSubMachine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    masterthread.cpp \
    slavethread.cpp

HEADERS  += mainwindow.h \
    masterthread.h \
    slavethread.h

FORMS    += mainwindow.ui
