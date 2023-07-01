#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <iostream>
#include "database_u.h"

MyTcpServer::~MyTcpServer()
{
    server_status=0;
}

MyTcpServer::MyTcpServer()
{
    if (this->listen(QHostAddress::Any, 33333))
    {
        server_status = 1;
        qDebug()<<"Server started!";
    }
    else
    {
        qDebug()<<"Lost connection!";
    }
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    if(server_status == 1)
    {
        QTcpSocket *socket = new QTcpSocket;
        socket->setSocketDescriptor(socketDescriptor);
        connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::clientDisconnected);
        Sockets.push_back(socket);
        qDebug()<<"Client connected!"<<socketDescriptor;
    }
}

void MyTcpServer::clientDisconnected()
{
    QTcpSocket* client = (QTcpSocket *)sender();
    if (client) {
        client->deleteLater();
        for (int i = 0; i < Sockets.size(); i++) {
            if (Sockets[i] == client) {
                Sockets.remove(i);
                break;
            }
        }
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket* socket = (QTcpSocket*)sender();
    while (socket->bytesAvailable() > 0)
    {
        QString result = "";
        QString data = socket->readAll();
        QStringList params = data.trimmed().split("&");
        if (params.size() == 1 && params[0] == "min_price") {
            result = Database_u::GetInstance()->MinPrice();
        }
        else if (params.size() == 2 && params[0] == "expensive_in_type") {
            result = Database_u::GetInstance()->ExpensiveInType(params[1]);
        }
        else if (params.size() == 2 && params[0] == "min_price_in_type") {
            result = Database_u::GetInstance()->MinPriceInType(params[1]);
        }
        else if (params.size() == 1 && params[0] == "expensive") {
            result = Database_u::GetInstance()->Expensive();
        } else {
            result = "Invalid command\r\n";
        }

        socket->write(result.toUtf8());
    }
}
