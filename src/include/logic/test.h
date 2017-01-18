//!
/*!
  \brief Contains class Test - Stores info about test
  \author Kamil Bachanek
*/

#ifndef TEST_H
#define TEST_H

#include "test.h"
#include "user.h"
#include "question.h"

//!  class Test
/*!
  Stores info about test
*/
class Test
{

public:
    //!  Test constructor
    /*!
      \param id_test_db id test from DB
      \param name test name
      \param createdBy pointer to user (owner)
      \param questions vector with pointers to Question
    */
    Test(unsigned int id_test_db, QString name, std::shared_ptr<User> createdBy, std::vector<std::shared_ptr<Question>> questions);

    //!  getTestOwner method
    /*!
      \return pointer to User (test owner)
    */
    std::shared_ptr<User> getTestOwner() const;

    //!  getTestName method
    /*!
      \return test name
    */
    const QString& getTestName() const;

    //!  getIdDb method
    /*!
      \return id from DB
    */
    unsigned int getIdDb() const;

    //!  getNumberOfQuestions method
    /*!
      \return number of questions
    */
    int getNumberOfQuestions();

    //!  addQuestion method
    /*!
      \param question pointer to Question
    */
    void addQuestion(std::shared_ptr<Question> question);

    //!  modifyQuestion method
    /*!
      \param index question index to modify
      \param question question text
      \param answer answer text
    */
    void modifyQuestion(unsigned int index, const QString& question, const QString& answer);

    //!  getQuestion method
    /*!
      \return pointer to question
      \param idDb id from DB
    */
    std::shared_ptr<Question> getQuestion(unsigned int idDb);

    //!  getAllQuestions method
    /*!
      \return vector with pointers to question
    */
    std::vector<std::shared_ptr<Question> > getAllQuestions();

private:
    std::shared_ptr<User> mCreatedBy;
    const unsigned int mIdTestDb;
    QString mName;
    std::vector<std::shared_ptr<Question>> mQuestions;
};

#endif // TEST_H
