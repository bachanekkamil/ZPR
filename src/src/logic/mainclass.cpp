#include "logic/mainclass.h"
#include "logic/database.h"
#include <logic/database_exception.h>
#include <QDebug>

MainClass* MainClass::mInstance = nullptr;

MainClass::MainClass()
{
    mUser=nullptr;
    mState=NOT_LOGGED;
    //create db
    db = DbManager::getInstance();

    //get all users
    try
    {
        mUsers = db->getAllUsers();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllUsers(): " << e.what();
    }


/*

    //add test test
    try
    {
    shared_ptr<Test> test = db->addTest("Test12345", mUsers.at(0));
    qDebug() << "Added new test to db-> ID:" << QString::number(test->getIdDb());
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }*/



    qDebug() << "get all test " ;

    //get all test
    try
    {
        mTests = db->getAllTests();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllTests(): " << e.what();
    }
/*

    qDebug() << "add question ";

    QString question_text = "How are you?";
    QString answert_text = "OK";
    try
    {
    db->addQuestionAndAnswer(mTests.at(0), question_text, answert_text);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }*/

/*
    qDebug() << "add concrete test ";

    QString contestname = "My first concrete test";
    try
    {
    db->addConcreteTest(contestname, mUsers.at(0), mTests.at(0));
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during addConcreteTest method: " << e.what();
    }
    /*/

    /*
    qDebug() << "delete quest ";

    try
    {
    db->deleteQuestion(mTests.at(0)->getAllQuestions().at(0));
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during deleteQuestion method: " << e.what();
    }



    qDebug() << "delete test";

    try
    {
    db->deleteTest(mTests.at(0));
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during deleteTest method: " << e.what();
    }


    qDebug() << "delete all questions";

    try
    {
    db->deleteAllQuestionsForTest(mTests.at(0));
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during deleteAllQuestionsForTest method: " << e.what();
    }



    qDebug() << "modify test ";
    QString newTestName = "lalala";
    try
    {
    db->modifyTest(mTests.at(0), newTestName);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during modifyTest method: " << e.what();
    }

*/
    /////////////






    /*




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
    db->addUser("Olson");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }


    if(db->isUserExists(1))
    qDebug() << "User exists";

    db->removeUser("Kamil");
            qDebug() << "User deleted";


    try{
    //add user test
    unsigned int id = db->addUser("Kamil");
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
    db->addUser("");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }


    try{
    //get user test
    std::shared_ptr<User> us = db->getUser(1);
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
    for (std::vector<std::shared_ptr<User>>::iterator it = mUsers.begin(); it!=mUsers.end(); ++it){
        list << (*it)->getName();
    }
    return list;
}

void MainClass::setUser(const QString &name){
    for (std::vector<std::shared_ptr<User>>::iterator it = mUsers.begin(); it!=mUsers.end(); ++it){
        if(name.compare((*it)->getName())==0){
            mUser=*it;
            break;
        }
    }
    mState=NOT_LOGGED;
}

void MainClass::logoutUser(){
    mUser=nullptr;
    mState=NOT_LOGGED;
}

void MainClass::addNewUser(const QString &name){

    try
    {
        std::shared_ptr<User> new_user = db->addUser(name);
        mUsers.push_back(new_user);
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method addUser() newUser: " << e.what();
    }

}

void MainClass::deleteUser(const QString &name){
    try
    {
        db->removeUser(name);
        for (std::vector<std::shared_ptr<User>>::iterator it = mUsers.begin(); it!=mUsers.end(); ++it){
            if(name.compare((*it)->getName())==0){
                mUsers.erase(it);
                break;
            }
        }
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method removeUser(): " << e.what();
    }
}

void MainClass::createNewTest(){

}

void MainClass::endConcreteTest(){

}

void MainClass::endCreatingNewTest(){

}

std::vector<std::shared_ptr<ConcreteTest>> MainClass::getAvailableConcreteTests(){
    return mConcreteTests;
}

QStringList MainClass::getAvailableTests(){
    QStringList list;
    for (std::vector<std::shared_ptr<Test>>::iterator it = mTests.begin(); it!=mTests.end(); ++it){
        list << (*it)->getTestName();
        //list << QString::number((*it)->getNumberOfQuestions());
    }
    return list;
}

void MainClass::addNewTest(const QString& name){
    try
    {
        mTest = db->addTest(name, mUser);
        mTests.push_back(mTest);
        qDebug() << "Added new test to db-> ID:" << QString::number(mTest->getIdDb());
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }
}

void MainClass::editTest(const QString& name){
    for (std::vector<std::shared_ptr<Test>>::iterator it = mTests.begin(); it!=mTests.end(); ++it){
        if(name.compare((*it)->getTestName())==0){
            mTest=*it;
            break;
        }
    }
}

void MainClass::addQuestion(QString& question,QString& answer){
    try
    {
        unsigned int idDb=db->addQuestionAndAnswer(mTest,question,answer);
        std::shared_ptr<QuestionReal> question_real(new QuestionReal(idDb,answer,question));
        mTest->addQuestion(question_real);

    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }
}

void MainClass::modifyQuestion(unsigned int index, QString& question, QString& answer){
    try
    {
        db->modifyQuestion(mTest->getAllQuestions().at(index), question, answer);
        mTest->modifyQuestion(index,question,answer);

    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception: " << e.what();
    }
}

std::shared_ptr<Test> MainClass::getCurrentlyEditedTest(){
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

std::shared_ptr<User> MainClass::getUser(unsigned int idDb)
{
    foreach (std::shared_ptr<User> us, mUsers) {
        if(us->getIdDb() == idDb)
            return us;
    }
    return nullptr;
}

std::shared_ptr<Test> MainClass::getTest(unsigned int idDb)
{
    foreach (std::shared_ptr<Test> us, mTests) {
        if(us->getIdDb() == idDb)
            return us;
    }
    return nullptr;
}

std::shared_ptr<ConcreteTest> MainClass::getConcreteTest(unsigned int idDb)
{
    foreach (std::shared_ptr<ConcreteTest> us, mConcreteTests) {
        if(us->getIdDb() == idDb)
            return us;
    }
    return nullptr;
}
