#include "answersdone.h"


/**
 * throw std::invalid_argument exception, push info about answer to database to
 * database
 */
AnswersDone::AnswersDone(bool _correct, unsigned short _answer_number,
                         unsigned int _concrete_test_id, unsigned int _id_question_db)
                            :id_question_db(_id_question_db){

}


/**
 * pull answers from database for one question from concrete test
 */
AnswersDone::AnswersDone(unsigned int _id_concrete_test, unsigned int _id_question_db)
    : id_question_db(_id_question_db){

}
