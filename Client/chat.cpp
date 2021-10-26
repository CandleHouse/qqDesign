#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket* _sock, QString _username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    sock = _sock;
    username = _username;
    this->setWindowTitle("用户: " + username);
    //onReadyRead()
    connect(sock,SIGNAL(readyRead()),this,SLOT(onReadReady()));

    ui->listWidget_friends->addItem(GROUP);
    //在聊天记录表中新增
    records[GROUP]="";
    ui->pushButton_send->setShortcut(Qt::Key_Return);//对应键盘上面大的回车键
}

Chat::~Chat()
{
    delete ui;
}

void Chat::onReadReady()
{
    //获取消息字符串
    QJsonObject recvData = QJsonDocument::fromJson(sock->readAll()).object();
    qDebug()<<recvData;

    //好友列表广播消息
    if (recvData.value("code").toInt()==0)
    {
        QJsonArray friendList = recvData.value("friendList").toArray();
        for (int i = 0; i < friendList.size(); ++i) {
            //如果好友不存在，在聊天列表和记录中新增
            if(!records.contains(friendList[i].toString())
                    && username!=friendList[i].toString())
            {
                QString newFriend=friendList[i].toString();
                ui->listWidget_friends->addItem(newFriend);
                records[newFriend]="";
                QString SysInfo = QString("[%1] 您的好友[%2]已上线").arg(currentTime()).arg(newFriend);
                ui->listWidget_sysInfo->addItem(SysInfo);
            }
        }
    }
    //接收到某一好友的数据
    else if (recvData.value("code").toInt()==1)
    {
        QString sender = recvData.value("sender").toString();
        QString msg = recvData.value("msg").toString();
        QString text = QString("               [%1]\n %2:%3\n")
                .arg(currentTime())
                .arg(sender)
                .arg(msg);
        records[sender] += text;
        //消息框里出现消息
        if (ui->listWidget_friends->currentItem()->text()==sender) {
            ui->textBrowser_record->setText(records[sender]);
        }
        QString SysInfo = QString("[%1] 您的好友[%2]给您发消息了").arg(currentTime()).arg(sender);
        ui->listWidget_sysInfo->addItem(SysInfo);
        qDebug()<<text;
    }
    //接收到群聊消息
    else if (recvData.value("code").toInt()==2)
    {
        QString sender = recvData.value("sender").toString();
        QString msg = recvData.value("msg").toString();
        QString text = QString("               [%1]\n %2:%3\n")
                .arg(currentTime())
                .arg(sender)
                .arg(msg);
        if(sender!=username)
            records[GROUP] += text;

        if (ui->listWidget_friends->currentItem()->text()==GROUP) {
            ui->textBrowser_record->setText(records[GROUP]);
        }
        QString SysInfo = QString("[%1] 您的好友[%2]在群里发消息了").arg(currentTime()).arg(sender);
        ui->listWidget_sysInfo->addItem(SysInfo);
    }
    //接受到好友下线通知
    else if (recvData.value("code").toInt()==3)
    {
        QString friendName = recvData.value("username").toString();
        QString SysInfo = QString("[%1] 您的好友[%2]下线了").arg(currentTime()).arg(friendName);
        ui->listWidget_sysInfo->addItem(SysInfo);

        //查找item
        QListWidgetItem *item = ui->listWidget_friends->findItems(friendName,Qt::MatchExactly)[0];
        //删除这item
        ui->listWidget_friends->removeItemWidget(item);
        update();//刷新
        delete item;//删除指针
    }
}


void Chat::on_pushButton_send_clicked()
{
    //判断发送消息前是否选择了好友
    if(ui->listWidget_friends->currentRow()==-1)
    {
        QMessageBox::about(this, "提示", "请先选择一名好友");
        return;
    }

    //将消息写入聊天记录中
    QString sender = username;
    QString receiver = ui->listWidget_friends->currentItem()->text();
    QString msg = ui->textEdit_send->toPlainText();
    QString text = QString("               [%1]\n %2:%3\n")
            .arg(currentTime())
            .arg(sender)
            .arg(msg);
    records[receiver] += text;
    ui->textBrowser_record->setText(records[receiver]);

    //发送消息
    QJsonObject sendData;
    sendData.insert("code",
                    ui->listWidget_friends->currentItem()->text() != GROUP ? 1:2);//如果是群聊 如果是好友
    sendData.insert("msg", msg);
    sendData.insert("sender", sender);
    sendData.insert("receiver", receiver);
    QJsonDocument doc(sendData);
    sock->write(doc.toJson());
    //清空聊天框
    ui->textEdit_send->setText("");
}

void Chat::on_listWidget_friends_itemClicked(QListWidgetItem *item)
{
    ui->textBrowser_record->setText(records[item->text()]);
}

QString Chat::currentTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    return currentTime.toString("yyyy-MM-dd hh:mm:ss");
}
