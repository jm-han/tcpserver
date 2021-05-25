#include "mytcpserver.h"
#include "serverthread.h"

MyTcpServer::MyTcpServer(QObject *parent) :
    QTcpServer(parent)
{
//    server = new QTcpServer(this);

//    // whenever a user connects, it will emit signal
//    connect(server, SIGNAL(newConnection()),
//            this, SLOT(newConnection()));

//    if(!server->listen(QHostAddress::Any, 9999))
//    {
//        qDebug() << "Server could not start";
//    }
//    else
//    {
//        qDebug() << "Server started!";
//    }
}

//void MyTcpServer::newConnection()
//{
//    // need to grab the socket
//    QTcpSocket *socket = server->nextPendingConnection();

//    socket->write("Hello client\r\n");
//    socket->flush();

//    socket->waitForBytesWritten(3000);

//    socket->close();
//}

void MyTcpServer::incomingConnection(int sockDesc)
{
    //m_socketList.append(sockDesc);

    serverThread *thread = new serverThread(sockDesc);

    //m_dialog->showConnection(sockDesc);

    connect(thread, SIGNAL(disconnectTCP(int)), this, SLOT(clientDisconnected(int)));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

//    connect(thread, SIGNAL(dataReady(const QString&, const QByteArray&)),
//            m_dialog, SLOT(recvData(const QString&, const QByteArray&)));

//    connect(m_dialog, SIGNAL(sendData(int, const QByteArray&)),
//            thread, SLOT(sendDataSlot(int, const QByteArray&)));

    thread->start();
}

void MyTcpServer::clientDisconnected(int sockDesc)
{
    //m_dialog->showDisconnection(sockDesc);
}
