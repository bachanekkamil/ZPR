//!
/*!
  \brief Contains class QuestionProxy methods implementation used in proxy design patterns. Stores only DB ID for question.
  \author Kamil Bachanek
*/

#include "questionproxy.h"
#include "logic/database.h"
#include <QDebug>

QuestionProxy::QuestionProxy(unsigned int id_db) :mIdDb(id_db)
{

}

const unsigned int QuestionProxy::getIdDb()
{
    return  mIdDb;
}

const QString& QuestionProxy::getText()
{
    return getQuestion()->getText();
}

const QString& QuestionProxy::getCorrectAnswerText()
{
    return getQuestion()->getCorrectAnswerText();
}

void QuestionProxy::modifyQuestion(const QString& question, const QString& answer){
    getQuestion()->modifyQuestion(question,answer);
}

std::shared_ptr<Question> QuestionProxy::getQuestion()
{
    if(!mQuestionReal)
    mQuestionReal = DbManager::getInstance()->getRealQuestion(mIdDb);
    return mQuestionReal;
}

void QuestionProxy::setFactor(double factor)
{
    getQuestion()->setFactor(factor);
}

const double QuestionProxy::getFactor()
{
    return getQuestion()->getFactor();
}
