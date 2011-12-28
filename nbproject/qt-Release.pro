# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = KeeperTime
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += source/main.cpp source/WorkTime.cpp source/Status.cpp source/Team.cpp source/Menu.cpp source/SqlConnector.cpp source/Exception.cpp source/Wages.cpp source/User.cpp source/DateTime.cpp source/BaseRecord.cpp source/Report.cpp source/NumberToStringConverter.cpp source/Group.cpp source/Task.cpp source/Project.cpp
HEADERS += header/BaseRecord.h header/ERROR_CODES.h header/Team.h header/WorkTime.h header/SqlConnector.h header/Menu.h header/DateTime.h header/Task.h header/Exception.h header/User.h header/Project.h header/Status.h header/Group.h header/NumberToStringConverter.h header/Wages.h header/Report.h
FORMS += resource/MyTasks.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
