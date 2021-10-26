# Qt笔记

## 命名风格

变量用驼峰式

函数用下划线

## 数据库

### pro

```
sql
```

### 头文件

```c++
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
```

### sql查询语句占位符

```c++
QString str=QString("select * from user where name='%1' and passward='%2'").arg(name).arg(passward);
```



### sql连接并打开数据库

```c++
db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("user.db");
db.open();
```



### sql语句

```
SELECT LastName FROM Persons
INSERT INTO 表名称 VALUES (值1, 值2,....)
UPDATE Person SET FirstName = 'Fred' WHERE LastName = 'Wilson' 
DELETE FROM Person WHERE LastName = 'Wilson' 
```



## 客户端socket

### 连接

```c++
//连接到本机的8888号端口，本机服务器在这个端口监听
    tcpSocket.connectToHost("127.0.0.1",8888);
```

### socket槽函数的连接

```c++
//槽函数的连接
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadReady()));
    connect(&tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected));
          connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));

```

### 发送

```c++
//成功连接后该函数触发，此时发送userName给server
    QString msg = "0:"+ui->lineEdit_username->text();
    sock->write(msg.toUtf8());
```

### 读取

```c++
 qDebug()<<sock->bytesAvailable();
    if (sock->bytesAvailable()>0) {
        char buffer[1024];
        sock->read(buffer, sock->bytesAvailable());
        qDebug()<<buffer;
    }
```



```c++
QString msg = (QString)clientSocket->readAll();
```



### 多客户端

```c++
    QList<TcpClientSocket*> tcpclientsocketlist;
```

```c++
 //将这个套接字加入客户端套接字列表中
    tcpclientsocketlist.append(tcpclientsocket);
```

需要注意的是当QTcpSocket断开连接时，记得删除QList<QTcpSocket*> tcpSocketConnetList中的QTcpSocket对象。。。 

```c++
    void TcpServer::Socket_Disconnected(int descriptor)
{
    for(int i = 0; i < tcpSocketConnetList.count(); i++)
    {
        QTcpSocket *item = tcpSocketConnetList.at(i);
        int temp = item->socketDescriptor();
        if(-1 == temp||temp == descriptor)            //测试中发现，当disconnected()信号发出，item->socketDescriptor()返回值已经为-1了，不能通过item->socketDescriptor() == descriptor来进行判断了。。。所以删除返回值为-1的QTcpSocket对象
        {
            tcpSocketConnetList.removeAt(i);//如果有客户端断开连接， 就将列表中的套接字删除
            item->deleteLater();
            qDebug()<< "[TcpSocket]---------------------------------Disconnect:" << descriptor << endl;
            return;
        }
    }
    return;
}
```

获取发出信号的socket

```c++
QObject * obj = this->sender();
QTcpSocket * socket = qobject_cast<QTcpSocket*>(obj);  
```



## 其他

### 时间

```c++
QDateTime currentTime = QDateTime::currentDateTime();
```



### 格式处理

```c++
QDateTime currentTime = QDateTime::currentDateTime();
        //设置item的数据
        int splitSign = text.lastIndexOf("#");
        QString sender = text.mid(splitSign+1);
        text = text.mid(0,splitSign);
        QStandardItem *item = new QStandardItem(QString(sender+"： [%1]\n  %2\n").
                              arg(currentTime.toString("yyyy-MM-dd hh:mm:ss")).arg(text));
```



## Qt json的使用

### 头文件

```c++
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
```

### json数据通过tcp发送

```c++
//成功连接后该函数触发，此时发送userName给server
    QJsonObject data;
    data.insert("code", 0);
    data.insert("username", ui->lineEdit_username->text());
    QJsonDocument doc(data);
    sock->write(doc.toJson());
```

### tcp接受json数据

```c++
//获取消息字符串
    QJsonObject data = QJsonDocument::fromJson(clientSocket->readAll()).object();
```

### 用key取数据

```c++
QString username = data.value("username").toString();
```

```c++
data.value("code").toInt()
```

### 遍历

```c++
QJsonObject jsonConfig;
 
 QJsonObject::Iterator iteratorJson;
 iteratorJson = jsonConfig.begin();
 while(iteratorJson != jsonConfig.end()){
     QString strVal = iteratorJson.value().toString();

     qDebug()<<"值："<<strVal;
     iteratorJson++;
 }
```



## Qt打包

https://blog.csdn.net/windsnow1/article/details/78004265

1. 将release下的exe文件放在一个新的文件夹里 在 win10 查找qt 打开对应编辑器的命令行
2. 输入cd /d 文件位置
3. 输入命令 windeployqt 程序名  

 