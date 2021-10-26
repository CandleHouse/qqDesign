#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_listen_clicked()
{
    //服务器socket部分
    int port = ui->lineEdit_port->text().toInt();
    server = new Server(port);
    QMessageBox::about(this,"消息","已开启监听服务");
    ui->pushButton_listen->setDisabled(true);
    ui->lineEdit_port->setDisabled(true);

    connect(server, SIGNAL(loginSuccess(QString,QString,QString)),
            this, SLOT(newUserLogin(QString,QString,QString)));
    connect(server, SIGNAL(msgForwardingOne2One(QString,QString,QString)),
            this, SLOT(msgForwardingOne2One(QString,QString,QString)));
    connect(server, SIGNAL(msgForwardingOne2Many(QString,QString)),
            this, SLOT(msgForwardingOne2Many(QString,QString)));
    connect(server, SIGNAL(logout(QString)), this, SLOT(logout(QString)));

    //tableView_online部分
    ui->tableView_online->setModel(dao.getQmodel());
}

void Widget::newUserLogin(QString username, QString ip, QString port)
{
    //    qDebug()<<"hello!";
    qDebug()<<"username:"+username;
    qDebug()<<"ip:"+ip;
    qDebug()<<"port:"+port;
    //更新日志
    QString info = QString("[%1] 用户[%2]登录").arg(currentTime()).arg(username);
    ui->listWidget_log->addItem(info);
    //将三个数据加入数据库
    dao.insertUser(username, ip, port);
    //更新qmodel
    dao.updateQmodel();


}

void Widget::msgForwardingOne2One(QString sender, QString receiver, QString msg)
{
    //更新日志
    QString info = QString("[%1] 用户[%2]向用户[%3]发送消息[%4]")
            .arg(currentTime())
            .arg(sender)
            .arg(receiver)
            .arg(msg);

    ui->listWidget_log->addItem(info);
}

void Widget::msgForwardingOne2Many(QString sender, QString msg)
{
    //更新日志
    QString info = QString("[%1] 用户[%2]在群里发送消息[%3]")
            .arg(currentTime())
            .arg(sender)
            .arg(msg);

    ui->listWidget_log->addItem(info);
}

QString Widget::currentTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    return currentTime.toString("yyyy-MM-dd hh:mm:ss");
}

void Widget::logout(QString username)
{
    //更新日志
    QString info = QString("[%1] 用户[%2]下线").arg(currentTime()).arg(username);
    ui->listWidget_log->addItem(info);
    //删除用户
    dao.deleteQmodel(username);
    //更新qmodel
    dao.updateQmodel();
}

void Widget::on_pushButton_find_clicked()
{
    //查找item
    QListWidgetItem *item = ui->listWidget_log->findItems(ui->lineEdit_content->text(), Qt::MatchContains)[0];
//    qDebug()<<item;
    if(item){
//        qDebug()<<item->text();
        //跳转
        ui->listWidget_log->setCurrentItem(item);
    }
}
