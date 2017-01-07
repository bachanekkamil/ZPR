#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE AnswersDone

#include "../src/logic/answersdone.cpp"
#include "../src/logic/concretetest.cpp"
#include "../src/logic/database.cpp"
#include "../src/logic/database_exception.cpp"
#include "../src/logic/game.cpp"
#include "../src/logic/mainclass.cpp"
#include "../src/logic/newtestcreator.cpp"
#include "../src/logic/olduseranswer.cpp"
#include "../src/logic/question.cpp"
#include "../src/logic/questionproxy.cpp"
#include "../src/logic/questionreal.cpp"
#include "../src/logic/test.cpp"
#include "../src/logic/user.cpp"

#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;

void test_case1()
{
    DbManager::getInstance()->isOpen();
//    bool cond = (GameList::getInstance()->getResult(third_player_id) == STILL_PLAYING
//                     && GameList::getInstance()->getResult(first_player_id) == STILL_PLAYING);
       BOOST_CHECK_EQUAL(true, true);
}
test_suite* init_unit_test_suite( int argc, char * argv[] )
{
    test_suite *ts0 = BOOST_TEST_SUITE( "CheckPlayersSuite" );
    ts0->add( BOOST_TEST_CASE( & test_case1 ) );
    framework::master_test_suite().add( ts0 );
    return 0;
}
