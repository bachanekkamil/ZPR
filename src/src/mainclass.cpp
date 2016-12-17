#include "mainclass.h"

MainClass::MainClass()
{

}

MainClass::~MainClass()
{

}

void MainClass::createNewTest(){

}

void MainClass::endConcreteTest(){

}

void MainClass::endCreatingNewTest(){

}

std::vector<ConcreteTest*> MainClass::getAvailableConcreteTests(){
    return concrete_tests;
}

std::vector<Test*> MainClass::getAvailableTest(){
    return tests;
}

Game* MainClass::getGame(){
    return NULL;
}

NewTestCreator* MainClass::getNewTestCreator(){
    return NULL;
}

User* MainClass::getUser(){
    return actual_user;
}

void MainClass::startConcreteTest(unsigned int, ConcreteTest *){

}

void MainClass::startNewTest(unsigned int, Test *){

}
