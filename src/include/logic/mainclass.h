#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <vector>
#include <logic/concretetest.h>
#include <logic/game.h>
#include <logic/newtestcreator.h>

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
    MainClass();
    ~MainClass();

    //not used now
    void createNewTest();
    void endConcreteTest();
    void endCreatingNewTest();
    std::vector<ConcreteTest*> getAvailableConcreteTests();
    std::vector<Test*> getAvailableTest();
    Game* getGame();
    NewTestCreator* getNewTestCreator();
    User *getUser();
    void startConcreteTest(unsigned int, ConcreteTest*);
    void startNewTest(unsigned int, Test*);

private:
    std::vector<std::shared_ptr<User>> mUsers;
    std::vector<std::shared_ptr<Test>> mTests;

    //not used now
    state mState;
    User* mUser;
    std::vector<ConcreteTest*> mConcreteTests;
    Game* mGame;
    NewTestCreator* mNewTestCreator;
    std::vector<Test*> mTest;
};

#endif // MAINCLASS_H
