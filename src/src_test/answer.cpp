#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE AnswerTest
#define BOOST_TEST_DYN_LINK


#include "src/logic/answer.cpp"
#include <QString>


#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;
using namespace boost::unit_test_framework;


BOOST_AUTO_TEST_CASE( answer_test )
{
    Answer answer("qwerty", 0);

    BOOST_CHECK( answer.getIdDb()!=0);
}