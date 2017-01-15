#include "logic/concretetest.h"

ConcreteTest::ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date, std::vector<std::shared_ptr<OldUserAnswer> > oldUserAnswers):
mIdDb(id), mTest(test), mUser(user), mName(name), mDateTimeCreated(date), mOldAnswers(oldUserAnswers)
{
    mQuestionsForNow=mTest->getAllQuestions();
}

std::shared_ptr<User> ConcreteTest::getTestOwner() const
{
    return  mUser;
}

std::shared_ptr<Test> ConcreteTest::getTest() const{
    return  mTest;
}

QString ConcreteTest::getTestName() const{

    return mName;
}

unsigned int ConcreteTest::getIdDb() const
{
    return mIdDb;
}

QDateTime ConcreteTest::getTimeCreated() const{
    return mDateTimeCreated;
}

std::vector<std::shared_ptr<OldUserAnswer>> ConcreteTest::getAllOldAnswers()
{
    return mOldAnswers;
}

std::vector<std::shared_ptr<Question>> ConcreteTest::getQuestionsForToday(){
    return mQuestionsForNow;
}

void ConcreteTest::generateScheduler()
{

}
