#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);
    
signals:
    
public slots:
    //void newConnection();

private:
    //QTcpServer *server;

private:
    void incomingConnection(int sockDesc);

private slots:
    void clientDisconnected(int sockDesc);
};

#endif // MYTCPSERVER_H
