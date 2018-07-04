#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include "manager.h"

class Player : public QObject
{
    //Q_OBJECT

    public:
        Player();
        ~Player();
        Player* getThisPlayer();
        void playMusic(QString);

    private:
        QMediaPlayer *m_player;
};

#endif // PLAYER_H
