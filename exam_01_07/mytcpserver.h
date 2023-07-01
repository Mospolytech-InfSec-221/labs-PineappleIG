#ifndef MYSERVER_H
#define MYSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QString>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();
    ~MyTcpServer();
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void clientDisconnected();
    //void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();
private:
    int server_status;
    QVector <QTcpSocket*> Sockets;
};
#endif // MYSERVER_H







