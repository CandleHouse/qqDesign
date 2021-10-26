#ifndef WIDGET_H
#define WIDGET_H

#include "server.h"
#include "dao.h"
#include <QWidget>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_listen_clicked();
    void newUserLogin(QString username, QString ip, QString port);
    void msgForwardingOne2One(QString sender,QString receiver,QString msg);
    void msgForwardingOne2Many(QString sender,QString msg);
    QString currentTime(); //返回固定格式的当前时间字符串
    void logout(QString username);

    void on_pushButton_find_clicked();

private:
    Ui::Widget *ui;
    Server *server; //服务器
    Dao dao; //数据访问层
};

#endif // WIDGET_H
