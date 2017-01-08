#include "logic/test.h"
#include "logic/database.h"



Test::Test(unsigned int id_test_db, QString name, std::shared_ptr<User> createdBy, std::vector<std::shared_ptr<Question>> questions):
    mIdTestDb(id_test_db), mName(name), mCreatedBy(createdBy), mQuestions(questions)
{

}

const QString& Test::getTestName() const{

    return mName;
}


std::shared_ptr<User> Test::getTestOwner() const{

    return  mCreatedBy;
}

unsigned int Test::getIdDb() const
{
    return mIdTestDb;
}

int Test::getNumberOfQuestions(){
    return mQuestions.size();
}

void Test::addQuestion(std::shared_ptr<Question> question){
    mQuestions.push_back(question);
}

void Test::modifyQuestion(unsigned int index, const QString& question, const QString& answer){
    mQuestions.at(index)->modifyQuestion(question,answer);
}

//not used now

Test::Test(): mIdTestDb(0)
{

}

Test::Test(QString _name, User _user): mIdTestDb(0){

}


Test::~Test(){

}




std::vector<std::shared_ptr<Question>> Test::getAllQuestions(){

    return mQuestions;
}

Test* Test::getParentTest(){

    return  NULL;
}


Question* Test::getQuestion(unsigned int _id_db){

    return  NULL;
}




void Test::setTestName(QString _name){

}
