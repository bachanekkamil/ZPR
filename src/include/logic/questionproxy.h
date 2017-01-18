//!
/*!
  \brief Contains class QuestionProxy used in proxy design patterns. Stores only DB ID for question.
  \author Kamil Bachanek
*/

#ifndef QUESTIONPROXY_H
#define QUESTIONPROXY_H

#include <QString>
#include "question.h"
#include "questionreal.h"

//!  class QuestionProxy
/*!
  Used in proxy design patterns. Stores only DB ID for question.
*/
class QuestionProxy : public Question
{
public:

    //!  QuestionProxy constructor
    /*!
      \param id_db question id from db
    */
    QuestionProxy(unsigned int id_db);

    //!  getIdDb method
    /*!
      \return question id from db
    */
    virtual const unsigned int getIdDb();

    //!  getText method
    /*!
      \return question text
    */
    virtual const QString& getText();

    //!  getCorrectAnswerText method
    /*!
      \return answer text
    */
    virtual const QString& getCorrectAnswerText();

    //!  modifyQuestion method
    /*!
      \param question text
      \param answer text
    */
    virtual void modifyQuestion(const QString& question, const QString& answer);

    //!  setFactor method
    /*!
      \param factor (used in SuperMemo algorithm) used in current ConcreteTest with this question
    */
    virtual void setFactor(double factor);

    //!  getFactor method
    /*!
      \return factor (used in SuperMemo algorithm) used in current ConcreteTest with this question
    */
    virtual const double getFactor();


private:
    const unsigned int mIdDb;
    std::shared_ptr<Question> mQuestionReal;
    std::shared_ptr<Question> getQuestion();

};

#endif // QUESTIONPROXY_H
