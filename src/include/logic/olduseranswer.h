//!
/*!
  \brief Contains OldUserAnswer Class used to stores data about historical answers.
  \author Kamil Bachanek
*/

#ifndef OLDUSERANSWER_H
#define OLDUSERANSWER_H
#include <vector>
#include <QDateTime>
#include <logic/question.h>

//!  class OldUserAnswer
/*!
  Stores data about historical answers.
*/
class OldUserAnswer
{

public:
    //!  QuestionProxy constructor
    /*!
      \param idDb id (Logs table) from DB
      \param dateTimeCreated datetime when user answered
      \param question pointer to Question
      \param grade grade for this answer
      \param factor last factor for this question (related to SuperMemo algorithm)
    */
    OldUserAnswer(long long idDb, QDateTime dateTimeCreated, std::shared_ptr<Question> question, unsigned short grade, double factor);

    //!  getIdDb method
    /*!
      \return idDb id (Logs table) from DB
    */
    long long getIdDb() const;

    //!  getQuestion method
    /*!
      \return pointer to Question
    */
    const std::shared_ptr<Question> getQuestion() const;

    //!  getQuestion method
    /*!
      \return datetime when user answered
    */
    const QDateTime* getDateTimeCreated() const;

    //!  getQuestion method
    /*!
      \return grade for this answer
    */
    unsigned short getGrade() const;

    //!  getQuestion method
    /*!
      \return last factor for this question (related to SuperMemo algorithm)
    */
    double getFactor() const;

private:
    long long mIdDb;
    QDateTime mDateTimeCreated;
    std::shared_ptr<Question> mQuestion;
    unsigned short mGrade;
    double mFactor;

};

#endif // OLDUSERANSWER_H
