#ifndef QUESTIONREAL_H
#define QUESTIONREAL_H

#include <vector>
#include <memory>
#include <logic/question.h>

class QuestionReal : public Question
{
public:
    QuestionReal(unsigned int id_db, QString answerText, QString text);
    ~QuestionReal();
    const unsigned int getIdDb();
    virtual const QString& getCorrectAnswerText();
    virtual const QString& getText();
    virtual void modifyQuestion(const QString& question, const QString& answer);

private:
    QString mCorrectAnswerText;
    unsigned int mIdDb;
    QString mText;

};

#endif // QUESTIONREAL_H
