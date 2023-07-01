#include "database_u.h"

#include <QSqlError>
#include <QSqlRecord>

Database_u *Database_u::instance;

Database_u::Database_u()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); // Добавление базы данных
    db.setDatabaseName("products.db"); // Перезапись имени базы данных для корректной работы кода
    if(db.open())
    {
        qDebug("open db"); // Выводится при корректной работе кода
    }
    else
    {
        qDebug("not open db"); // Выводится при некорректной работе кода
    }
}

Database_u* Database_u::GetInstance() // Если база данных не запущена
{
    if (Database_u::instance == NULL)
    {
        Database_u::instance = new Database_u();
    }

    return Database_u::instance;
}

QString Database_u::MinPrice()
{
    QString result = "";

    QSqlQuery *query = new QSqlQuery(db);
    query->exec("SELECT products.Name, products.Price from products ORDER BY Price LIMIT 10");

    while (query->next())
    {
        QString name = query->value(0).toString();
        QString price = query->value(1).toString();
        result += name;
        result += "\t" + price;
        result += "\r\n";
    }

    return result;
}

QString Database_u::ExpensiveInType(QString type)
{
    QString result = "";

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT AVG(products.Price) from products WHERE Type = :Type");
    query->bindValue(":Type", type);
    query->exec();

    if (!query->next())
    {
        return "Invalid type";
    }

    double avg = query->value(0).toDouble();
    query->prepare("SELECT products.Name, products.Price from products WHERE Price > :Avg");
    query->bindValue(":Avg", avg);
    query->exec();

    while (query->next())
    {
        QString name = query->value(0).toString();
        QString price = query->value(1).toString();
        result += name;
        result += "\t" + price;
        result += "\r\n";
    }

    return result;
}

QString Database_u::MinPriceInType(QString type)
{
    QString result = "";

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT products.Name, products.Price from products WHERE Type = :Type ORDER BY Price LIMIT 10");
    query->bindValue(":Type", type);
    query->exec();

    while (query->next())
    {
        QString name = query->value(0).toString();
        QString price = query->value(1).toString();
        result += name;
        result += "\t" + price;
        result += "\r\n";
    }

    return result;
}

QString Database_u::Expensive()
{
    QString result = "";

    QSqlQuery *query = new QSqlQuery(db);
    query->exec("SELECT AVG(products.Price) from products");

    if (!query->next())
    {
        return "Emtpy products";
    }

    double avg = query->value(0).toDouble();
    query->prepare("SELECT products.Name, products.Price from products WHERE Price > :Avg LIMIT 10" );
    query->bindValue(":Avg", avg);
    query->exec();

    while (query->next())
    {
        QString name = query->value(0).toString();
        QString price = query->value(1).toString();
        result += name;
        result += "\t" + price;
        result += "\r\n";
    }

    return result;
}
