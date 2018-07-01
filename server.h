#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>


class Server : public QWidget
{
    Q_OBJECT

    public:
        Server();
        ~Server();
        bool connection();
        void decodeString(const QString &message);
        void sendString(const QString &message);

    private slots:
        void newConnection();
        void receivedData();
        void newDisconnection();

    private:        
        QLabel *etatServeur;
        QPushButton *boutonQuitter;

        QTcpServer *serveur;
        QList<QTcpSocket *> clients;
        quint16 tailleMessage;
};

#endif
