#-------------------------------------------------
#
# Project created by QtCreator 2013-09-18T12:54:50
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = TcpServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mysocket.cpp \
    mytcpserver.cpp \
    serverthread.cpp

HEADERS += \
    mysocket.h \
    mytcpserver.h \
    serverthread.h
