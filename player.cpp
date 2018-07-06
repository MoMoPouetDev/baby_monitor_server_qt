
#include "player.h"

Player::Player()
{
    m_player = new QMediaPlayer(this);
    m_player->setVolume(50);

    QObject::connect(m_player, SIGNAL(volumeChanged(int)), this, SLOT(changeVolumeBar(int)));
    QObject::connect(m_player, SIGNAL(mutedChanged(bool)), this, SLOT(muteVolumeBar(bool)));
    QObject::connect(this, SIGNAL(isReadyServer(Server*)), this, SLOT(getThisServer(Server*)));
}

Player::~Player()
{
}

Player* Player::getThisPlayer()
{
    return this;
}

void Player::getThisServer(Server *server)
{
    m_server = server;
}

void Player::playMusic(QString music)
{
    QString musicPath = PATH_DIR_MUSICS+music;

    m_player->setMedia(QUrl::fromLocalFile(musicPath));
    m_player->play();
}

void Player::stopMusic()
{
    m_player->stop();
}

void Player::buttonPlus(void)
{
    if(m_player->isMuted())
    {
        m_player->setMuted(false);
    }
    if( m_player->volume() <= SOUND_MAX)
    {
        m_player->setVolume((m_player->volume())+SOUND_MARGIN);
    }
}

void Player::buttonMinus(void)
{
    if(m_player->isMuted())
    {
        m_player->setMuted(false);
    }
    if(m_player->volume() >= SOUND_MIN)
    {
        m_player->setVolume((m_player->volume())-SOUND_MARGIN);
    }
}

void Player::buttonMute(void)
{
    if(m_player->isMuted())
    {
        qDebug() << "if";
        m_player->setMuted(false);
        m_server->sendString("Mute;false");
    }
    else
    {
        qDebug() << "else";
        m_player->setMuted(true);
        m_server->sendString("Mute;true");
    }
}

void Player::getVolumePlayer()
{
    QString volumeString = QString::number(m_player->volume());
    volumeString = "Volume;" + volumeString;
    m_server->sendString(volumeString);
}

void Player::changeVolumeBar(int volume)
{
    QString volumeString = QString::number(volume);
    volumeString = "Volume;" + volumeString;
    m_server->sendString(volumeString);
}

void Player::muteVolumeBar(bool mute)
{
    /*if (mute){
        m_server->sendString("Mute;true");
    }
    else {
        m_server->sendString("Mute;false");
    }*/
}
