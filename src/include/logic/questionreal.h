#ifndef QUESTIONREAL_H
#define QUESTIONREAL_H

#include <vector>
#include <memory>
#include <logic/answer.h>
#include <logic/question.h>

class QuestionReal : public Question
{
public:
    QuestionReal(unsigned int id_db, std::vector<std::shared_ptr<Answer>> answers, std::shared_ptr<Answer> correct_answer, QString text);
    ~QuestionReal();
    std::vector<std::shared_ptr<Answer> > getAnswers();
    const unsigned int getIdDb();
    std::shared_ptr<Answer> getCorrectAnswer();
    const QString* getText();

private:
    std::vector<std::shared_ptr<Answer>> mAnswers;
    const std::shared_ptr<Answer> mCorrectAnswer;
    unsigned int mIdDb;
    QString mText;

};

#endif // QUESTIONREAL_H
