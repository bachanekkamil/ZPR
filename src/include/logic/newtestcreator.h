#ifndef NEWTESTCREATOR_H
#define NEWTESTCREATOR_H

#include "test.h"
#include "questionreal.h"

class NewTestCreator
{

public:
    NewTestCreator();
    Test *m_Test;

    NewTestCreator(Test* _parent_test, QString name);
    ~NewTestCreator();
    void addQuestion(QString text, std::vector<QString> Answer, std::shared_ptr<Test> test, short correct_answer);
    Test* getNewTest();

private:
    Test* new_test;

};
#endif // NEWTESTCREATOR_H
