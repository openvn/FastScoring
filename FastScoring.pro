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
    digitreader.cpp

HEADERS  += mainwindow.h \
    digitreader.h

FORMS    += mainwindow.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
