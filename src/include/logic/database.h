#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include "user.h"
#include "test.h"
#include "questionreal.h"
#include <memory>
#include <vector>
#include <logic/concretetest.h>



class DbManager
{
public:

    static DbManager* getInstance()
    {
        if(mInstance == nullptr)
            mInstance = new DbManager("db_test.db");
        return mInstance;
    }

    ~DbManager();

    bool isOpen() const;

    //users
    std::shared_ptr<User> addUser(const QString& name);
    std::shared_ptr<User> getUser(unsigned int id);
    void removeUser(const QString& name);
    void removeUser(unsigned int id);
    bool isUserExists(const QString& name) const;
    bool isUserExists(unsigned int id);
    std::vector<std::shared_ptr<User> > getAllUsers();
    void removeAllUsers();

    //tests
    std::shared_ptr<Test> addTest(const QString& name, const std::shared_ptr<User> user);
    std::vector<std::shared_ptr<Test>> getAllTests();
    void deleteTest(std::shared_ptr<Test> test);
    void modifyTest(std::shared_ptr<Test> test, const QString& name);

    //questions
    std::shared_ptr<Question> getRealQuestion(unsigned long long id);
    std::vector<std::shared_ptr<Question>> getAllQuestionForTest(unsigned int id);
    unsigned int addQuestionAndAnswer(std::shared_ptr<Test> test, QString& question_text, QString& answer_text);
    void modifyQuestion(std::shared_ptr<Question> question, QString& question_text, QString& answer_text);
    void deleteQuestion(std::shared_ptr<Question> question);
    void deleteAllQuestionsForTest(std::shared_ptr<Test> test);


    //concretetests
    std::shared_ptr<ConcreteTest> addConcreteTest(const QString& name, const std::shared_ptr<User> user, const std::shared_ptr<Test> test);
    std::vector<std::shared_ptr<ConcreteTest>> getAllConcreteTests();
    void deleteConcreteTest(std::shared_ptr<ConcreteTest> test);
    void modifyConcreteTest(std::shared_ptr<ConcreteTest> test, const QString& name);

    //logs
    std::shared_ptr<OldUserAnswer> addAnswerToLogs(std::shared_ptr<ConcreteTest> conc_test, std::shared_ptr<Question> quest, unsigned short grade, double factor);
    std::vector<std::shared_ptr<OldUserAnswer>> getLogsForConcreteTests(std::shared_ptr<ConcreteTest> conc_test);
    std::vector<std::shared_ptr<OldUserAnswer>> getLogsForConcreteTests(unsigned int concreteTestId);



private:
    QSqlDatabase m_db;
    static DbManager* mInstance;
    DbManager(const QString& path);
    unsigned int getLastInsertedRowId();
};



#endif // DATABASE_H


