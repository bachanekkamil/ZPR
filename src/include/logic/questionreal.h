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
    virtual void setFactor(double factor);
    virtual const double getFactor();

private:
    QString mCorrectAnswerText;
    unsigned int mIdDb;
    QString mText;
    double mFactor = 2.5;

};

#endif // QUESTIONREAL_H
