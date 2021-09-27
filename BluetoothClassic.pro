QT += quick
QT += bluetooth

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        BluetoothIO.cpp \
        src/bluetooth_controller/InputBluetoothController.cpp \
        src/bluetooth_controller/OutputBluetoothController.cpp \
        src/event/EventListener.cpp \
        src/event/EventSender.cpp \
        src/main.cpp \
        src/connector/DeviceConnector.cpp \
        src/page_controller/ConnectionPageController.cpp \
        src/page_controller/ControlPageController.cpp \
        src/page_controller/SensorPageController.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    BluetoothIO.hpp \
    src/bluetooth_controller/InputBluetoothController.hpp \
    src/bluetooth_controller/OutputBluetoothController.hpp \
    src/connector/DeviceConnector.hpp \
    src/event/EventListener.hpp \
    src/event/EventSender.hpp \
    src/page_controller/ConnectionPageController.hpp \
    src/page_controller/ControlPageController.hpp \
    src/page_controller/SensorPageController.hpp
