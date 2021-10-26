#ifndef CHAT_H
#define CHAT_H
#define GROUP "群聊"

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include <QMap>
#include <QListWidgetItem>
#include <QDateTime>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QTcpSocket* _sock, QString _username, QWidget *parent = 0);
    ~Chat();

private slots:
    void onReadReady();

    void on_pushButton_send_clicked();

    void on_listWidget_friends_itemClicked(QListWidgetItem *item);

private:
    Ui::Chat *ui;
    QTcpSocket *sock;
    QString username;
    QMap<QString, QString> records; // 保存聊天记录 username->log
    QString currentTime(); //返回固定格式的当前时间字符串
};

#endif // CHAT_H
