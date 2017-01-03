#ifndef QUESTION_H
#define QUESTION_H

#include <logic/answer.h>
#include <vector>
#include <memory>

class Question
{

public:
    virtual ~Question() { }
    virtual std::vector<std::shared_ptr<Answer>> getAnswers() = 0;
    virtual const unsigned int getIdDb() = 0;
    virtual const QString* getText() = 0;
    virtual std::shared_ptr<Answer> getCorrectAnswer() = 0;

private:
};

#endif // QUESTION_H
