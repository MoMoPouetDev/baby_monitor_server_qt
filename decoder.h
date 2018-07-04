#ifndef DECODER_H
#define DECODER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>

#include "manager.h"

class Server;
class Player;
class Decoder : public QObject
{
    Q_OBJECT

    public:
        Decoder();
        ~Decoder();
        Decoder* getThisDecoder();
        void decodeString(const QString &message);
        void sendMusicLibrary();
        QStringList getLibrary();

    private slots:
        void getThisServer(Server*);
        void getThisPlayer(Player*);

    signals:
        void isReadyServer(Server*);
        void isReadyPlayer(Player*);

    private:
        Server *m_server;
        Player *m_player;
};

#endif // DECODER_H
