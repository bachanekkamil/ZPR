#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include "user.h"
#include <memory>


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

    unsigned int addUser(const QString& name);

    std::shared_ptr<User> getUser(unsigned int id);

    void removeUser(const QString& name);

    void removeUser(unsigned int id);

    bool isUserExists(const QString& name) const;

    bool isUserExists(unsigned int id);

    std::vector<std::shared_ptr<User> > getAllUsers() const;

    void removeAllUsers();

private:
    QSqlDatabase m_db;

    DbManager(const QString& path);

    unsigned int getLastInsertedRowId();
};

#endif // DATABASE_H


