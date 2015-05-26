#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T16:14:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GerenciadorDeDisco
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    disco.cpp \
    lista.cpp \
    file.cpp \
    setor.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    disco.h \
    lista.h \
    file.h \
    setor.h

FORMS    += mainwindow.ui \
    dialog.ui
