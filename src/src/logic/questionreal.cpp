#include "logic/questionreal.h"

QuestionReal::QuestionReal(unsigned int id_db, std::vector<std::shared_ptr<Answer>> answers, std::shared_ptr<Answer> correct_answer, QString text) :
    mIdDb(id_db), mAnswers(answers), mCorrectAnswer(correct_answer), mText(text)
{

}

QuestionReal::~QuestionReal()
{

}

std::vector<std::shared_ptr<Answer>> QuestionReal::getAnswers(){
    return mAnswers;
}

const unsigned int QuestionReal::getIdDb(){
    return mIdDb;
}

const QString* QuestionReal::getText(){
    return &mText;
}

std::shared_ptr<Answer> QuestionReal::getCorrectAnswer()
{
    return mCorrectAnswer;
}
