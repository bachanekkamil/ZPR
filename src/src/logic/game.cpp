#include "logic/game.h"

Game::Game():number_of_questions(0)
{

}

Game::Game(unsigned int _number_of_questions, ConcreteTest* concrete_test, User* _user)
    :number_of_questions(_number_of_questions){

}


Game::~Game(){

}


ConcreteTest* Game::getActualConcreteTest(){

    return  NULL;
}


unsigned int Game::getNumberOfQuestion(){

    return 0;
}


unsigned int Game::getNumberOfQuestionDone(){

    return 0;
}
