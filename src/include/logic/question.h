#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <memory>
#include <QString>

class Question
{

public:
    virtual ~Question() { }
    virtual void setFactor(double factor) = 0;
    virtual const double getFactor() = 0;
    virtual const unsigned int getIdDb() = 0;
    virtual const QString& getText() = 0;
    virtual const QString& getCorrectAnswerText() = 0;
    virtual void modifyQuestion(const QString& question, const QString& answer) = 0;

private:
};

#endif // QUESTION_H
