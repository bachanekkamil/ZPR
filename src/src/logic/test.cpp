//!
/*!
  \brief Contains class Test method implementation
  \author Kamil Bachanek
*/

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

std::shared_ptr<Question> Test::getQuestion(unsigned int idDb)
{
    foreach(std::shared_ptr<Question> question, mQuestions)
        if(question->getIdDb() == idDb)
            return question;
    return nullptr;
}


std::vector<std::shared_ptr<Question>> Test::getAllQuestions(){

    return mQuestions;
}

