#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

struct Client{
    qintptr socketDescriptor;
    QString userName;
    QTcpSocket *socket;
};

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    Server(int port);
    void incomingConnection(qintptr socketDescriptor);

private:
    //    QTcpSocket *clientSocket;
    QVector<Client> clients;
    int find(QString userName);
    int find(qintptr socketDescriptor);
    int find(QTcpSocket *socket);

private slots:
    void onReadReady();
    void onDisconnected();

signals:
    void loginSuccess(QString, QString, QString);
    void msgForwardingOne2One(QString, QString, QString);
    void msgForwardingOne2Many(QString, QString);
    void logout(QString);
};

#endif // SERVER_H
