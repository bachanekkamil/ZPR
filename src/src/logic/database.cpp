#include <logic/database.h>
#include <logic/database_exception.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QDateTime>


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

unsigned int DbManager::addUser(const QString& name)
{
    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Users (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            return getLastInsertedRowId();
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

std::shared_ptr<User> DbManager::getUser(unsigned int id)
{
    if (id > 0)
    {
        QSqlQuery queryGet;
        queryGet.prepare("Select name, datetime_created FROM Users WHERE id = :id");
        queryGet.bindValue(":id", QString::number(id));

        if(queryGet.exec())
        {
            if(queryGet.next())
            {
                QString name = queryGet.value(0).toString();
                QString date = queryGet.value(1).toString();
                QString format = "yyyy-MM-dd HH:mm:ss";
                QDateTime dt = QDateTime::fromString(date, format);
                std::shared_ptr<User> us(new User (name, id, dt));
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


void DbManager::removeUser(const QString& name)
{
    if (isUserExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Users WHERE name = (:name)");
        queryDelete.bindValue(":name", name);

        if(!queryDelete.exec())
        {
            throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::ROW_NOT_FOUND);
    }

}

void DbManager::removeUser(unsigned int id)
{
    if (isUserExists(id))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Users WHERE id = (:id)");
        queryDelete.bindValue(":id", id);

        if(!queryDelete.exec())
        {
            throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::ROW_NOT_FOUND);
    }
}

std::vector<std::shared_ptr<User>> DbManager::getAllUsers() const
{
    qDebug() << "Persons in db:";
    QSqlQuery queryGet;
    queryGet.prepare("Select name, datetime_created, id FROM Users");
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    std::vector<std::shared_ptr<User>> vec;
    while (queryGet.next())
    {
        QString name = queryGet.value(0).toString();
        QString date = queryGet.value(1).toString();
        unsigned int id = queryGet.value(2).toUInt();
        QString format = "yyyy-MM-dd HH:mm:ss";
        QDateTime dt = QDateTime::fromString(date, format);
        std::shared_ptr<User> us(new User (name, id, dt));
        vec.push_back(us);
    }
    return vec;
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
        throw DatabaseException(checkQuery.lastError().text().toStdString().c_str());
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
        throw DatabaseException(checkQuery.lastError().text().toStdString().c_str());
    }

    return exists;
}


void DbManager::removeAllUsers()
{
    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM Users");

    if (!removeQuery.exec())
    {
        throw DatabaseException(removeQuery.lastError().text().toStdString().c_str());
    }
}

unsigned int DbManager::getLastInsertedRowId()
{
    QSqlQuery queryGet;
    queryGet.prepare("SELECT last_insert_rowid()");

    if(queryGet.exec())
    {
        if(queryGet.next())
        {
            unsigned int id = queryGet.value(0).toUInt();
            return id;
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

