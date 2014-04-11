#-------------------------------------------------
#
# Project created by QtCreator 2013-02-26T15:23:26
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    configuration.cpp \
    parameters.cpp \
    file.cpp

HEADERS  += mainwindow.h \
    configuration.h \
    parameters.h \
    file.h

FORMS    += mainwindow.ui
