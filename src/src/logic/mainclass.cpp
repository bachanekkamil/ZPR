#include "logic/mainclass.h"
#include "logic/database.h"
#include <logic/database_exception.h>
#include <QDebug>

MainClass::MainClass()
{


    //create db
    DbManager db = DbManager::getInstance();

    /////////////

    /*try{
    db.addUser("Olson");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception in MainClass constructor: " << e.what();
    }*/

    //get all users
    try
    {
        mUsers = db.getAllUsers();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllUsers(): " << e.what();
    }

    /*

    //add test test
    int test_id;
    try
    {
    test_id = db.addTest("Test1234", mUsers.at(0));
    qDebug() << "Added new test to DB. ID:" << QString::number(test_id);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
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


    QString question_text = "How are you?";
    QString answert_text = "OK";
    try
    {
    db.addQuestionAndAnswer(mTests.at(0), question_text, answert_text);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }

    /////////////











    //PIERDOŁY
    //add user test


    foreach(std::shared_ptr<Test> test, mTests)
    {

        //qDebug() << "Test ID: " << QString::number(test->getIdDb()) << ". Test name: " << *test->getTestName() << ". Test owner name: " << *test->getTestOwner()->getName();


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

QStringList MainClass::getAllUsers(){
    QStringList list;
    for (std::shared_ptr<User> item: mUsers){
        list << item->getName();
    }
    return list;
}

void MainClass::setUser(int index){
    mUser=mUsers[index];
}

void MainClass::addNewUser(const QString &name){
    DbManager db = DbManager::getInstance();
    try
    {
        db.addUser("name");
        //db.addUser(name);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method addUser() newUser: " << e.what();
    }
}

void MainClass::deleteUser(int index){
    DbManager db = DbManager::getInstance();
    try
    {
        db.removeUser("name");
        //db.removeUser(mUsers[index]->getName());
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method removeUser(): " << e.what();
    }
}

int MainClass::iloscDB(){
    DbManager db = DbManager::getInstance();
    return db.zwrocIlosc();
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

std::shared_ptr<User> MainClass::getUser(){
    return mUser;
}

void MainClass::startConcreteTest(unsigned int, ConcreteTest *){

}

void MainClass::startNewTest(unsigned int, Test *){

}
