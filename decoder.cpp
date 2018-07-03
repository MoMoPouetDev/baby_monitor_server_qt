#include <QDebug>
#include "decoder.h"

Decoder::Decoder() : QObject()
{
    QObject::connect(this, SIGNAL(isReadyServer(Server*)), this, SLOT(getThisServer(Server*)));
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

QStringList Decoder::getLibrary()
{
    QStringList library(QDir("/home/morgan/git/baby_monitor_server_qt/musics/").entryList());
    qDebug() << library;
    return library;
}

void Decoder::decodeString(const QString &message)
{
    qDebug()<<"Decoder: " + message;

    if(message == "Library")
    {
        sendMusicLibrary();
    }
    else if(message == "SoundUp")
    {}
    else if(message == "SoundDown")
    {}
    else if(message == "SoundMute")
    {}
    else if(message == "SoundUnmute")
    {}
    else if(message == "PowerOff")
    {}
    else
    {
        /*Parcour List music*/
    }
}

void Decoder::sendMusicLibrary()
{
    QStringList library = getLibrary();
    QString libraryString = library.join(";");

    m_server->sendString(libraryString);
}
