#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <vector>
#include <logic/concretetest.h>
#include <logic/game.h>
#include <logic/newtestcreator.h>
#include <logic/database.h>
#include <logic/concretetest.h>
#include <QDebug>

enum state{
    RUNNING_TEST = 0,
    CREATING_TEST = 1,
    EDITING_TEST = 2,
    NOT_LOGGED = 3,
    NOT_BUSSY = 4,
};

class MainClass
{
public:
    static MainClass* getInstance()
    {
        if(mInstance == nullptr)
        {
            mInstance = new MainClass();
        }
        return mInstance;
    }
    ~MainClass();
    void Initialize();

    // user
    QStringList getAllUsers();
    void setUser(const QString& name);
    void logoutUser();
    void addNewUser(const QString& name);
    void deleteUser(const QString& name);

    // used by database class
    std::shared_ptr<User> getUser(unsigned int idDb);
    std::shared_ptr<Test> getTest(unsigned int idDb);
    std::shared_ptr<ConcreteTest> getConcreteTest(unsigned int idDB);

    // test
    QStringList getAvailableTests();
    void addNewTest(const QString& name);
    void editTest(const QString& name);
    void addQuestion(QString question, QString answer);
    void modifyQuestion(unsigned int index, QString question, QString answer);
    std::shared_ptr<Test> getCurrentlyEditedTest();

    //
    std::shared_ptr<Question> getQuestion(long long id_db);

    //concrete test
    void addNewConcreteTest(QString& name);
    void deleteConcreteTest(QString& name);
    QStringList getAvailableConcreteTests();
    std::shared_ptr<ConcreteTest> getCurrentConcreteTest();
    void addAnswerToCurrentConcreteTest(unsigned int question_id, unsigned short grade);
    void startConcreteTest(QString& name);


    //not used now
    void endCurrentConcreteTest();
    void endCreatingNewTest();

    Game *getGame();
    NewTestCreator* getNewTestCreator();
    std::shared_ptr<User> getUser();

private:
    MainClass();
    std::vector<std::shared_ptr<User>> mUsers;
    std::vector<std::shared_ptr<Test>> mTests;
    std::vector<std::shared_ptr<ConcreteTest>> mConcreteTests;
    static MainClass* mInstance;

    std::shared_ptr<User> mUser;

    // wskaznik na aktualnie tworzony przez uzytkownika nowy test/ aktualnie edytowany test
    std::shared_ptr<Test> mTest;
    std::shared_ptr<ConcreteTest> mConcreteTest;
    DbManager* db;

    //not used now
    state mState;
    Game* mGame;
    NewTestCreator* mNewTestCreator;
};

#endif // MAINCLASS_H
