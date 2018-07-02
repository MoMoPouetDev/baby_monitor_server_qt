#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>

#include "manager.h"

class Decoder;
class Server : public QWidget
{
    Q_OBJECT

    public:
        Server();
        ~Server();
        Server* getThisServer();
        bool connection();
        void decodeString(const QString &message);
        void sendString(const QString &message);

    private slots:
        void newConnection();
        void receivedData();
        void newDisconnection();
        void getThisDecoder(Decoder*);

    signals:
        void isReadyDecoder(Decoder*);

    private:        
        Decoder* m_decoder;
        QLabel *etatServeur;
        QPushButton *boutonQuitter;

        QTcpServer *serveur;
        QList<QTcpSocket *> clients;
        quint16 tailleMessage;
};

#endif
