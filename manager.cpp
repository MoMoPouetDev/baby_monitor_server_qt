#include "QDebug"

#include "manager.h"

Manager::Manager() : QObject()
{
    m_server = new Server;
    m_decoder = new Decoder;
    emit m_server->isReadyDecoder(m_decoder);
    emit m_decoder->isReadyServer(m_server);

    m_player = new Player;
    emit m_decoder->isReadyPlayer(m_player);

    m_server->show();
}

Manager::~Manager()
{
    m_decoder->deleteLater();
    m_server->deleteLater();
    m_player->deleteLater();
}

Server* Manager::getInstanceServer()
{
    return m_server;
}

Decoder* Manager::getInstanceDecoder()
{
    return m_decoder;
}

Player* Manager::getInstancePlayer()
{
    return m_player;
}
