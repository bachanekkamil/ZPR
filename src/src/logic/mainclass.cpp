#include "logic/mainclass.h"
#include "logic/mainclassexception.h"
#include "logic/database.h"
#include <logic/database_exception.h>
#include <QDebug>

MainClass* MainClass::mInstance = nullptr;


void MainClass::Initialize()
{
    mUser=nullptr;
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

    qDebug() << "get all tests" ;
    try
    {
        mTests = db->getAllTests();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllTests(): " << e.what();
    }

    qDebug() << "get all ConcreteTests" ;

    try
    {
        mConcreteTests = db->getAllConcreteTests();
    }
    catch(DatabaseException &e)
    {
        qDebug() << "Database exception during method getAllConcreteTests(): " << e.what();
    }

}


MainClass::~MainClass()
{
    delete db;
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
}

void MainClass::logoutUser(){
    mUser=nullptr;
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
        throw MainClassException(e.what());
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
        throw MainClassException(e.what());
    }
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

QStringList MainClass::getAvailableTests(){
    QStringList list;
    for (std::vector<std::shared_ptr<Test>>::iterator it = mTests.begin(); it!=mTests.end(); ++it){
        list << (*it)->getTestName();
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
        throw MainClassException(e.what());
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

void MainClass::addQuestion(QString question,QString answer){
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

void MainClass::modifyQuestion(unsigned int index, QString question, QString answer){
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

std::shared_ptr<Question> MainClass::getQuestion(long long id_db)
{
    foreach(std::shared_ptr<Test> test, mTests)
    {
        std::shared_ptr<Question> q = test->getQuestion(id_db);
        if(q != nullptr)
                return q;
    }
    return nullptr;
}

void MainClass::addNewConcreteTest(QString& name){

    bool concrete_test_already_exist=false;
    foreach(std::shared_ptr<ConcreteTest> test, mConcreteTests)
    {
        if(test->getTestName()==name && test->getTestOwner()->getIdDb()==mUser->getIdDb()){
            concrete_test_already_exist=true;
            break;
        }
    }

    if(concrete_test_already_exist){
        throw MainClassException("Dany test jest już rozwiązywany przez użytkownika");

    }else{
        try{
            std::shared_ptr<Test> wsk;
            foreach(std::shared_ptr<Test> test, mTests)
            {
                if(test->getTestName()==name){
                    wsk=test;
                    break;
                }
            }
            std::shared_ptr<ConcreteTest> t=db->addConcreteTest(name,mUser,wsk);
            mConcreteTests.push_back(t);
            mConcreteTest=t;
        }catch(DatabaseException &e){
            qDebug() << "Database exception: " << e.what();
        }
    }

}

void MainClass::deleteConcreteTest(QString& name){

    for (std::vector<std::shared_ptr<ConcreteTest>>::iterator it = mConcreteTests.begin(); it != mConcreteTests.end(); ++it){
        if((name.compare((*it)->getTestName())==0) && (*it)->getTestOwner()->getIdDb()==mUser->getIdDb()){
            try{
                db->deleteConcreteTest((*it));
                mConcreteTests.erase(it);
            }catch(DatabaseException &e){
                qDebug() << "Database exception: " << e.what();
            }
            break;
        }
    }
}

QStringList MainClass::getAvailableConcreteTests(){
    QStringList list;

    foreach(std::shared_ptr<ConcreteTest> test, mConcreteTests)
    {
        if(test->getTestOwner()->getIdDb()==mUser->getIdDb()){

            list << test->getTestName();
            list << test->getTimeCreated().toString("yyyy.MM.dd");
        }
    }

    return list;
}

std::shared_ptr<ConcreteTest> MainClass::getCurrentConcreteTest(){
    return mConcreteTest;
}

void MainClass::addAnswerToCurrentConcreteTest(unsigned int question_id, unsigned short grade){
    try{
        std::shared_ptr<Question> q= mConcreteTest->getQuestionsForToday()[question_id];
        std::shared_ptr<OldUserAnswer> wsk = db->addAnswerToLogs(mConcreteTest, q, grade);
        mConcreteTest->addNewAnswer(wsk);

    }catch(DatabaseException &e){
        qDebug() << "Database exception: " << e.what();
    }
}

void MainClass::generateNewScheduler()
{
    mConcreteTest->refreshAnswers();
}

void MainClass::startConcreteTest(QString& name){
    foreach(std::shared_ptr<ConcreteTest> test, mConcreteTests)
    {
        if(test->getTestOwner()->getIdDb()==mUser->getIdDb() && test->getTestName()==name){
            mConcreteTest=test;
            break;
        }
    }
}

void MainClass::endCurrentConcreteTest(){
    mConcreteTest=nullptr;
}

void MainClass::endCreatingNewTest(){
    mTest=nullptr;
}



std::shared_ptr<User> MainClass::getUser(){
    return mUser;
}


