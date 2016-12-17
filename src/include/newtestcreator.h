#ifndef NEWTESTCREATOR_H
#define NEWTESTCREATOR_H

#include "test.h"

class NewTestCreator
{

public:
    NewTestCreator();
    Test *m_Test;

    NewTestCreator(Test* _parent_test, QString name);
    ~NewTestCreator();
    void addQuestion(Question name);
    Test* getNewTest();

private:
    Test* new_test;

};
#endif // NEWTESTCREATOR_H
