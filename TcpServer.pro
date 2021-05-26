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
    serverthread.cpp \
    avilib.cpp \
    camerathread.cpp \
    color.cpp \
    utils.cpp \
    v4l2uvc.cpp

HEADERS += \
    mysocket.h \
    mytcpserver.h \
    serverthread.h \
    avilib.h \
    camerathread.h \
    color.h \
    huffman.h \
    utils.h \
    uvc_compat.h \
    uvcvideo.h \
    v4l2uvc.h
