//!
/*!
  \brief Contains OldUserAnswer Class methods implementation used to stores data about historical answers.
  \author Kamil Bachanek
*/

#include "logic/olduseranswer.h"

OldUserAnswer::OldUserAnswer(long long idDb, QDateTime dateTimeCreated, std::shared_ptr<Question> question, unsigned short grade, double factor):
    mIdDb(idDb), mDateTimeCreated(dateTimeCreated), mQuestion(question), mGrade(grade), mFactor(factor)
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

double OldUserAnswer::getFactor() const
{
    return mFactor;
}
