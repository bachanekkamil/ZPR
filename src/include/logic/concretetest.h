#ifndef CONCRETETEST_H
#define CONCRETETEST_H

#include "user.h"
#include "test.h"
#include "answersdone.h"

class ConcreteTest
{

public:
    ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date);
    std::shared_ptr<User> getTestOwner() const;
    std::shared_ptr<Test> getTest() const;
    const QString* getTestName() const;
    unsigned int getIdDb() const;
    const QDateTime* getTimeCreated() const;



    //not used now
    User *m_User;
    Test *m_Test;
    AnswersDone *m_AnswersDone;

    ~ConcreteTest() {}
    const QString* getConcreteTestName();
    User* getConcreteTestOwner();
    Question* getNextQuestion();
    Test* getTest();
    void prepareListOfQuestions(unsigned int _number_of_questions);

private:
    const unsigned int mIdDb;
    std::shared_ptr<Test> mTest;
    std::shared_ptr<User> mUser;
    QString mName;
    QDateTime mDateTimeCreated;


    //not used now
    std::vector<AnswersDone*> answers_done;
    const QString name_from_user;
    const User* owner;
    std::vector<Question*> questions_for_now;
    const Test* test;

};


#endif // CONCRETETEST_H
