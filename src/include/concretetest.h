#ifndef CONCRETETEST_H
#define CONCRETETEST_H

#include "user.h"
#include "test.h"
#include "answersdone.h"

class ConcreteTest
{

public:
    ConcreteTest();
    User *m_User;
    Test *m_Test;
    AnswersDone *m_AnswersDone;

    ConcreteTest(unsigned int _id_concrete_test_db);
    ConcreteTest(Test* _test, User* _user, QString _name_from_user);
    ~ConcreteTest();
    const QString* getConcreteTestName();
    User* getConcreteTestOwner();
    Question* getNextQuestion();
    Test* getTest();
    void prepareListOfQuestions(unsigned int _number_of_questions);

private:
    std::vector<AnswersDone*> answers_done;
    const unsigned int id_concrete_test_db;
    const QString name_from_user;
    const User* owner;
    std::vector<Question*> questions_for_now;
    const Test* test;

};


#endif // CONCRETETEST_H
