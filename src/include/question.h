#ifndef QUESTION_H
#define QUESTION_H

#include <answer.h>

class Question
{

public:
    Question();

    virtual ~Question();
//    virtual std::vector<Answer*> getAnswers();
    virtual const unsigned int getIdDb();
    virtual const QString* getName();

};

#endif // QUESTION_H
