#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Tests

#include "../src/logic/concretetest.cpp"
#include "../src/logic/database.cpp"
#include "../src/logic/database_exception.cpp"
#include "../src/logic/mainclass.cpp"
#include "../src/logic/mainclassexception.cpp"
#include "../src/logic/olduseranswer.cpp"
#include "../src/logic/question.cpp"
#include "../src/logic/questionproxy.cpp"
#include "../src/logic/questionreal.cpp"
#include "../src/logic/test.cpp"
#include "../src/logic/user.cpp"

#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_CASE( database )
{

    DbManager* db = DbManager::getInstance();
    DatabaseException *exc = new DatabaseException("TEXT_PASSED_NULL_PARAMETER");
    std::vector<std::shared_ptr<User>> users;
    std::shared_ptr<User> usr,usr2;
    std::shared_ptr<Test> test;
    std::vector<std::shared_ptr<Test>> tests;
    std::vector<std::shared_ptr<Question>> questions;
    std::vector<std::shared_ptr<ConcreteTest>> concreteTests;
    std::vector<std::shared_ptr<OldUserAnswer>> oldUserAnswers;

    std::shared_ptr<ConcreteTest> concreteTest, cTest;
    std::shared_ptr<Question> question (new QuestionReal(1, "Pies", "Dog"));
    QString testQuestion = "Dog";
    QString testAnswer= "Pies";

    QString date = "2017-01-11 11:11:11";
    QString format = "yyyy-MM-dd HH:mm:ss";
    QDateTime dt = QDateTime::fromString(date, format);
    const QDateTime* today = new QDateTime();
    long long id;
    unsigned short grade;
    double factor = 4.5;
    short unsigned int grd = 4;
    std::shared_ptr<OldUserAnswer> oldUserAnswer(new OldUserAnswer(1, dt, question, grd, factor) );


    BOOST_CHECK(exc);

    bool cond = db->isOpen();
    BOOST_CHECK_EQUAL(cond, true);

    usr = db->addUser("user");
    BOOST_CHECK(usr);

    db->removeAllUsers();
    BOOST_REQUIRE_THROW(db->addUser(""), DatabaseException);

    users = db->getAllUsers();
    BOOST_CHECK_EQUAL(users.size(),0);

    usr = db->addUser("user");
    usr2 = db->addUser("user2");

    users = db->getAllUsers();

    db -> removeUser("user");
    BOOST_CHECK_EQUAL(db->isUserExists("user"), false);

    db -> removeUser(2);
    BOOST_CHECK_EQUAL(db->isUserExists(2), false);

    BOOST_REQUIRE_THROW(db -> removeUser("user"), DatabaseException);

    BOOST_REQUIRE_THROW(db -> removeUser(2), DatabaseException);

    usr = db->addUser("user");
    BOOST_CHECK(usr);
    BOOST_CHECK_EQUAL(db->isUserExists(1), true);

    usr2 = db->addUser("user2");

    usr = db->getUser(1);
    BOOST_CHECK(usr ->getName() == QString("user"));

    usr2 = db->getUser(2);
    BOOST_CHECK(usr2 ->getName() == QString("user2"));

    BOOST_REQUIRE_THROW(db->getUser(4), DatabaseException);
    BOOST_REQUIRE_THROW(db->getUser(0), DatabaseException);

    users = db->getAllUsers();

    // TODO : przetestować users
    // BOOST_CHECK_EQUAL(users.at(1), "user");

    test = db ->addTest("test1",usr);
    BOOST_CHECK(test);

    concreteTest = db->addConcreteTest("concreteTest", usr, test);

    BOOST_REQUIRE_THROW(db->addConcreteTest("concreteTest", 0L, test), DatabaseException);


    BOOST_CHECK(test ->getTestName() == QString("test1"));

    tests = db->getAllTests();

    unsigned int i = db->addQuestionAndAnswer(test, testQuestion, testAnswer);


    questions = db -> getAllQuestionForTest(1);


   //   concreteTests = db ->getAllConcreteTests();
      db->modifyConcreteTest(concreteTest, "concreteTest");
      BOOST_REQUIRE_THROW(db->modifyConcreteTest(concreteTest, ""), DatabaseException);
      BOOST_REQUIRE_THROW(db->modifyConcreteTest(0L, "concreteTest"), DatabaseException);


   //qInfo() << i;

   //BOOST_CHECK(i);
     db ->modifyQuestion(questions.at(0),testAnswer, testQuestion);

     BOOST_REQUIRE_THROW(db ->deleteQuestion(nullptr), DatabaseException);

     db ->deleteQuestion(questions.at(0));

//   BOOST_CHECK(question);

     BOOST_REQUIRE_THROW(db -> getRealQuestion(1), DatabaseException);
     BOOST_REQUIRE_THROW(db -> getRealQuestion(0), DatabaseException);


    db ->modifyTest(test, "test2");

    db -> deleteAllQuestionsForTest(test);

   concreteTest->addNewAnswer(oldUserAnswer);

   BOOST_REQUIRE_THROW(db->addAnswerToLogs(concreteTest, question, grd), DatabaseException);

   // TODO :
//   oldUserAnswer = db ->addAnswerToLogs(concreteTest, question, grd);
   //BOOST_CHECK(oldUserAnswer);

    oldUserAnswers = db -> getLogsForConcreteTests(0);
   BOOST_CHECK(oldUserAnswers.at(0));

   db->deleteConcreteTest(concreteTest);
   db-> deleteTest(test);
   BOOST_REQUIRE_THROW(db->deleteTest(0L), DatabaseException);


}

