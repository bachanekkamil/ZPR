#include <logic/database.h>
#include <logic/database_exception.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include <QDateTime>
#include <logic/questionproxy.h>
#include <logic/mainclass.h>


DbManager* DbManager::mInstance = nullptr;

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("db_test.db");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection okk";
    }
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");
    query.exec();


}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

std::shared_ptr<User> DbManager::addUser(const QString& name)
{
    if (!name.isEmpty())
    {
        QSqlQuery queryAdd(m_db);
        queryAdd.prepare("INSERT INTO Users (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            return getUser(getLastInsertedRowId());
        }
        else
        {
            throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
}

std::shared_ptr<User> DbManager::getUser(unsigned int id)
{
    if (id > 0)
    {
        QSqlQuery queryGet;
        queryGet.prepare("Select name, datetime_created FROM Users WHERE id = :id");
        queryGet.bindValue(":id", QString::number(id));

        if(queryGet.exec())
        {
            if(queryGet.next())
            {
                QString name = queryGet.value(0).toString();
                QString date = queryGet.value(1).toString();
                QString format = "yyyy-MM-dd HH:mm:ss";
                QDateTime dt = QDateTime::fromString(date, format);
                std::shared_ptr<User> us(new User (name, id, dt));
                return us;
            }
            else
            {
                throw DatabaseException(error_type::ROW_NOT_FOUND);
            }
        }
        else
        {
            throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_WRONG_ID);
    }
}


void DbManager::removeUser(const QString& name)
{
    if (isUserExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Users WHERE name = (:name)");
        queryDelete.bindValue(":name", name);

        if(!queryDelete.exec())
        {
            throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::ROW_NOT_FOUND);
    }
}

void DbManager::removeUser(unsigned int id)
{
    if (isUserExists(id))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Users WHERE id = (:id)");
        queryDelete.bindValue(":id", id);

        if(!queryDelete.exec())
        {
            throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::ROW_NOT_FOUND);
    }
}

std::vector<std::shared_ptr<User>> DbManager::getAllUsers()
{
    QSqlQuery queryGet;
    queryGet.prepare("Select name, datetime_created, id FROM Users");
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    std::vector<std::shared_ptr<User>> users;
    while (queryGet.next())
    {
        QString name = queryGet.value(0).toString();
        QString date = queryGet.value(1).toString();
        unsigned int id = queryGet.value(2).toUInt();
        QString format = "yyyy-MM-dd HH:mm:ss";
        QDateTime dt = QDateTime::fromString(date, format);
        std::shared_ptr<User> us(new User (name, id, dt));
        users.push_back(us);
    }
    return users;
}

bool DbManager::isUserExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM Users WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        throw DatabaseException(checkQuery.lastError().text().toStdString().c_str());
    }

    return exists;
}

bool DbManager::isUserExists(unsigned int id)
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM Users WHERE id = (:id)");
    checkQuery.bindValue(":id", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        throw DatabaseException(checkQuery.lastError().text().toStdString().c_str());
    }

    return exists;
}


void DbManager::removeAllUsers()
{
    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM Users");

    if (!removeQuery.exec())
    {
        throw DatabaseException(removeQuery.lastError().text().toStdString().c_str());
    }
}

unsigned int DbManager::getLastInsertedRowId()
{
    QSqlQuery queryGet;
    queryGet.prepare("SELECT last_insert_rowid()");

    if(queryGet.exec())
    {
        if(queryGet.next())
        {
            unsigned int id = queryGet.value(0).toUInt();
            return id;
        }
        else
        {
            throw DatabaseException(error_type::ROW_NOT_FOUND);
        }
    }
    else
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
}

