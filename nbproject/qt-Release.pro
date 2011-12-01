# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = KeeperTime
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += source/main.cpp source/CommentNews.cpp source/CommentReport.cpp source/Comment.cpp source/CommentStatus.cpp source/CommentTask.cpp source/Group.cpp resource/BaseRecord.cpp
HEADERS += header/CommentStatus.h header/BaseRecord.h header/Comment.h header/User.h header/CommentTask.h header/Group.h header/CommentReport.h header/CommentNews.h
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