BOOST_AUTO_TEST_CASE( user )
{

    unsigned int id = 1;
    QString usrName = "usr";
    QString date = "2017-01-11 11:11:11";
    QString format = "yyyy-MM-dd HH:mm:ss";
    QDateTime dt = QDateTime::fromString(date, format);


    std::shared_ptr<User> user(new User(usrName, id, dt));
    BOOST_CHECK(user);

    BOOST_CHECK(user->getTimeCreated()->date() == dt.date());
    BOOST_CHECK(user->getName() == usrName);
    BOOST_CHECK(user->getIdDb() == id);


}


BOOST_AUTO_TEST_CASE( test )
{
    std::vector<std::shared_ptr<Question>> questions;
    std::shared_ptr<Question> question(new QuestionReal(1, "Pies", "Dog"));

    QString usrName = "usr2";
    QString date = "1992-21-32 12:32:32";
    QString format = "yyyy-MM-dd HH:mm:ss";
    QDateTime dt = QDateTime::fromString(date, format);

    std::shared_ptr<User> user(new User(usrName, 3, dt));
    std::shared_ptr<Test> test(new Test(1, "test01", user, questions));

    BOOST_CHECK_EQUAL (test ->getTestOwner(), user);
    BOOST_CHECK_EQUAL (test ->getNumberOfQuestions(), 0);

    test ->addQuestion(question);
    BOOST_CHECK_EQUAL (test ->getNumberOfQuestions(), 1);

    test ->modifyQuestion(0, "Kot","Cat");
    BOOST_CHECK(test);

    question = test ->getQuestion(1);
    BOOST_CHECK(question);

    questions = test ->getAllQuestions();
}

BOOST_AUTO_TEST_CASE( questionReal )
{

    std::vector<std::shared_ptr<Question>> questions;
    QString text;
    std::shared_ptr<Question> question(new QuestionReal(1, "Pies", "Dog"));

    text = question->getText();
    BOOST_CHECK (text == "Dog");
    text = question->getCorrectAnswerText();
    BOOST_CHECK (text == "Pies");

    question->modifyQuestion("Cat", "Kot");

    text = question->getText();
    BOOST_CHECK (text == "Cat");
    text = question->getCorrectAnswerText();
    BOOST_CHECK (text == "Kot");

    question->setFactor(4.5);
    BOOST_CHECK (question->getFactor() == 4.5);


}

BOOST_AUTO_TEST_CASE( questionProxy )
{

    QString usrName = "usr2";
    QString date = "1992-21-32 12:32:32";
    QString format = "yyyy-MM-dd HH:mm:ss";
    QDateTime dt = QDateTime::fromString(date, format);
    std::vector<std::shared_ptr<Question>> questions;
    double factor = 3.4;

    std::shared_ptr<User> user(new User(usrName, 3, dt));
    std::shared_ptr<Test> test(new Test(1, "test04", user, questions));

    QString text;
    std::shared_ptr<Question> question(new QuestionReal(1, "Pies", "Dog"));
    std::shared_ptr<Question> questionProxy(new QuestionProxy(question->getIdDb()));

    test ->addQuestion(question);


    BOOST_REQUIRE_THROW (questionProxy ->getText(), DatabaseException);
    BOOST_REQUIRE_THROW (questionProxy ->setFactor(factor), DatabaseException);
    BOOST_REQUIRE_THROW (questionProxy ->getFactor(), DatabaseException);
    BOOST_REQUIRE_THROW (questionProxy ->getCorrectAnswerText(), DatabaseException);
    BOOST_REQUIRE_THROW (questionProxy ->modifyQuestion("Kot", "Cat"), DatabaseException);
}

