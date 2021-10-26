#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //实例化socket
    sock = new QTcpSocket(this);
    //登录界面槽函数的连接
    connect(sock,SIGNAL(connected()),this,SLOT(onConnected()));

    ui->pushButton_login->setShortcut(Qt::Key_Return);//对应键盘上面大的回车键
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString ip = ui->lineEdit_ip->text();
    int port = ui->lineEdit_port->text().toInt();
    sock->connectToHost(ip, port);
}

void Login::onConnected()
{
    //成功连接后该函数触发，此时发送userName给server
    QJsonObject sendData;
    sendData.insert("code", 0);
    QString username = ui->lineEdit_username->text();
    sendData.insert("newFriend", username);
    QJsonDocument doc(sendData);
    sock->write(doc.toJson());
    //跳转到聊天界面
    chat = new Chat(sock, username);
    this->close();
    chat->show();
}

