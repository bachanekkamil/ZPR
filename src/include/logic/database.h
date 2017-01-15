#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include "user.h"
#include "test.h"
#include "questionreal.h"
#include <memory>
#include <vector>
#include <logic/concretetest.h>


//!  DbManager Class
/*!
  Class used to create connection with DATABASE and creates query to retrieve data and modify data.
*/
class DbManager
{
public:
    //!  getInstance method
    /*!
      Impelements signleton design pattern
    */
    static DbManager* getInstance()
    {
        if(mInstance == nullptr)
            mInstance = new DbManager("db_test.db");
        return mInstance;
    }
    //!  Destructor
    /*!
      Closes connection with DB
    */
    ~DbManager() ;

    //! isOpen method
        /*!
      \return true if database is open
        */
    bool isOpen() const;

    //! addUser method
        /*!
      \return pointer to User
      \param name user name
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::shared_ptr<User> addUser(const QString& name);

    //! getUser method
        /*!
      \return pointer to User
      \param id ID from DB
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::shared_ptr<User> getUser(unsigned int id);
    //! removeUser method
        /*!
      \param user name
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void removeUser(const QString& name);

    //! removeUser method
        /*!
      \param id id from DB
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void removeUser(unsigned int id);

    //! isUserExists method
        /*!
      \return true if user exists
      \param name user name
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    bool isUserExists(const QString& name) const;

    //! isUserExists method
        /*!
      \return true if user exists
      \param id user ID from DB
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    bool isUserExists(unsigned int id);

    //! getAllUsers method
        /*!
      \return vector with all users
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::vector<std::shared_ptr<User> > getAllUsers();

    //! removeAllUsers method
        /*!
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void removeAllUsers();

    //! addTest method
        /*!
      Used to add new test
      \return pointer to Test
      \param name test name
      \param user pointer to User (owner of Test)
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::shared_ptr<Test> addTest(const QString& name, const std::shared_ptr<User> user);

    //! getAllTests method
        /*!
      \return vector with pointers to Test
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::vector<std::shared_ptr<Test>> getAllTests();

    //! deleteTest method
        /*!
      \param test pointer to Test
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void deleteTest(std::shared_ptr<Test> test);

    //! modifyTest method
        /*!
      \param test pointer to Test
      \param name new test name
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void modifyTest(std::shared_ptr<Test> test, const QString& name);

    //! getRealQuestion method
        /*!
      \return pointer to QuestionReal
      \param id id question from DB
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::shared_ptr<Question> getRealQuestion(unsigned long long id);

    //! getAllQuestionForTest method
        /*!
      \return pointer to QuestionProxy
      \param id id test from DB
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::vector<std::shared_ptr<Question>> getAllQuestionForTest(unsigned int id);

    //! addQuestionAndAnswer method
        /*!
      \return id qustion from DB
      \param test pionter to Test
      \param question_text quesstion text
      \param answer_text answer text
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    unsigned int addQuestionAndAnswer(std::shared_ptr<Test> test, QString& question_text, QString& answer_text);

    //! modifyQuestion method
        /*!
      \param question pointer to Question
      \param question_text quesstion text
      \param answer_text answer text
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void modifyQuestion(std::shared_ptr<Question> question, QString& question_text, QString& answer_text);

    //! deleteQuestion method
        /*!
      \param question pointer to Question
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void deleteQuestion(std::shared_ptr<Question> question);

    //! deleteAllQuestionsForTest method
        /*!
      \param test pointer to Test
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void deleteAllQuestionsForTest(std::shared_ptr<Test> test);

    //! addConcreteTest method
        /*!
      \return pointer to ConcreteTest
      \param question pointer to Test
      \param user pointer to User (owner of concrete test)
      \param test pointer to Test
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::shared_ptr<ConcreteTest> addConcreteTest(const QString& name, const std::shared_ptr<User> user, const std::shared_ptr<Test> test);

    //! getAllConcreteTests method
        /*!
      \return vector with pointers to ConcreteTest
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::vector<std::shared_ptr<ConcreteTest>> getAllConcreteTests();

    //! addConcreteTest method
        /*!
      \param test pointer to ConcreteTest
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void deleteConcreteTest(std::shared_ptr<ConcreteTest> test);

    //! modifyConcreteTest method
        /*!
      \param test pointer to ConcreteTest
      \param name new name for ConcreTest
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    void modifyConcreteTest(std::shared_ptr<ConcreteTest> test, const QString& name);

    //! addAnswerToLogs method
        /*!
      \return pointer to ConcreteTest
      \param conc_test pointer to ConcreteTest
      \param quest pointer to Question
      \param grade answer grade
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::shared_ptr<OldUserAnswer> addAnswerToLogs(std::shared_ptr<ConcreteTest> conc_test, std::shared_ptr<Question> quest, unsigned short grade);

    //! getLogsForConcreteTests method
        /*!
      \return vevtor with pointers to OldUserAnswer
      \param conc_test pointer to ConcreteTest
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::vector<std::shared_ptr<OldUserAnswer>> getLogsForConcreteTests(std::shared_ptr<ConcreteTest> conc_test);

    //! getLogsForConcreteTests method
        /*!
      \return vevtor with pointers to OldUserAnswer
      \param concreteTestId id concreteTest from DB
      \throws <DatabaseException> { throws exception if query was failed or wrong parameter/aparameters were passed }
        */
    std::vector<std::shared_ptr<OldUserAnswer>> getLogsForConcreteTests(unsigned int concreteTestId);



private:
    QSqlDatabase m_db;
    static DbManager* mInstance;
    DbManager(const QString& path);
    unsigned int getLastInsertedRowId();
};



#endif // DATABASE_H


