#include "logic/concretetest.h"

ConcreteTest::ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date, std::vector<std::shared_ptr<OldUserAnswer> > oldUserAnswers):
mIdDb(id), mTest(test), mUser(user), mName(name), mDateTimeCreated(date), mOldAnswers(oldUserAnswers)
{

}


unsigned int ConcreteTest::getIdDb() const
{
    return mIdDb;
}

std::shared_ptr<Test> ConcreteTest::getTest() const{
    return  mTest;
}

std::shared_ptr<User> ConcreteTest::getTestOwner() const
{
    return  mUser;
}

const QString* ConcreteTest::getTestName() const{

    return &mName;
}

const QDateTime* ConcreteTest::getTimeCreated() const{
    return &mDateTimeCreated;
}

std::vector<std::shared_ptr<OldUserAnswer>> ConcreteTest::getAllOldAnswers()
{
    return mOldAnswers;
}

void ConcreteTest::generateScheduler()
{

}
