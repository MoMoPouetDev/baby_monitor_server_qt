#ifndef MANAGER_H
#define MANAGER_H

#include "server.h"
#include "decoder.h"

class Server;
class Decoder;
class Manager : public QObject
{
    Q_OBJECT

public:
    Manager();
    ~Manager();
    Server* getInstanceServer();
    Decoder* getInstanceDecoder();

private:
    Server *m_server;
    Decoder *m_decoder;

};

#endif // MANAGER_H
