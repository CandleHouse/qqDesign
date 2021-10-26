#ifndef DAO_H
#define DAO_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Dao : public QObject
{
    Q_OBJECT
public:
    explicit Dao(QObject *parent = nullptr);
    QSqlQueryModel* getQmodel() const;
    void insertUser(QString username, QString ip, QString port);
    void updateQmodel();
    void deleteQmodel(QString username);

private:
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlQueryModel *qmodel;

signals:

public slots:

};

#endif // DAO_H
