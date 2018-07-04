#ifndef DECODER_H
#define DECODER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QProcess>

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

        QString m_powerOff = "/sbin/shutdown now";
        QProcess *m_process;
};

#endif // DECODER_H
