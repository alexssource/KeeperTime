# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = KeeperTime
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui
SOURCES += source/main.cpp source/SqlConnector.cpp source/Exception.cpp source/BaseRecord.cpp
HEADERS += header/BaseRecord.h header/ERROR_CODES.h header/SqlConnector.h header/Exception.h
FORMS += resource/MyTasks.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-4.4
DEFINES += 
INCLUDEPATH += /usr/local/include /usr/lib /usr/include /usr/local/lib /usr/lib32 /usr/share 
LIBS += -lmysqlclient  -Wl,-rpath /usr/local/lib -Wl,-rpath /usr/include -Wl,-rpath /usr/lib 
