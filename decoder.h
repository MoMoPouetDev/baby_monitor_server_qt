#ifndef DECODER_H
#define DECODER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>

#include "manager.h"

class Server;
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

    signals:
        void isReadyServer(Server*);

    private:
        Server *m_server;
};

#endif // DECODER_H
