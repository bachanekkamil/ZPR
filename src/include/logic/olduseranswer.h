#ifndef OLDUSERANSWER_H
#define OLDUSERANSWER_H
#include <vector>
#include <QDateTime>
#include <logic/question.h>

struct OldUserAnswer
{

public:
    OldUserAnswer(long long idDb, QDateTime dateTimeCreated, std::shared_ptr<Question> question, unsigned short grade);
    long long getIdDb() const;
    const std::shared_ptr<Question> getQuestion() const;
    const QDateTime* getDateTimeCreated() const;
    unsigned short getGrade() const;

private:
    long long mIdDb;
    QDateTime mDateTimeCreated;
    std::shared_ptr<Question> mQuestion;
    unsigned short mGrade;

};

#endif // OLDUSERANSWER_H
