#ifndef TEST_H
#define TEST_H

#include "test.h"
#include "user.h"
#include "question.h"
#include <unordered_map>
class Test
{

public:
    Test(unsigned int id_test_db, QString name, std::shared_ptr<User> createdBy, std::vector<std::shared_ptr<Question>> questions);
    std::shared_ptr<User> getTestOwner() const;
    const QString* getTestName() const;
    unsigned int getIdDb() const;

    //not used now
    Test();


    Test(QString _name, User _user);
    ~Test();
    void addQuestion(Question* _question);
    std::vector<std::shared_ptr<Question> > getAllQuestions();
    Test* getParentTest();
    Question* getQuestion(unsigned int _id_db);
    void setTestName(QString _name);

private:
    std::shared_ptr<User> mCreatedBy;
    const unsigned int mIdTestDb;
    QString mName;
    std::vector<std::shared_ptr<Question>> mQuestions;

    //not used now
    std::shared_ptr<User> mParentTest;
    /**
     * container with questions
     */


};

#endif // TEST_H
