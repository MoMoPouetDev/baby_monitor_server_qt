#include "QDebug"

#include "manager.h"

Manager::Manager() : QObject()
{
    m_server = new Server;

    m_server->show();
}

Manager::~Manager()
{
    m_server->deleteLater();
}

Server* Manager::getInstanceServer()
{
    return m_server;
}
