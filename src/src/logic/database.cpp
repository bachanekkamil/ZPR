#include <logic/database.h>
#include <logic/database_exception.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>






DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection okk";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

void DbManager::addUser(const QString& name)
{
    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Users (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            return;
        }
        else
        {
            throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
}

User DbManager::getUser(unsigned int id)
{
    if (id > 0)
    {
        QSqlQuery queryGet;
        queryGet.prepare("Select name FROM Users WHERE id = :id");
        queryGet.bindValue(":id", QString::number(id));

        if(queryGet.exec())
        {
            if(queryGet.next())
            {
                QString name = queryGet.value(0).toString();
                User us(name, id);
                return us;
            }
            else
            {
                throw DatabaseException(error_type::ROW_NOT_FOUND);
            }
        }
        else
        {
            throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_WRONG_ID);
    }
}


bool DbManager::removeUser(const QString& name)
{
    bool success = false;

    if (isUserExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Users WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove user failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove user failed: person doesnt exist";
    }

    return success;
}

bool DbManager::removeUser(unsigned int id)
{
    bool success = false;

    if (isUserExists(id))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Users WHERE id = (:id)");
        queryDelete.bindValue(":id", id);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove user failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove user failed: person doesnt exist";
    }

    return success;
}

void DbManager::getAllUsers() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM Users");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool DbManager::isUserExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM Users WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "user exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::isUserExists(unsigned int id)
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM Users WHERE id = (:id)");
    checkQuery.bindValue(":id", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "user exists failed: " << checkQuery.lastError();
    }

    return exists;
}


bool DbManager::removeAllUsers()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM Users");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all users failed: " << removeQuery.lastError();
    }

    return success;
}
