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
    const QString& getTestName() const;
    unsigned int getIdDb() const;
    int getNumberOfQuestions();
    void addQuestion(std::shared_ptr<Question> question);
    void modifyQuestion(unsigned int index, const QString& question, const QString& answer);
    std::shared_ptr<Question> getQuestion(unsigned int idDb);
    std::vector<std::shared_ptr<Question> > getAllQuestions();

private:
    std::shared_ptr<User> mCreatedBy;
    const unsigned int mIdTestDb;
    QString mName;
    std::vector<std::shared_ptr<Question>> mQuestions;
};

#endif // TEST_H
