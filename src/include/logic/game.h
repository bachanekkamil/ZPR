#ifndef GAME_H
#define GAME_H

#include "concretetest.h"

class Game
{

public:
    Game();
    ConcreteTest *m_ConcreteTest;

    Game(unsigned int _number_of_questions, ConcreteTest* concrete_test, User* _user);
    ~Game();
    ConcreteTest* getActualConcreteTest();
    unsigned int getNumberOfQuestion();
    unsigned int getNumberOfQuestionDone();

private:
    ConcreteTest* actual_test;
    const User* actual_user;
    std::vector<ConcreteTest> concrete_tests;
    const unsigned int number_of_questions;
    unsigned int number_of_questions_done;

};
#endif // GAME_H