std::shared_ptr<Test> DbManager::addTest(const QString& name, const std::shared_ptr<User> user)
{
    if (!name.isEmpty() && user)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Tests(name, user_who_made) VALUES (:name, :user_who_made)");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":user_who_made", user->getIdDb());

        if(queryAdd.exec())
        {
            unsigned int idd = getLastInsertedRowId();
            std::shared_ptr<Test> test(new Test (idd , name, user, getAllQuestionForTest(idd)));
            return test;
        }
        else
        {
            throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
}

std::vector<std::shared_ptr<Test>> DbManager::getAllTests()
{
    QSqlQuery queryGet;
    queryGet.prepare("Select name, user_who_made, id FROM Tests");
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    std::vector<std::shared_ptr<Test>> vec;
    while (queryGet.next())
    {
        QString name = queryGet.value(0).toString();
        unsigned int user_id = queryGet.value(1).toUInt();
        unsigned int id = queryGet.value(2).toUInt();
        std::shared_ptr<Test> test(new Test (id, name, getUser(user_id), getAllQuestionForTest(id)));
        vec.push_back(test);
    }
    return vec;
}

std::shared_ptr<Question> DbManager::getRealQuestion(unsigned long long id)
{
    if (id > 0)
    {
        QSqlQuery queryGet;
        queryGet.prepare("Select id, question_text, correct_answer FROM Questions WHERE id = :id");
        queryGet.bindValue(":id", id);

        if(queryGet.exec())
        {
            if(queryGet.next())
            {
                unsigned long long id = queryGet.value(0).toLongLong();
                QString text = queryGet.value(1).toString();
                QString correct_answer = queryGet.value(2).toString();
                std::shared_ptr<Question> us(new QuestionReal(id, correct_answer, text));
                return us;
            }
            else
            {
                throw DatabaseException(error_type::ROW_NOT_FOUND);
            }
        }
        else
        {
            throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_WRONG_ID);
    }
}

std::vector<std::shared_ptr<Question>> DbManager::getAllQuestionForTest(unsigned int id)
{
    if (id <= 0)
    throw DatabaseException(error_type::PASSED_WRONG_ID);

    std::vector<std::shared_ptr<Question>> all_questions;
    QSqlQuery queryGet;
    queryGet.prepare("Select id FROM Questions WHERE test_id = :test_id");
    queryGet.bindValue(":test_id", id);
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    while (queryGet.next())
    {
        unsigned int id_question = queryGet.value(0).toUInt();
        std::shared_ptr<Question> que(new QuestionProxy (id_question));
        all_questions.push_back(que);
    }
    return all_questions;
}

unsigned int DbManager::addQuestionAndAnswer(std::shared_ptr<Test> test, QString& question_text, QString& answer_text)
{
    if (!question_text.isEmpty() && test)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Questions(question_text, test_id, correct_answer) VALUES (:text, :test_id, :correct_answer)");
        queryAdd.bindValue(":text", question_text);
        queryAdd.bindValue(":test_id", test->getIdDb());
        queryAdd.bindValue(":correct_answer", answer_text);

        if(queryAdd.exec())
        {
            return getLastInsertedRowId();
        }
        else
        {
            throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
}

void DbManager::modifyQuestion(std::shared_ptr<Question> question, QString& question_text, QString& answer_text)
{
    if (question_text.isEmpty() || answer_text.isEmpty() || !question)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
    QSqlQuery queryUpdate;
    queryUpdate.prepare("UPDATE Questions SET question_text = :question_text, correct_answer = :answer_text WHERE id = :id");
    queryUpdate.bindValue(":question_text", question_text);
    queryUpdate.bindValue(":answer_text", answer_text);
    queryUpdate.bindValue(":id", question->getIdDb());
    if(queryUpdate.exec())
    {
        return;
    }
    else
    {
        throw DatabaseException(queryUpdate.lastError().text().toStdString().c_str());
    }
}

void DbManager::deleteQuestion(std::shared_ptr<Question> question)
{
    if (!question)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM Questions WHERE id = :id");
    queryDelete.bindValue(":id", question->getIdDb());
    if(queryDelete.exec())
    {
        return;
    }
    else
    {
        throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
    }
}

void DbManager::deleteTest(std::shared_ptr<Test> test)
{
    if (!test)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
    m_db.transaction();
    try
    {
        deleteAllQuestionsForTest(test);
    }
    catch(DatabaseException &e)
    {
        m_db.rollback();
        throw DatabaseException(e.what());
    }

    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM Tests WHERE id = :id");
    queryDelete.bindValue(":id", test->getIdDb());
    if(queryDelete.exec())
    {
        m_db.commit();
        return;
    }
    else
    {
        throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
    }
}

void DbManager::modifyTest(std::shared_ptr<Test> test, const QString& name)
{
    if (name.isEmpty() || !test)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
    QSqlQuery queryUpdate;
    queryUpdate.prepare("UPDATE Tests SET name = :test_name WHERE id = :id");
    queryUpdate.bindValue(":test_name", name);
    queryUpdate.bindValue(":id", test->getIdDb());
    if(queryUpdate.exec())
    {
        return;
    }
    else
    {
        throw DatabaseException(queryUpdate.lastError().text().toStdString().c_str());
    }
}

void DbManager::deleteAllQuestionsForTest(std::shared_ptr<Test> test)
{
    if (!test)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM Questions WHERE test_id = :id");
    queryDelete.bindValue(":id", test->getIdDb());
    if(queryDelete.exec())
    {
        return;
    }
    else
    {
        throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
    }
}

std::shared_ptr<ConcreteTest> DbManager::addConcreteTest(const QString& name, const std::shared_ptr<User> user, const std::shared_ptr<Test> test)
{
    if (!name.isEmpty() && user)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO ConcreteTests(test_id, user_who_started, name) VALUES(:test_id, :user_who_made, :name)");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":user_who_made", user->getIdDb());
        queryAdd.bindValue(":test_id", test->getIdDb());

        if(queryAdd.exec())
        {
            unsigned int idd = getLastInsertedRowId();
            std::vector<std::shared_ptr<OldUserAnswer>> logs;
            std::shared_ptr<ConcreteTest> contest(new ConcreteTest(idd, test, user, name, QDateTime::currentDateTimeUtc(), logs));
            return contest;
        }
        else
        {
            throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
}

std::vector<std::shared_ptr<ConcreteTest>> DbManager::getAllConcreteTests()
{
    QSqlQuery queryGet;
    queryGet.prepare("SELECT id, test_id, user_who_started, name, datetime_created FROM ConcreteTests");
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    std::vector<std::shared_ptr<ConcreteTest>> concTests;
    while (queryGet.next())
    {
        unsigned int id = queryGet.value(0).toUInt();
        unsigned int test_id = queryGet.value(1).toUInt();
        unsigned int user_id = queryGet.value(2).toUInt();
        QString name = queryGet.value(3).toString();
        QString date = queryGet.value(4).toString();
        QString format = "yyyy-MM-dd HH:mm:ss";
        QDateTime dt = QDateTime::fromString(date, format);
        std::shared_ptr<ConcreteTest> contest(new ConcreteTest(id, MainClass::getInstance()->getTest(test_id), MainClass::getInstance()->getUser(user_id), name, dt, getLogsForConcreteTests(id)));
        concTests.push_back(contest);
    }
    return concTests;
}

void DbManager::deleteConcreteTest(std::shared_ptr<ConcreteTest> test)
{
    if (!test)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }

    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM ConcreteTests WHERE id = :id");
    queryDelete.bindValue(":id", test->getIdDb());
    if(queryDelete.exec())
    {
        return;
    }
    else
    {
        throw DatabaseException(queryDelete.lastError().text().toStdString().c_str());
    }
}

void DbManager::modifyConcreteTest(std::shared_ptr<ConcreteTest> test, const QString& name)
{
    if (name.isEmpty() || !test)
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
    QSqlQuery queryUpdate;
    queryUpdate.prepare("UPDATE ConcreteTests SET name = :test_name WHERE id = :id");
    queryUpdate.bindValue(":test_name", name);
    queryUpdate.bindValue(":id", test->getIdDb());
    if(queryUpdate.exec())
    {
        return;
    }
    else
    {
        throw DatabaseException(queryUpdate.lastError().text().toStdString().c_str());
    }
}

std::shared_ptr<OldUserAnswer> DbManager::addAnswerToLogs(std::shared_ptr<ConcreteTest> conc_test, std::shared_ptr<Question> quest, unsigned short grade)
{

    if (conc_test && quest && grade >= 0)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Logs(question_id, concrete_test_id, grade) VALUES(:question_id, :concrete_test_id, :grade)");
        queryAdd.bindValue(":concrete_test_id", conc_test->getIdDb());
        queryAdd.bindValue(":question_id", quest->getIdDb());
        queryAdd.bindValue(":grade", grade);

        if(queryAdd.exec())
        {
            std::shared_ptr<OldUserAnswer> oua(new OldUserAnswer(getLastInsertedRowId(), QDateTime::currentDateTimeUtc(), quest, grade));
            return oua;
        }
        else
        {
            throw DatabaseException(queryAdd.lastError().text().toStdString().c_str());
        }
    }
    else
    {
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }

}



std::vector<std::shared_ptr<OldUserAnswer>> DbManager::getLogsForConcreteTests(unsigned int concreteTestId)
{
    if (concreteTestId <= 0)
    throw DatabaseException(error_type::PASSED_WRONG_ID);

    QSqlQuery queryGet;
    queryGet.prepare("SELECT id, question_id, grade, datetime_created FROM Logs WHERE concrete_test_id = :test_id");
    queryGet.bindValue(":test_id", concreteTestId);
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    std::vector<std::shared_ptr<OldUserAnswer>> allAnswers;
    while (queryGet.next())
    {
        unsigned int id_log = queryGet.value(0).toUInt();
        long long id_question = queryGet.value(1).toLongLong();
        unsigned short grade = queryGet.value(2).toUInt();
        QString dt_string = queryGet.value(3).toString();
        QString format = "yyyy-MM-dd HH:mm:ss";
        QDateTime dt = QDateTime::fromString(dt_string, format);
        std::shared_ptr<Question> quest = MainClass::getInstance()->getQuestion(id_question);
        if(!quest)
            throw DatabaseException("Didn't find question for that answer in memory.");
        std::shared_ptr<OldUserAnswer> oua(new OldUserAnswer(id_log, dt, quest, grade));
        allAnswers.push_back(oua);
    }
    return allAnswers;
}

std::vector<std::shared_ptr<OldUserAnswer>> DbManager::getLogsForConcreteTests(std::shared_ptr<ConcreteTest> conc_test)
{
    return getLogsForConcreteTests(conc_test->getIdDb());
}

