#include <QDebug>
#include <QRegExp>

#include "decoder.h"

Decoder::Decoder() : QObject()
{
    m_process = new QProcess;
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
    library = library.filter(".mp3");
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
        /* Send to the play with url */
        QString musicFile = string[0];

        m_player->playMusic(musicFile);
        m_player->getVolumePlayer();
    }
    else if (string.at(0) == "SoundStop") {
        m_player->stopMusic();
    }
    else if (string.at(0) == "SoundUp") {
        m_player->buttonPlus();
    }
    else if (string.at(0) == "SoundDown") {
        m_player->buttonMinus();
    }
    else if (string.at(0) == "SoundMute") {
        m_player->buttonMute();
    }
    else if (string.at(0) == "Volume") {
        m_player->getVolumePlayer();
    }
    else if (string.at(0) == "PowerOff") {
        m_process->startDetached(m_powerOff);
    }
}

void Decoder::sendMusicLibrary()
{
    QStringList library = getLibrary();
    library.insert(0,"Library");
    QString libraryString = library.join(";");

    m_server->sendString(libraryString);
}
