#include "logic/concretetest.h"

ConcreteTest::ConcreteTest():id_concrete_test_db(0){

}


/**
 * pull data about concrete test from database
 */
ConcreteTest::ConcreteTest(unsigned int _id_concrete_test_db): id_concrete_test_db(_id_concrete_test_db){

}

/**
 * create new concrete test and push data to db
 */
ConcreteTest::ConcreteTest(Test* _test, User* _user, QString _name_from_user)
    : owner(_user),id_concrete_test_db(0){

}

ConcreteTest::~ConcreteTest(){

}


const QString* ConcreteTest::getConcreteTestName(){

    return  NULL;
}

