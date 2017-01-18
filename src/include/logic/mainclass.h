//!
/*!
  \brief Class responsible for integrating application logic and delivering methods for GUI
  \author Aleksandra Grzegorczyk
  \author Kamil Bachanek
*/

#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <vector>
#include <logic/concretetest.h>
#include <logic/database.h>
#include <logic/concretetest.h>
#include <QDebug>

//!  MainClass
/*!
  Class which is responsible for integrating application logic and delivering methods for GUI
*/

class MainClass
{
public:
    //!  getInstance method
    /*!
      Impelements signleton design pattern
    */
    static MainClass* getInstance()
    {
        if(mInstance == nullptr)
        {
            mInstance = new MainClass();
        }
        return mInstance;
    }
    ~MainClass();

    //! Initialize method
    /*!
      Sets initial value for class attributes which are stored in data base
    */
    void Initialize();

    //! getAllUsers method
    /*!
      \return list containing users logins
    */
    QStringList getAllUsers();

    //! setUser method
        /*!
      \param name user name
        */
    void setUser(const QString& name);

    //! logoutUser method
    /*!
      Sets pointer to current User to nullptr
    */
    void logoutUser();

    //! addNewUser method
        /*!
      \param name user name
      \throws <MainClassException> { throws exception if adding new user to data base was unsuccessful }
        */
    void addNewUser(const QString& name);

    //! deleteUser method
        /*!
      \param name user name
      \throws <MainClassException> { throws exception if removing user from data base was unsuccessful }
        */
    void deleteUser(const QString& name);

    //! getUser method
        /*!
      \param id user id from data base
        */
    std::shared_ptr<User> getUser(unsigned int idDb);

    //! getTest method
        /*!
      \param id test id from data base
        */
    std::shared_ptr<Test> getTest(unsigned int idDb);

    //! getConcreteTest method
        /*!
      \param id concrete test id from data base
        */
    std::shared_ptr<ConcreteTest> getConcreteTest(unsigned int idDB);

    //! getAvailableTests method
    /*!
      \return list containing all tests form data base
    */
    QStringList getAvailableTests();

    //! addNewTest method
        /*!
      \param name new test name
      \throws <MainClassException> { throws exception if adding new test to data base was unsuccessful }
        */
    void addNewTest(const QString& name);

    //! editTest method
        /*!
      \param name edited test name
        */
    void editTest(const QString& name);

    //! addQuestion method
        /*!
      \param question contents of question
      \param answer contents of answer
      \throws <MainClassException> { throws exception if adding new question and answer to data base was unsuccessful }
        */
    void addQuestion(QString question, QString answer);

    //! modifyQuestion method
        /*!
      \param index position of question in vector from Test class object representing test in which this question occur
      \param question contents of question
      \param answer contents of answer
      \throws <MainClassException> { throws exception if changing question and answer in data base was unsuccessful }
        */
    void modifyQuestion(unsigned int index, QString question, QString answer);

    //! getCurrentlyEditedTest method
    /*!
      \return pointer to currently edited test
    */
    std::shared_ptr<Test> getCurrentlyEditedTest();

    //! getQuestion method
    /*!
      \return pointer question
    */
    std::shared_ptr<Question> getQuestion(long long id_db);

    //! addNewConcreteTest method
        /*!
      \param name new concrete test name
      \throws <MainClassException> { throws exception if adding new concrete test to data base was unsuccessful }
        */
    void addNewConcreteTest(QString& name);

    //! deleteConcreteTest method
        /*!
      \param name name of test to be deleted
      \throws <MainClassException> { throws exception if deleting concrete test from data base was unsuccessful }
        */
    void deleteConcreteTest(QString& name);

    //! getAvailableConcreteTests method
    /*!
      \return list of all concrete test available to current user, and date of next repetition
    */
    QStringList getAvailableConcreteTests();

    //! getCurrentConcreteTest method
    /*!
      \return pointer to concrete test that user chose for repetition
    */
    std::shared_ptr<ConcreteTest> getCurrentConcreteTest();

    //! addAnswerToCurrentConcreteTest method
        /*!
      \param question_id position of question in vector from conrete test class object returned by method getQuestionsForToday() from concrete test class
      \param grade grade which was chosen by user
      \throws <MainClassException> { throws exception if adding new answer to concrete test to data base was unsuccessful }
        */
    void addAnswerToCurrentConcreteTest(unsigned int question_id, unsigned short grade);

    //! startConcreteTest method
        /*!
      \param name concrete test name
      \throws <MainClassException> { throws exception if there are no question to be answered this day  }
        */
    void startConcreteTest(QString& name);

    //! endCurrentConcreteTest method
    /*!
      Sets pointer to current ConcreteTest to nullptr
    */
    void endCurrentConcreteTest();

    //! endCreatingNewTest method
    /*!
      Sets pointer to current new Test to nullptr
    */
    void endCreatingNewTest();

    //! generateNewScheduler method
        /*!
        */
    void generateNewScheduler();

    //! getUser method
    /*!
      \return pointer to user
    */
    std::shared_ptr<User> getUser();

private:
    MainClass(){}
    static MainClass* mInstance;
    DbManager* db;
    std::vector<std::shared_ptr<User>> mUsers;
    std::vector<std::shared_ptr<Test>> mTests;
    std::vector<std::shared_ptr<ConcreteTest>> mConcreteTests;
    std::shared_ptr<User> mUser;
    std::shared_ptr<Test> mTest;
    std::shared_ptr<ConcreteTest> mConcreteTest;
};

#endif // MAINCLASS_H
