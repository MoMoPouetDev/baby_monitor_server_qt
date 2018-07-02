#include "QDebug"

#include "manager.h"

Manager::Manager() : QObject()
{
    m_decoder = new Decoder;
    m_server = new Server;
    emit m_server->isReadyDecoder(m_decoder);
    //emit m_decoder->isReadyServer(m_server);

    m_server->show();
}

Manager::~Manager()
{
    m_decoder->deleteLater();
    m_server->deleteLater();
}

Server* Manager::getInstanceServer()
{
    return m_server;
}

Decoder* Manager::getInstanceDecoder()
{
    return m_decoder;
}
