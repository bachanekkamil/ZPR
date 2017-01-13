#include <logic/scheduler.h>

QDateTime Scheduler::getDay()
{
    return mDay;
}

std::vector<std::shared_ptr<Question>> Scheduler::getQuestions()
{
    return mQuestions;
}
