#include "questionproxy.h"
#include "logic/database.h"



QuestionProxy::QuestionProxy(unsigned int id_db) :mIdDb(id_db)
{

}

QuestionProxy::~QuestionProxy()
{

}


const unsigned int QuestionProxy::getIdDb()
{
    return  mIdDb;
}


std::vector<std::shared_ptr<Answer>> QuestionProxy::getAnswers()
{
    return getQuestion()->getAnswers();
}


const QString* QuestionProxy::getText()
{
    return getQuestion()->getText();
}

std::shared_ptr<Answer> QuestionProxy::getCorrectAnswer()
{
    return getQuestion()->getCorrectAnswer();
}


/**
 * returns real Question
 */
std::shared_ptr<Question> QuestionProxy::getQuestion()
{
    if(mQuestionReal == nullptr)
    mQuestionReal = DbManager::getInstance().getRealQuestion(mIdDb);
    return mQuestionReal;
}
