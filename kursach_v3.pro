#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T22:04:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kursach_v3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mygraphicsscene.cpp \
    mainwindowinit.cpp \
    mysceneproperties.cpp \
    myscenetool.cpp

HEADERS  += mainwindow.h \
    mygraphicsscene.h \
    mysceneproperties.h \
    myscenetool.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
