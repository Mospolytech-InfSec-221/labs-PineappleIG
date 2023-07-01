#ifndef DATABASE_U_H
#define DATABASE_U_H


#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QString>


class Database_u
{
public:
    static Database_u* GetInstance();

    QString MinPrice();
    QString ExpensiveInType(QString type);
    QString MinPriceInType(QString type);
    QString Expensive();

private:
    static Database_u *instance;
    QSqlDatabase db;

    Database_u();
};

#endif // DATABASE_U_H
