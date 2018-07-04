
#include "player.h"

Player::Player()
{
    m_player = new QMediaPlayer(this);
}

Player::~Player()
{
}

Player* Player::getThisPlayer()
{
    return this;
}

void Player::playMusic(QString music)
{
    m_player->setMedia(QUrl::fromLocalFile(music));
    m_player->play();
    m_player->setVolume(50);
}
