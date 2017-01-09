#include "logic/olduseranswer.h"

OldUserAnswer::OldUserAnswer(long long idDb, QDateTime dateTimeCreated, std::shared_ptr<Question> question, unsigned short grade):
    mIdDb(idDb), mDateTimeCreated(dateTimeCreated), mQuestion(question), mGrade(grade)
{

}

long long OldUserAnswer::getIdDb() const
{
    return mIdDb;
}

unsigned short OldUserAnswer::getGrade() const
{

    return mGrade;
}


const QDateTime* OldUserAnswer::getDateTimeCreated() const
{
    return &mDateTimeCreated;
}

const std::shared_ptr<Question> OldUserAnswer::getQuestion() const
{
    return  mQuestion;
}
