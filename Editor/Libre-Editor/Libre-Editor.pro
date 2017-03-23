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
    source/scripteditor.cpp \
    source/userproject.cpp \
    source/projectcreategui.cpp \
    source/tilemapeditor.cpp


HEADERS  += include/mainwindow.h \
    include/shadereditor.h \
    include/scripteditor.h \
    include/userproject.h \
    include/projectcreategui.h \
    include/tilemapeditor.hpp


FORMS    += ui/mainwindow.ui \
    ui/shadereditor.ui \
    ui/scripteditor.ui \
    ui/projectcreategui.ui \
    ui/tilemapeditor.ui

unix|win32: LIBS += -llibre-engine
