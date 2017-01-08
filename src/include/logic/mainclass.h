#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <vector>
#include <logic/concretetest.h>
#include <logic/game.h>
#include <logic/newtestcreator.h>
#include <logic/database.h>
#include <logic/concretetest.h>

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
            mInstance = new MainClass();
        return mInstance;
    }
    ~MainClass();

    QStringList getAllUsers();
    void setUser(const QString& name);
    void logoutUser();
    void addNewUser(const QString& name);
    void deleteUser(const QString& name);
    std::shared_ptr<User> getUser(unsigned int idDb);
    std::shared_ptr<Test> getTest(unsigned int idDb);
    std::shared_ptr<ConcreteTest> getConcreteTest(unsigned int idDB);
    QStringList getAvailableTests();
    void addNewTest(const QString& name);
    void editTest(const QString& name);
    void addQuestion(QString question, QString answer);
    void modifyQuestion(unsigned int index, QString question, QString answer);
    std::shared_ptr<Test> getCurrentlyEditedTest();

    //not used now
    void createNewTest();
    void endConcreteTest();
    void endCreatingNewTest();
    std::vector<std::shared_ptr<ConcreteTest>> getAvailableConcreteTests();

    Game *getGame();
    NewTestCreator* getNewTestCreator();
    std::shared_ptr<User> getUser();
    void startConcreteTest(unsigned int, ConcreteTest*);
    void startNewTest(unsigned int, Test*);

private:
    MainClass();
    std::vector<std::shared_ptr<User>> mUsers;
    std::vector<std::shared_ptr<Test>> mTests;
    std::vector<std::shared_ptr<ConcreteTest>> mConcreteTests;
    static MainClass* mInstance;

    std::shared_ptr<User> mUser;

    // wskaznik na aktualnie tworzony przez uzytkownika nowy test/ aktualnie edytowany test
    std::shared_ptr<Test> mTest;
    DbManager* db;

    //not used now
    state mState;
    Game* mGame;
    NewTestCreator* mNewTestCreator;
};

#endif // MAINCLASS_H
