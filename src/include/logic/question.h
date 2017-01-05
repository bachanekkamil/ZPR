#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <memory>
#include <QString>

class Question
{

public:
    virtual ~Question() { }
    virtual const unsigned int getIdDb() = 0;
    virtual const QString* getText() = 0;
    virtual const QString* getCorrectAnswerText() = 0;

private:
};

#endif // QUESTION_H