BOOST_AUTO_TEST_CASE( oldUserAnswer ){

    QString usrName = "usr2";
    QString date = "2017-01-11 11:11:11";
    QString format = "yyyy-MM-dd HH:mm:ss";
    QDateTime dt = QDateTime::fromString(date, format);
    const QDateTime* time;

    const QDateTime* today = new QDateTime();
    long long id;
    unsigned short grade;
    double factor = 4.5;
    short unsigned int grd = 4;
    std::shared_ptr<Question> question(new QuestionReal(1, "Pies", "Dog"));
    std::shared_ptr<OldUserAnswer> oldUserAnswer(new OldUserAnswer(1, dt, question, grd, factor) );

    id = oldUserAnswer->getIdDb();
    BOOST_CHECK (id == 1);


    grade = oldUserAnswer->getGrade();
    BOOST_CHECK (grade == grd);

    time = oldUserAnswer-> getDateTimeCreated();
    BOOST_CHECK (time->date() == dt.date());

    BOOST_CHECK(oldUserAnswer->getFactor()==factor);
    question = oldUserAnswer->getQuestion();
    BOOST_CHECK(question);

}


BOOST_AUTO_TEST_CASE( concreteTest ){
    unsigned int id = 2;
    QString usrName = "usr02";
    QString date = "2017-01-11 11:11:11";
    QString format = "yyyy-MM-dd HH:mm:ss";
    QString name = "concreteTest";
    QDateTime dt = QDateTime::fromString(date, format);
    std::shared_ptr<User> user(new User(usrName, id, dt));
    std::shared_ptr<Question> question (new QuestionReal(1, "Pies", "Dog"));
    std::vector<std::shared_ptr<Question>> questions;
    std::shared_ptr<OldUserAnswer> oldUserAnswer(new OldUserAnswer(1, dt, question, 4, 3.5) );
    std::vector<std::shared_ptr<OldUserAnswer>> oldUserAnswers;
    oldUserAnswers.push_back(oldUserAnswer);
    questions.push_back(question);
    std::shared_ptr<Test> test(new Test(1, "test02", user, questions));

    std::shared_ptr<ConcreteTest> concreteTest(new ConcreteTest(2, test, user, name,
                                                                dt,oldUserAnswers));

    BOOST_CHECK(concreteTest->getTestOwner()==user);
    BOOST_CHECK(concreteTest->getTestName()==name);
    BOOST_CHECK(concreteTest->getTimeCreated().date()==dt.date());

    oldUserAnswers = concreteTest->getAllOldAnswers();
    BOOST_CHECK(oldUserAnswers.at(0) == oldUserAnswer);

    concreteTest->refreshAnswers();

    concreteTest->addNewAnswer(oldUserAnswer);
    oldUserAnswers = concreteTest->getAllOldAnswers();

    BOOST_CHECK(oldUserAnswers.size() == 2);

    BOOST_CHECK((concreteTest ->getDateForNextTest()).isValid());
}


BOOST_AUTO_TEST_CASE( mainClass ) {
    MainClass* mc = MainClass::getInstance();
    std::shared_ptr<User> user;
    std::shared_ptr<Test> test;
    std::shared_ptr<ConcreteTest> cTest;
    QStringList userList;
    QString name = "user007";
    QString testName = "test007";
    QString concreteName = "test007Con";

    QStringList testList;
    std::shared_ptr<Question> question(new QuestionReal(1, "Pies", "Dog"));

    mc ->Initialize();
    mc -> addNewUser(name);
    userList = mc ->getAllUsers();

    BOOST_CHECK(userList.at(userList.size()-1)==name);
    mc ->setUser(name);
    BOOST_CHECK(mc ->getUser(userList.size()-1));

    mc -> addNewTest(testName);
    BOOST_REQUIRE_THROW(mc -> addNewTest(testName), MainClassException);
    testList = mc ->getAvailableTests();

    int id = testList.size() - 1;

    BOOST_CHECK(testList.at(id)==testName);

    BOOST_CHECK(mc->getTest(id));

    mc ->editTest(testName);

    BOOST_REQUIRE_NO_THROW(mc ->addQuestion("question", "answer"));
    BOOST_REQUIRE_NO_THROW(mc ->modifyQuestion(0,"question2", "answer2"));
    question = mc ->getQuestion(1);
    BOOST_CHECK (question == nullptr);
    test = mc ->getCurrentlyEditedTest();
    BOOST_CHECK (test);

    mc ->endCreatingNewTest();
    mc -> logoutUser();
//    mc -> deleteConcreteTest(" ");
    mc -> deleteUser(name);
    BOOST_REQUIRE_THROW(mc ->deleteUser(name), MainClassException);
    mc -> ~MainClass();

}



