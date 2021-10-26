#ifndef LOGIN_H
#define LOGIN_H

#include "chat.h"
#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_login_clicked();
    void onConnected();

private:
    Ui::Login *ui;
    QTcpSocket *sock;
    Chat *chat;
};

#endif // LOGIN_H
