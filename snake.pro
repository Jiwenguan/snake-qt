#-------------------------------------------------
#
# Project created by QtCreator 2018-06-21T21:00:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        SnakeDialog.cpp

HEADERS  += SnakeDialog.h

FORMS    += SnakeDialog.ui

RESOURCES += \
    pics.qrc
