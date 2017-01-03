#ifndef QUESTIONPROXY_H
#define QUESTIONPROXY_H

#include <QString>
#include "question.h"
#include "questionReal.h"


class QuestionProxy : public Question
{

public:
    ~QuestionProxy();

    QuestionProxy(unsigned int id_db);
    virtual std::vector<std::shared_ptr<Answer>> getAnswers();
    virtual const unsigned int getIdDb();
    virtual const QString* getText();
    virtual std::shared_ptr<Answer> getCorrectAnswer();

private:
    const unsigned int mIdDb;
    /**
     * pointer to QuestionReal
     */
    std::shared_ptr<Question> mQuestionReal;
    std::shared_ptr<Question> getQuestion();

};

#endif // QUESTIONPROXY_H
