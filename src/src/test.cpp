#include "test.h"

Test::Test(): id_test_db(0)
{

}

Test::Test(unsigned int _id_test_db): id_test_db(_id_test_db){

}


Test::Test(QString _name, User _user): id_test_db(0){

}


Test::~Test(){

}


void Test::addQuestion(Question* _question){

}

std::unordered_map<int, Question*> Test::getAllQuestions(){

    return  questions;
}


Test* Test::getParentTest(){

    return  NULL;
}


Question* Test::getQuestion(unsigned int _id_db){

    return  NULL;
}


const QString* Test::getTestName(){

    return  NULL;
}


User* Test::getTestOwner(){

    return  NULL;
}

void Test::setTestName(QString _name){

}
