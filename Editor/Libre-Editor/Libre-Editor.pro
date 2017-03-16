#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T20:38:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Libre-Editor
TEMPLATE = app

 CONFIG += c++11

SOURCES += source/main.cpp \
        source/mainwindow.cpp \
    source/shadereditor.cpp \
    source/scripteditor.cpp


HEADERS  += include/mainwindow.h \
    include/shadereditor.h \
    include/scripteditor.h


FORMS    += ui/mainwindow.ui \
    ui/shadereditor.ui \
    ui/scripteditor.ui
