QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    PersonDialog.cpp \
    main.cpp \
    Widget.cpp

HEADERS += \
    PersonDialog.h \
    Widget.h

FORMS += \
    PersonDialog.ui \
    Widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
