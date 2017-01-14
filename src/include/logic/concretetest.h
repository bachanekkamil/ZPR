#ifndef CONCRETETEST_H
#define CONCRETETEST_H

#include "user.h"
#include "test.h"
#include "logic/olduseranswer.h"

class ConcreteTest
{

public:
    ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date, std::vector<std::shared_ptr<OldUserAnswer>> oldUserAnswers);
    std::shared_ptr<User> getTestOwner() const;
    std::shared_ptr<Test> getTest() const;
    QString getTestName() const;
    unsigned int getIdDb() const;
    QDateTime getTimeCreated() const;
    std::vector<std::shared_ptr<OldUserAnswer>> getAllOldAnswers();
    std::vector<std::shared_ptr<Question>> getQuestionsForToday();

    //not used now
    User *m_User;
    Test *m_Test;
    std::shared_ptr<User> getConcreteTestOwner();


    ~ConcreteTest() {}
    const QString* getConcreteTestName();

    Question* getNextQuestion();
    void prepareListOfQuestions(unsigned int _number_of_questions);

private:
    void generateScheduler();

    const unsigned int mIdDb;
    std::shared_ptr<Test> mTest;
    std::shared_ptr<User> mUser;
    QString mName;
    QDateTime mDateTimeCreated;
    std::vector<std::shared_ptr<OldUserAnswer>> mOldAnswers;


    //not used now
    const QString name_from_user;
    const User* owner;
    std::vector<Question*> questions_for_now;
    const Test* test;

};


#endif // CONCRETETEST_H
