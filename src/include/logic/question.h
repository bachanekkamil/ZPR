//!
/*!
  \brief Contains Pure abstract class Question. Interface for questions. Used in proxy design patterns
  \author Kamil Bachanek
*/

#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
#include <memory>
#include <QString>

//!  class Question
/*!
  Pure abstract class. Interface for questions. Used in proxy design patterns
*/
class Question
{

public:
    //!  Question destructor
    /*!
      virtual
    */
    virtual ~Question() { }

    //!  setFactor method
    /*!
      \param factor (used in SuperMemo algorithm) used in current ConcreteTest with this question
    */
    virtual void setFactor(double factor) = 0;

    //!  setFactor method
    /*!
      \return factor (used in SuperMemo algorithm) used in current ConcreteTest with this question
    */
    virtual const double getFactor() = 0;

    //!  setFactor method
    /*!
      \return id question from DB
    */
    virtual const unsigned int getIdDb() = 0;

    //!  setFactor method
    /*!
      \return question text
    */
    virtual const QString& getText() = 0;

    //!  setFactor method
    /*!
      \return answer text
    */
    virtual const QString& getCorrectAnswerText() = 0;

    //!  setFactor method
    /*!
      \param new question text
      \param new answer text
    */
    virtual void modifyQuestion(const QString& question, const QString& answer) = 0;
};

#endif // QUESTION_H
