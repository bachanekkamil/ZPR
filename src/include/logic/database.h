#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include "user.h"
#include "test.h"
#include "questionreal.h"
#include <memory>
#include <vector>


class DbManager
{
public:

    static int ilosc;
    static int zwrocIlosc(){
        return ilosc;
    }

    static DbManager& getInstance()
    {
        static DbManager instance("db_test.db");
        return instance;
    }

    ~DbManager();

    bool isOpen() const;

    //users
    unsigned int addUser(const QString& name);
    std::shared_ptr<User> getUser(unsigned int id);
    void removeUser(const QString& name);
    void removeUser(unsigned int id);
    bool isUserExists(const QString& name) const;
    bool isUserExists(unsigned int id);
    std::vector<std::shared_ptr<User> > getAllUsers();
    void removeAllUsers();

    //tests
    unsigned int addTest(const QString& name, const std::shared_ptr<User> user);
    std::vector<std::shared_ptr<Test>> getAllTests();

    //questions
    std::shared_ptr<Question> getRealQuestion(unsigned long long id);
    std::vector<std::shared_ptr<Question>> getAllQuestionForTest(unsigned int id);


    unsigned int addQuestionAndAnswer(std::shared_ptr<Test> test, QString& question_text, QString& answer_text);


private:
    QSqlDatabase m_db;

    DbManager(const QString& path);

    unsigned int getLastInsertedRowId();

    std::vector<std::shared_ptr<User>> all_users;
};



#endif // DATABASE_H


