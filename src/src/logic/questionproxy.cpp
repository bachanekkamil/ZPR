#include "questionproxy.h"
#include "logic/database.h"
#include <QDebug>



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



const QString* QuestionProxy::getText()
{
    return getQuestion()->getText();
}

const QString* QuestionProxy::getCorrectAnswerText()
{
    return getQuestion()->getCorrectAnswerText();
}


/**
 * returns real Question
 */
std::shared_ptr<Question> QuestionProxy::getQuestion()
{
    qDebug() << "QuestionProxy::getQuestion()";
    if(!mQuestionReal)
    mQuestionReal = DbManager::getInstance().getRealQuestion(mIdDb);
    return mQuestionReal;
}
