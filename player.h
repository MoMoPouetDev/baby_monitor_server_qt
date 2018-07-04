#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>

#include "manager.h"

#define PATH_DIR_MUSICS "/home/morgan/git/baby_monitor_server_qt/musics/"
#define SOUND_MAX   100
#define SOUND_MIN   0
#define SOUND_MARGIN    10

class Server;
class Player : public QObject
{
    Q_OBJECT

    public:
        Player();
        ~Player();
        Player* getThisPlayer();
        void playMusic(QString);
        void buttonPlus(void);
        void buttonMinus(void);
        void buttonMute(void);
        void getVolumePlayer(void);

    private slots:
        void getThisServer(Server*);
        void changeVolumeBar(int);
        void muteVolumeBar(bool);

    signals:
        void isReadyServer(Server*);
        void volumeChanged(int);
        void mutedChanged(bool);

    private:
        Server *m_server;
        QMediaPlayer *m_player;
};

#endif // PLAYER_H
