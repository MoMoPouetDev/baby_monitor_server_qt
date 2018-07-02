TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += server.h \
    manager.h \
    decoder.h
SOURCES += server.cpp main.cpp \
    manager.cpp \
    decoder.cpp
