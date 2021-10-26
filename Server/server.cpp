#include "server.h"

Server::Server()
{

}

Server::Server(int port)
{
    listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<socketDescriptor;
    QTcpSocket *senderSocket = new QTcpSocket(this);
    senderSocket->setSocketDescriptor(socketDescriptor);
    connect(senderSocket, SIGNAL(readyRead()), this, SLOT(onReadReady()));
    connect(senderSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    //放入列表 username在onReadReady中确定
    clients.append({socketDescriptor," ",senderSocket});
}

int Server::find(QString userName)
{
    for(int i = 0;i<clients.length();i++){
        auto client = clients[i];
        if(client.userName == userName) return i;
    }
}

int Server::find(qintptr socketDescriptor)
{
    for(int i = 0;i<clients.length();i++){
        auto client = clients[i];
        if(client.socketDescriptor == socketDescriptor) return i;
    }
}

int Server::find(QTcpSocket *socket)//找到socket对应的结构体下标
{
    QHostAddress clientIp = socket->peerAddress();
    quint16 clientPort = socket->peerPort();
    //利用ip和port从clients找到这个socket对应的结构体并删除
    int i;
    for(i = 0;i<clients.length();i++){
        auto client = clients[i];
        if(clientIp == client.socket->peerAddress() && clientPort == client.socket->peerPort()){
            break;
        }
    }
    return i;
}


void Server::onReadReady()
{
    //获取触发这个槽函数的senderSocket
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(this->sender());
    //当前客户的索引
    int senderIndex = find(senderSocket->socketDescriptor());
    //获取消息字符串
    QJsonObject recvData = QJsonDocument::fromJson(senderSocket->readAll()).object();
    //如果这是一个登录请求
    if(recvData.value("code").toInt()==0)
    {
        QString username = recvData.value("newFriend").toString();
        clients[senderIndex].userName = username;
        QString ip = QHostAddress(senderSocket->peerAddress().toIPv4Address()).toString();
        QString port = QString::number(senderSocket->peerPort());
        qDebug()<<"username:"+username;
        qDebug()<<"ip:"+ip;
        qDebug()<<"ip:"+port;

        //向所有客户端发送上线用户的名字
        QJsonObject sendData;
        sendData.insert("code", 0);
        QJsonArray friendList;
        for (int i = 0; i < clients.length(); ++i) {
            friendList.append(clients[i].userName);
        }
        sendData.insert("friendList", friendList);
        QJsonDocument doc(sendData);
        for (int i = 0; i < clients.length(); ++i) {
            clients[i].socket->write(doc.toJson());
        }
        //向主界面提交用户登录信号
        emit loginSuccess(username, ip, port);
    }
    else if(recvData.value("code").toInt()==1)
    {
        //如果这是一个消息转发请求
        QString receiverName = recvData.value("receiver").toString();
        QJsonObject &sendData=recvData;
//        sendData.insert("code", 1);
//        sendData.insert("msg", recvData.value("msg").toString());
//        sendData.insert("sender", clients[senderIndex].userName);
        QJsonDocument doc(sendData);
        //找到接受方的socket 将数据发送出去
        clients[find(receiverName)].socket->write(doc.toJson());
        emit msgForwardingOne2One(recvData.value("sender").toString(),
                                  recvData.value("receiver").toString(),
                                  recvData.value("msg").toString());
    }
    else if(recvData.value("code").toInt()==2)
    {
        //如果这是一个消息群发请求
        QJsonObject &sendData=recvData;
        QJsonDocument doc(sendData);
        //群发
        for (int i = 0; i < clients.length(); ++i) {
            //不向发送方转发
            if (senderIndex == i) continue;
            clients[i].socket->write(doc.toJson());
        }
        emit msgForwardingOne2Many(recvData.value("sender").toString(),
                                   recvData.value("msg").toString());
    }
}

void Server::onDisconnected()
{
    qDebug() << "Disconnected!!";
    //获取触发这个槽函数的senderSocket
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(this->sender());
    //当前客户的索引
    int index = find(socket);
    //通知其他客户端该用户下线
    QJsonObject sendData;
    sendData.insert("code", 3);
    sendData.insert("username", clients[index].userName);
    QJsonDocument doc(sendData);
    //群发
    for (int i = 0; i < clients.length(); ++i) {
        if (i == index) continue;
        clients[i].socket->write(doc.toJson());
    }
    //修改监控台界面
    logout(clients[index].userName);
    //删除socket
    clients.remove(index);
    socket->deleteLater();
}



