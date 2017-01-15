#include "logic/questionreal.h"
#include <QDebug>

QuestionReal::QuestionReal(unsigned int id_db, QString answerText, QString text) :
    mIdDb(id_db), mCorrectAnswerText(answerText), mText(text)
{
    //qDebug() << "Created new real question with text :" << mText;
}

QuestionReal::~QuestionReal()
{

}


const unsigned int QuestionReal::getIdDb(){
    return mIdDb;
}

const QString& QuestionReal::getText(){
    return mText;
}

const QString& QuestionReal::getCorrectAnswerText()
{
    return mCorrectAnswerText;
}

void QuestionReal::modifyQuestion(const QString& question, const QString& answer){
    mText=question;
    mCorrectAnswerText=answer;
}

void QuestionReal::setFactor(double factor)
{
    mFactor = factor;
}

const double QuestionReal::getFactor()
{
    return mFactor;
}
