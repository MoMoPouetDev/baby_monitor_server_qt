#include "server.h"

Server::Server()
{
    // Gestion du serveur
    serveur = new QTcpServer(this);

    while(!connection());

    QObject::connect(this, SIGNAL(isReadyDecoder(Decoder*)), this, SLOT(getThisDecoder(Decoder*)));

    tailleMessage = 0;
}

Server::~Server()
{
    serveur->deleteLater();
}

Server* Server::getThisServer()
{
    return this;
}

void Server::newConnection()
{
    QTcpSocket *client = serveur->nextPendingConnection();
    clients << client;

    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(receivedData()));
    QObject::connect(client, SIGNAL(disconnected()), this, SLOT(newDisconnection()));
}

void Server::receivedData()
{
    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    // Si tout va bien, on continue : on récupère le message
    QDataStream in(socket);

    if (tailleMessage == 0) // Si on ne connaît pas encore la taille du message, on essaie de la récupérer
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16)) // On n'a pas reçu la taille du message en entier
             return;

        in >> tailleMessage; // Si on a reçu la taille du message en entier, on la récupère
    }

    // Si on connaît la taille du message, on vérifie si on a reçu le message en entier
    if (socket->bytesAvailable() < tailleMessage) // Si on n'a pas encore tout reçu, on arrête la méthode
        return;


    // Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !
    QString message;
    in >> message;


    // 2 : on renvoie le message à tous les clients
    decodeString(message);

    // 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
    tailleMessage = 0;
}

void Server::newDisconnection()
{
    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void Server::getThisDecoder(Decoder* decoder)
{
    m_decoder = decoder;
}

bool Server::connection()
{
    if (!serveur->listen(QHostAddress("192.168.1.25"), 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
        etatServeur = "Le serveur n'a pas pu être démarré. Raison :" + serveur->errorString();
        qDebug() << etatServeur;
        return false;
    }
    else
    {
        // Si le serveur a été démarré correctement
        etatServeur = "Le serveur a été démarré sur le port" + QString::number(serveur->serverPort()) + ". Des clients peuvent maintenant se connecter.";
        qDebug() << etatServeur;
        connect(serveur, SIGNAL(newConnection()), this, SLOT(newConnection()));
        return true;
    }
}

void Server::decodeString(const QString &message)
{
    m_decoder->decodeString(message);
}

void Server::sendString(const QString &message)
{
    // Préparation du paquet
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message


    // Envoi du paquet préparé à tous les clients connectés au serveur
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->write(paquet);
    }

}
