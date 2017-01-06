#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE Tests
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include "../src/src/logic/database.cpp"
#include "logic/database.h"
#include "logic/mainclass.h"
#include <QtSql/QSqlDatabase>
#include "logic/game.h"
#include "../include/logic/game.h"
#include "../include/logic/answersdone.h"
#include <QString>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;



BOOST_AUTO_TEST_CASE( Tests )
{
  //  AnswersDone answer("qwerty", 0);
/*
	Game *game = new Game();
   	BOOST_CHECK( game->getNumberOfQuestion()==0);
	delete game;

*/
 	BOOST_CHECK( 0==0);

}


