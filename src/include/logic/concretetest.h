#ifndef CONCRETETEST_H
#define CONCRETETEST_H

#include "user.h"
#include "test.h"
#include "logic/olduseranswer.h"
#include "logic/scheduler.h"

//!  struct QuestionsToScheduler
/*!
  Struct used by SuperMemo alghoritm.
*/
struct QuestionsToScheduler
{
    std::shared_ptr<OldUserAnswer> oua; /*!< Pointer to OldUserAnswer*/
    int n = -1; /*!< Number of repetition of this question*/
    int last_interval; /*!< Interval between last and next to last user answer for this question*/
};

//!  Concrete test class
/*!
  Class related to concrete instance of test (linked to user and done answers).
*/
class ConcreteTest
{

public:
    //! A ConcreteTest constructor.
        /*!
      \param id ID from DB
      \param test pointer to Test class
      \param user pointer to user (owner of ConcreteTest)
      \param name name of test
      \param date datetime when test was created
      \param oldUserAnswers vector with pointers to old user answer for this test
        */
    ConcreteTest(unsigned int id, std::shared_ptr<Test> test, std::shared_ptr<User> user, QString name, QDateTime date, std::vector<std::shared_ptr<OldUserAnswer>> oldUserAnswers);
    //! A ConcreteTest destructor.
        /*!
      Deletes mScheduler
        */
    ~ConcreteTest();
    //! getTestOwner memhod
        /*!
      \return pointer to owner of this test
        */
    std::shared_ptr<User> getTestOwner() const;
    //! getTest method
        /*!
      \return pointer to Test
        */
    std::shared_ptr<Test> getTest() const;
    //! getTestName method
        /*!
      \return test name
        */
    QString getTestName() const;
    //! getIdDb method
        /*!
      \return ID concrete test from DB
        */
    unsigned int getIdDb() const;
    //! getTimeCreated method
        /*!
      \return datetime when test was created
        */
    QDateTime getTimeCreated() const;

    //! getAllOldAnswers method
        /*!
      \return vector with all OldUserAnswer for this test
        */
    std::vector<std::shared_ptr<OldUserAnswer>> getAllOldAnswers();
    //! getQuestionsForToday method
        /*!
      \return vector with questions which should be solved today
        */
    std::vector<std::shared_ptr<Question>> getQuestionsForToday();
    //!  refreshAnswers method
    /*!
      Creates new scheduler
    */
    void refreshAnswers();
    //!  addNewAnswer method
    /*!
      Add new answer to be stored in vector
    */
    void addNewAnswer(std::shared_ptr<OldUserAnswer> oua);
    //! getDateForNextTest
        /*!
      \return Get the nearest date for next test
        */
    QDate getDateForNextTest();

private:
    void generateScheduler();
    QuestionsToScheduler getLastAnswerFromHistory(std::shared_ptr<Question> quest);
    const unsigned int mIdDb;
    std::shared_ptr<Test> mTest;
    std::shared_ptr<User> mUser;
    QString mName;
    QDateTime mDateTimeCreated;
    std::vector<std::shared_ptr<OldUserAnswer>> mOldAnswers;
    Scheduler* mScheduler = nullptr;
};


#endif // CONCRETETEST_H
