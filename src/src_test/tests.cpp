#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Tests

#include "../src/logic/answersdone.cpp"
#include "../src/logic/concretetest.cpp"
#include "../src/logic/database.cpp"
#include "../src/logic/database_exception.cpp"
#include "../src/logic/game.cpp"
#include "../src/logic/mainclass.cpp"
#include "../src/logic/mainclassexception.cpp"
#include "../src/logic/newtestcreator.cpp"
#include "../src/logic/olduseranswer.cpp"
#include "../src/logic/question.cpp"
#include "../src/logic/questionproxy.cpp"
#include "../src/logic/questionreal.cpp"
#include "../src/logic/test.cpp"
#include "../src/logic/user.cpp"

#include <boost/test/unit_test.hpp>
class DbManager;
using namespace boost::unit_test;
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_CASE( database )
{

    DbManager* db = DbManager::getInstance();
    bool cond = db->isOpen();
    BOOST_CHECK_EQUAL(cond, true);

    db->removeAllUsers();
    std::vector<std::shared_ptr<User>> users;
    std::shared_ptr<User> usr = db->addUser("testUsr");

    BOOST_CHECK(usr);
    users = db->getAllUsers();
    std::shared_ptr<User> usr2 = db->addUser("testUsr23");
    usr = db->getUser(1);

//    BOOST_CHECK(users);

//    BOOST_CHECK((db->getUser(0)) =="user2");


//    std::shared_ptr<User> DbManager::addUser(const QString& name)
//    {
//        if (!name.isEmpty())
//        {
//            QSqlQuery queryAdd(m_db);
//            queryAdd.prepare("INSERT INTO Users (name) VALUES (:name)");
//            queryAdd.bindValue(":name", name);

//            if(queryAdd.exec())
//            {
//                return getUser(getLastInsertedRowId());
//            }
//            else
//            {
//                throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
//            }
//        }
//        else
//        {
//            throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
//        }
//    }


}



//void test_case1()
//{
//    DbManager::getInstance()->isOpen();
////    bool cond = (GameList::getInstance()->getResult(third_player_id) == STILL_PLAYING
////                     && GameList::getInstance()->getResult(first_player_id) == STILL_PLAYING);
//       BOOST_CHECK_EQUAL(true, true);
//}
//test_suite* init_unit_test_suite( int argc, char * argv[] )
//{
//    test_suite *ts0 = BOOST_TEST_SUITE( "CheckPlayersSuite" );
//    ts0->add( BOOST_TEST_CASE( & test_case1 ) );
//    framework::master_test_suite().add( ts0 );
//    return 0;
//}
