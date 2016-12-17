#ifndef ANSWERSDONE_H
#define ANSWERSDONE_H
#include <vector>
#include <olduseranswer.h>

using namespace std;
struct AnswersDone
{

public:
    std::vector<OldUserAnswer> correct;
    const unsigned int id_question_db;

    AnswersDone(bool _correct, unsigned short _answer_number, unsigned int _concrete_test_id, unsigned int _id_question_db);
    AnswersDone(unsigned int _id_concrete_test, unsigned int _id_question_db);

};
#endif // ANSWERSDONE_H
