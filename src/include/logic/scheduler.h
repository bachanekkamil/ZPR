#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <QDate>
#include <logic/question.h>
#include <vector>
#include <QDebug>

//!  class Scheduler
/*!
  Stores date and date-related vector with questions
*/
struct Pair
{
    QDate date;
    std::vector<std::shared_ptr<Question>> mQuestions;
};

//!  class Scheduler
/*!
  Stores info about date when user should answer the question
*/
class Scheduler
{
public:
    //!  getQuestionsForDay method
    /*!
      \return vector with questions for that date
      \param date date
    */
    std::vector<std::shared_ptr<Question>> getQuestionsForDay(QDate date)
    {
        std::vector<std::shared_ptr<Question>> qqq;

        foreach(std::shared_ptr<Pair> day, mAll)
        {
            if(date >= day->date)
            {
                foreach(std::shared_ptr<Question> quest,day->mQuestions)
                    qqq.push_back(quest);
            }
        }

        return qqq;
    }

    //!  getQuestionsForDay method
    /*!
      \param quest pointer to Question
      \param date date when user should answer for that question
    */
    void insertQuestionForDay(std::shared_ptr<Question> quest, QDate date)
    {
        foreach(std::shared_ptr<Pair> day, mAll)
        {
            if(date == day->date)
            {
                day->mQuestions.push_back(quest);
                return;
            }
        }
        std::shared_ptr<Pair> x(new Pair());
        x->date=date;
        x->mQuestions.push_back(quest);
        mAll.push_back(x);
    }

    void printScheduler()
    {
        qDebug() << getNearestDay().toString("yyyy-MM-dd");
        foreach(std::shared_ptr<Pair> day, mAll)
        {
            qDebug() << "Day: " << day->date.toString("yyyy-MM-dd");
            foreach(std::shared_ptr<Question> q, day->mQuestions)
            {
                qDebug() << "Id: " << q->getIdDb() << " Question: " << q->getText() << " Answer: " << q->getCorrectAnswerText() << " Factor: " << q->getFactor();
            }
        }
    }

    //!  getNearestDay method
    /*!
      \return nearest date when user should start a test
    */
    QDate getNearestDay()
    {
        QDate min = QDate::currentDate().addYears(50);
        foreach(std::shared_ptr<Pair> day, mAll)
        {
            qDebug() << "Day: " << day->date.toString("yyyy-MM-dd");
            if(day->date < min)
                min = day->date;
        }
        return min;
    }



private:
    QDate mDay;
    std::vector<std::shared_ptr<Pair>> mAll;
};

#endif //SCHEDULER_H
