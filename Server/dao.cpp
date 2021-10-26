#include "dao.h"

Dao::Dao(QObject *parent) : QObject(parent)
{
    //打开数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("charRoom.db");
    db.open();

    //数据库查询
    query = new QSqlQuery();
    //创建表 如果表存在 则不创建
    query->exec("create table userinfo(username, ip, port)");
    //删除表中所有数据
    query->exec("delete from userinfo");

    //实例化数据库模板
    qmodel = new QSqlQueryModel();
}

QSqlQueryModel *Dao::getQmodel() const
{
    return qmodel;
}

void Dao::updateQmodel()
{
    qmodel->setQuery("select * from userinfo");
}

void Dao::deleteQmodel(QString username)
{
    QString sql = QString("delete from userinfo where username = '%1'").arg(username);
    query->exec(sql);
}

void Dao::insertUser(QString username, QString ip, QString port)
{
    QString sql = QString("insert into userinfo values ('%1', '%2', '%3')").arg(username).arg(ip).arg(port);
    query->exec(sql);
}

