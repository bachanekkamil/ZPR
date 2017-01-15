#ifndef CONCRETETEST_H
#define CONCRETETEST_H

#include "user.h"
#include "test.h"
#include "logic/olduseranswer.h"
#include "logic/scheduler.h"

struct QuestionsToScheduler
{
    std::shared_ptr<OldUserAnswer> oua;
    int n = -1;
    int last_interval;
};

class ConcreteTest
{

public:
    ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date, std::vector<std::shared_ptr<OldUserAnswer>> oldUserAnswers);
    ~ConcreteTest();
    std::shared_ptr<User> getTestOwner() const;
    std::shared_ptr<Test> getTest() const;
    QString getTestName() const;
    unsigned int getIdDb() const;
    QDateTime getTimeCreated() const;
    std::vector<std::shared_ptr<OldUserAnswer>> getAllOldAnswers();
    std::vector<std::shared_ptr<Question>> getQuestionsForToday();
    void refreshAnswers();
    void addNewAnswer(std::shared_ptr<OldUserAnswer> oua);
    QDate getDateForNextTest();

private:
    void generateScheduler();
    QuestionsToScheduler getLastAnswerFromHistory(std::shared_ptr<Question> quest);
    const unsigned int mIdDb;
    std::shared_ptr<Test> mTest;
    std::shared_ptr<User> mUser;
    QString mName;
    QDateTime mDateTimeCreated;
    std::vector<std::shared_ptr<OldUserAnswer>> mOldAnswers;
    Scheduler* mScheduler = nullptr;
};


#endif // CONCRETETEST_H
