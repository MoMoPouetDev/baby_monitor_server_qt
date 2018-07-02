#include "decoder.h"

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

Decoder* Decoder::getThisDecoder()
{
    return this;
}

QStringList Decoder::getLibrary()
{
    QStringList library(QDir("/home/morgan/git/baby_monitor_server_qt/musics/").entryList());
    qDebug() << library;
}

void Decoder::decodeString(const QString &message)
{
    qDebug()<<"Decder: " + message;

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

}
