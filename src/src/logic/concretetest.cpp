#include "logic/concretetest.h"

ConcreteTest::ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date, std::vector<std::shared_ptr<OldUserAnswer> > oldUserAnswers):
mIdDb(id), mTest(test), mUser(user), mName(name), mDateTimeCreated(date), mOldAnswers(oldUserAnswers)
{
    mScheduler = new Scheduler();
    generateScheduler();
    mScheduler->printScheduler();
}

ConcreteTest::~ConcreteTest()
{
    delete mScheduler;
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

std::vector<std::shared_ptr<Question>> ConcreteTest::getQuestionsForToday()
{
    return mScheduler->getQuestionsForDay(QDate::currentDate());
}

void ConcreteTest::generateScheduler()
{
    foreach(std::shared_ptr<Question> quest, getTest()->getAllQuestions())
    {
        QuestionsToScheduler x = getLastAnswerFromHistory(quest);
        if(x.oua == nullptr)
        {
           mScheduler->insertQuestionForDay(quest, QDate::currentDate());
        }
        else
        {
            int interval = 0;
            double factor = 2.5;
            switch(x.n)
            {
                case 1:
                    interval = 1;
                    break;
                case 2:
                    interval = 6;
                    break;
                default:
                    factor = x.oua->getFactor() + (0.1 - (5-x.oua->getGrade())*(0.08+(5-x.oua->getGrade())*0.02));
                    interval = x.last_interval*factor;
            }
            mScheduler->insertQuestionForDay(quest, x.oua->getDateTimeCreated()->date().addDays(interval));
            quest->setFactor(factor);
        }
    }
    qDebug() << "Added question to scheduler";
}

QuestionsToScheduler ConcreteTest::getLastAnswerFromHistory(std::shared_ptr<Question> quest)
{
    QDate dt = QDate::currentDate().addYears(-50);
    QDate p_dt = QDate::currentDate().addYears(-50);
    std::shared_ptr<OldUserAnswer> answerToReturn = nullptr;
    int n=0;

    foreach(std::shared_ptr<OldUserAnswer> oldAnswer, mOldAnswers)
    {

        if(oldAnswer->getQuestion() == quest)
        {
            n++;
            qDebug() << "Old Date: " << oldAnswer->getDateTimeCreated()->date().toString("yyyy-MM-dd");
            if(oldAnswer->getDateTimeCreated()->date() > dt)
            {
                qDebug() << "Changing date";
                p_dt = dt;
                answerToReturn = oldAnswer;
                dt = oldAnswer->getDateTimeCreated()->date();
            }
            else if(oldAnswer->getDateTimeCreated()->date() > p_dt)
            {
                p_dt = oldAnswer->getDateTimeCreated()->date();
            }
        }
    }
    QuestionsToScheduler struct_to_return;
    qDebug() << "Date: " << dt.toString("yyyy-MM-dd") << " P Date: " << p_dt.toString("yyyy-MM-dd");
    struct_to_return.n = n;
    struct_to_return.oua = answerToReturn;
    if(n>1)
    struct_to_return.last_interval = p_dt.daysTo(dt);
    else
        struct_to_return.last_interval = 0;
    return struct_to_return;
}

void ConcreteTest::refreshAnswers()
{
    delete mScheduler;
    mScheduler = new Scheduler();
    generateScheduler();
}

void ConcreteTest::addNewAnswer(std::shared_ptr<OldUserAnswer> oua)
{
    mOldAnswers.push_back(oua);
}

QDate ConcreteTest::getDateForNextTest()
{
    return mScheduler->getNearestDay();
}
