TEMPLATE = app
QT += widgets network multimedia
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += server.h \
    manager.h \
    decoder.h \
    player.h
SOURCES += server.cpp main.cpp \
    manager.cpp \
    decoder.cpp \
    player.cpp
