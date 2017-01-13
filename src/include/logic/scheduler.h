#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <QDateTime>
#include <logic/question.h>

class Scheduler
{

public:
    Scheduler(QDateTime day, std::vector<std::shared_ptr<Question>> questions);
    QDateTime getDay();
    std::vector<std::shared_ptr<Question>> getQuestions();



private:
    QDateTime mDay;
    std::vector<std::shared_ptr<Question>> mQuestions;
};

#endif SCHEDULER_H
