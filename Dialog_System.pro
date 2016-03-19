QT += core
QT -= gui

TARGET = Dialog_System
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    DSObjects/semnetobj.h \
    DSObjects/simplesno.h \
    Model/datasender.h \
    Model/dialogstorage.h \
    Model/dialogworker.h \
    Model/hashdst.h \
    Model/model.h \
    Presenter/presenter.h \
    View/view.h \
    DSObjects/dialogendsno.h

SOURCES += \
    DSObjects/simplesno.cpp \
    Model/hashdst.cpp \
    Model/model.cpp \
    Presenter/presenter.cpp \
    View/view.cpp \
    main.cpp \
    DSObjects/dialogendsno.cpp



