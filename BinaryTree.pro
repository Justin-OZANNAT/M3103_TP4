TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    node.hpp \
    binarysearchtree.hpp

QMAKE_MAC_SDK = macosx10.13
