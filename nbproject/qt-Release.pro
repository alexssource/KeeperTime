# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = KeeperTime
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += source/main.cpp source/SqlConnector.cpp source/Exception.cpp source/DateTime.cpp source/BaseRecord.cpp source/NumberToStringConverter.cpp source/Group.cpp
HEADERS += header/BaseRecord.h header/ERROR_CODES.h header/SqlConnector.h header/DateTime.h header/Exception.h header/Group.h header/NumberToStringConverter.h
FORMS += resource/MyTasks.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-4.4
DEFINES += 
INCLUDEPATH += 
LIBS += 
