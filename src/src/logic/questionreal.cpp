#include "logic/questionreal.h"

QuestionReal::QuestionReal(unsigned int, unsigned short, std::vector<Answer>, QString)
{

}

QuestionReal::QuestionReal(unsigned int)
{

}

QuestionReal::~QuestionReal()
{

}

std::vector<Answer>* QuestionReal::getAnswers(){
    return NULL;
}

const unsigned int QuestionReal::getIdDb(){
    return NULL;
}

const QString* QuestionReal::getName(){
    return NULL;
}
