#include <QDebug>
#include <QRegExp>

#include "decoder.h"

Decoder::Decoder() : QObject()
{
    QObject::connect(this, SIGNAL(isReadyServer(Server*)), this, SLOT(getThisServer(Server*)));
    QObject::connect(this, SIGNAL(isReadyPlayer(Player*)), this, SLOT(getThisPlayer(Player*)));
}

Decoder::~Decoder()
{
}

Decoder* Decoder::getThisDecoder()
{
    return this;
}

void Decoder::getThisServer(Server* server)
{
    m_server = server;
}

void Decoder::getThisPlayer(Player *player)
{
    m_player = player;
}

QStringList Decoder::getLibrary()
{
    QStringList library(QDir("/home/morgan/git/baby_monitor_server_qt/musics/").entryList());
    library = library.filter(".wav");
    qDebug() << library;
    return library;
}

void Decoder::decodeString(const QString &message)
{
    qDebug()<<"Decoder: " + message;

    QRegExp regex("\\;");
    QStringList string = message.split(regex);

    if (string.at(0) == "Library") {
        sendMusicLibrary();
    }
    else if (string.at(0) == "Play") {
        string.removeFirst();
        qDebug() << "play music: " << string;
        /* Send to the play with url */
    }
    else if (string.at(0) == "Volume") {

    }
    else if (string.at(0) == "SoundUp") {

    }
    else if (string.at(0) == "SoundDown") {

    }
    else if (string.at(0) == "SoundMute") {

    }
    else if (string.at(0) == "SoundUnmute") {

    }
    else if (string.at(0) == "PowerOff") {

    }
}

void Decoder::sendMusicLibrary()
{
    QStringList library = getLibrary();
    library.insert(0,"Library");
    QString libraryString = library.join(";");

    m_server->sendString(libraryString);
}
