include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += thread
CONFIG += qt
QT += bluetooth

HEADERS += \
        tst_firsttest.hpp
        ../../BluetoothIO.hpp

SOURCES += \
        main.cpp
        ../../BluetoothIO.cpp
