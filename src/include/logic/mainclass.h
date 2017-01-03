#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <vector>
#include <logic/concretetest.h>
#include <logic/game.h>
#include <logic/newtestcreator.h>

enum state{
    running_test = 0,
    creating_test = 1,
    editing_test = 2,
    not_logged = 3,
    not_bussy = 4
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
    state actual_state;
    User* actual_user;
    std::vector<ConcreteTest*> concrete_tests;
    Game* game;
    NewTestCreator* new_test;
    std::vector<Test*> tests;
};

#endif // MAINCLASS_H
