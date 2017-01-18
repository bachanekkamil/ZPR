//!
/*!
  \brief Contains class QuestionReal used in proxy design patterns. Stores all info about question.
  \author Kamil Bachanek
*/

#ifndef QUESTIONREAL_H
#define QUESTIONREAL_H

#include <vector>
#include <memory>
#include <logic/question.h>

//!  class QuestionReal
/*!
  Used in proxy design patterns. Stores all info about question.
*/
class QuestionReal : public Question
{
public:
    //!  QuestionProxy constructor
    /*!
      \param id_db question id from db
      \param answerText answer text
      \param text question question
    */
    QuestionReal(unsigned int id_db, QString answerText, QString text);


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
    QString mCorrectAnswerText;
    unsigned int mIdDb;
    QString mText;
    double mFactor = 2.5;

};

#endif // QUESTIONREAL_H
