#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T20:02:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZCompiler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scanner.cpp \
    parser.cpp \
    generator.cpp \
    symboltable.cpp \
    token.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    scanner.h \
    parser.h \
    generator.h \
    symboltable.h \
    token.h \
    utils.h

FORMS    += mainwindow.ui
