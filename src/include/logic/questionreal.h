#ifndef QUESTIONREAL_H
#define QUESTIONREAL_H

#include <vector>
#include <logic/answer.h>
#include <logic/question.h>

class QuestionReal : public Question
{
public:
    QuestionReal(unsigned int);
    QuestionReal(unsigned int, unsigned short, std::vector<Answer>, QString);
    ~QuestionReal();
    std::vector<Answer>* getAnswers();
    const unsigned int getIdDb();
    const QString* getName();

private:
    std::vector<Answer*> answers;
    const Answer* correct_answer;
    unsigned int id_db;
    QString text;

};

#endif // QUESTIONREAL_H
