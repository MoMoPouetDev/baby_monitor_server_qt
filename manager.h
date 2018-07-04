#ifndef MANAGER_H
#define MANAGER_H

#include "server.h"
#include "decoder.h"
#include "player.h"

class Server;
class Decoder;
class Player;
class Manager : public QObject
{
    //Q_OBJECT

public:
    Manager();
    ~Manager();
    Server* getInstanceServer();
    Decoder* getInstanceDecoder();
    Player* getInstancePlayer();

private:
    Server *m_server;
    Decoder *m_decoder;
    Player *m_player;

};

#endif // MANAGER_H
