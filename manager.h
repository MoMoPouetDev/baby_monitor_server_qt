#ifndef MANAGER_H
#define MANAGER_H

#include "server.h"

class Server;
class Manager : public QObject
{
    Q_OBJECT

public:
    Manager();
    ~Manager();
    Server* getInstanceServer();

private:
    Server *m_server;

};

#endif // MANAGER_H
