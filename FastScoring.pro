#-------------------------------------------------
#
# Project created by QtCreator 2013-03-14T22:09:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FastScoring
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    digitreader.cpp \
    formprinter.cpp \
    dbconnector.cpp \
    pointdigitextracter.cpp \
    digitextracter.cpp \
    processwidget.cpp

HEADERS  += mainwindow.h \
    digitreader.h \
    digitextracter.h \
    formprinter.h \
    datastruct.h \
    dbconnector.h \
    pointdigitextracter.h \
    processwidget.h

FORMS    += mainwindow.ui \
    processwidget.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
