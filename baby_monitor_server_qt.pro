TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += server.h \
    manager.h
SOURCES += server.cpp main.cpp \
    manager.cpp
