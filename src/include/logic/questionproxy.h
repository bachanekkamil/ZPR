#ifndef QUESTIONPROXY_H
#define QUESTIONPROXY_H

#include <QString>
#include "question.h"
#include "questionreal.h"


class QuestionProxy : public Question
{

public:
    ~QuestionProxy();

    QuestionProxy(unsigned int id_db);
    virtual const unsigned int getIdDb();
    virtual const QString& getText();
    virtual const QString& getCorrectAnswerText();
    virtual void modifyQuestion(const QString& question, const QString& answer);


private:
    const unsigned int mIdDb;
    /**
     * pointer to QuestionReal
     */
    std::shared_ptr<Question> mQuestionReal;
    std::shared_ptr<Question> getQuestion();

};

#endif // QUESTIONPROXY_H
