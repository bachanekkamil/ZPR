#include <logic/database.h>
#include <logic/database_exception.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QDateTime>
#include <logic/questionproxy.h>

int DbManager::ilosc=0;

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

    ilosc++;
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

unsigned int DbManager::addUser(const QString& name)
{
    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Users (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

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

std::shared_ptr<User> DbManager::getUser(unsigned int id)
{
    if (id > 0)
    {
        if(all_users.size() > 0)
        {
            foreach (std::shared_ptr<User> us, all_users) {
                if(us->getIdDb() == id)
                    return us;
            }
        }
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
    if(all_users.size() > 0)
        return all_users;
    QSqlQuery queryGet;
    queryGet.prepare("Select name, datetime_created, id FROM Users");
    if(!queryGet.exec())
    {
        throw DatabaseException(queryGet.lastError().text().toStdString().c_str());
    }
    while (queryGet.next())
    {
        QString name = queryGet.value(0).toString();
        QString date = queryGet.value(1).toString();
        unsigned int id = queryGet.value(2).toUInt();
        QString format = "yyyy-MM-dd HH:mm:ss";
        QDateTime dt = QDateTime::fromString(date, format);
        std::shared_ptr<User> us(new User (name, id, dt));
        all_users.push_back(us);
    }
    return all_users;
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

unsigned int DbManager::addTest(const QString& name, const std::shared_ptr<User> user)
{
    if (!name.isEmpty() && user)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Tests(name, user_who_made) VALUES (:name, :user_who_made)");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":user_who_made", user->getIdDb());

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
        QSqlDatabase::database().rollback();
        throw DatabaseException(error_type::PASSED_NULL_PARAMETER);
    }
}
