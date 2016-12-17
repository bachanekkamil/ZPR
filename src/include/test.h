#ifndef TEST_H
#define TEST_H

#include "user.h"
#include "question.h"
#include <unordered_map>
class Test
{

public:
    Test();
    User *m_User;
    Question *m_Question;

    Test(unsigned int _id_test_db);
    Test(QString _name, User _user);
    ~Test();
    void addQuestion(Question* _question);
    std::unordered_map<int, Question*> getAllQuestions();
    Test* getParentTest();
    Question* getQuestion(unsigned int _id_db);
    const QString* getTestName();
    User* getTestOwner();
    void setTestName(QString _name);

private:
    const User* created_by;
    const unsigned int id_test_db;
    const QString name;
    Test* parent_test;
    /**
     * container with questions
     */
    std::unordered_map<int, Question*> questions;

};

#endif // TEST_H
