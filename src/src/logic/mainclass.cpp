#include "logic/mainclass.h"
#include "logic/database.h"
#include <logic/database_exception.h>
#include <QDebug>

MainClass::MainClass()
{/*
    //create db
    DbManager db = DbManager::getInstance();

    //get all users
    try
    {
        mUsers = db.getAllUsers();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllUsers(): " << e.what();
    }

    //get all test
    try
    {
        mTests = db.getAllTests();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllTests(): " << e.what();
    }







    //PIERDOŁY
    //add user test


    foreach(std::shared_ptr<Test> test, mTests)
    {

        qDebug() << "Test ID: " << QString::number(test->getIdDb()) << ". Test name: " << *test->getTestName() << ". Test owner name: " << *test->getTestOwner()->getName();
        foreach(std::shared_ptr<Question> question, test->getAllQuestions())
        {
            try
            {
            qDebug() << "Question: " << *question->getText();
            }
            catch(exception &e)
            {
                qDebug() << "Exception: " << e.what();
            }
            qDebug() << "Answer: " << *question->getCorrectAnswerText();
        }

    }



    try{
    db.addUser("Olson");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception: " << e.what();
    }




    //add test test
    int test_id;
    try
    {
    test_id = db.addTest("Test123", mUsers.at(0));
    qDebug() << "Added new test to DB. ID:" << QString::number(test_id);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }



//unsigned int DbManager::addQuestionAndAnswers(std::shared_ptr<Test> test, QString& question_text, std::vector<QString>& answers_text, unsigned short which_correct)

    QString question_text = "How are you?";
    QString answert_text = "OK";
    db.addQuestionAndAnswer(mTests.at(0), question_text, answert_text);



*/
//////////////???????????????

        /*/
    Answer ans("sda",0);

    ans.getIdDb();

        for(unsigned int i = 0 ; i<mUsers.size() ; ++i)
        {
            qDebug() << "User: " << *mUsers.at(i)->getName();
        }

    //add user test
    try{
    db.addUser("Olson");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }


    if(db.isUserExists(1))
    qDebug() << "User exists";

    db.removeUser("Kamil");
            qDebug() << "User deleted";


    try{
    //add user test
    unsigned int id = db.addUser("Kamil");
    qDebug() << "Added user with id: ";
    qDebug() << QString::number(id);
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }

    try{
    //add user test
    db.addUser("");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }


    try{
    //get user test
    std::shared_ptr<User> us = db.getUser(1);
    qDebug() << "Name: ";
    qDebug() << *us->getName();
    qDebug() << "Time created: ";
    qDebug() << us->getTimeCreated()->toString();
    deq.push_back(us);
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }

    qDebug() << "Name: ";
    qDebug() << *deq.at(0)->getName();
    qDebug() << "Time created: ";
    qDebug() << deq.at(0)->getTimeCreated()->toString();
    /*/


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
    return mConcreteTests;
}

std::vector<Test*> MainClass::getAvailableTest(){
    return mTest;
}

Game* MainClass::getGame(){
    return NULL;
}

NewTestCreator* MainClass::getNewTestCreator(){
    return NULL;
}

User* MainClass::getUser(){
    return mUser;
}

void MainClass::startConcreteTest(unsigned int, ConcreteTest *){

}

void MainClass::startNewTest(unsigned int, Test *){

}
