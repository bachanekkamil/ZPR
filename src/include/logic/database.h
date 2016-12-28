#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>


class DbManager
{
public:

    static DbManager& DbManager::getInstance(const QString& path)
    {
        static DbManager instance(path);
        return instance;
    }

    ~DbManager();

    bool isOpen() const;

    bool addUser(const QString& name);

    bool removeUser(const QString& name);

    bool removeUser(unsigned int id);

    bool isUserExists(const QString& name) const;

    bool isUserExists(unsigned int id);

    void getAllUsers() const;

    bool removeAllUsers();

private:
    QSqlDatabase m_db;

    DbManager(const QString& path);
};

#endif // DATABASE_H


