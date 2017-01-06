#ifndef DATABASE_EXCEPTION_H
#define DATABASE_EXCEPTION_H

#include <QtSql/QSqlDatabase>
#include <exception>
#include <iostream>

enum error_type
{
    PASSED_NULL_PARAMETER,
    PASSED_WRONG_ID,
    ROW_NOT_FOUND
};

class DatabaseException : public std::exception
{
public:
    DatabaseException(const char* error);


    DatabaseException(error_type err);

    virtual const char *what() const noexcept override;


private:
   static char* TEXT_PASSED_NULL_PARAMETER;
   static char* TEXT_PASSED_WRONG_ID;
   static char* TEXT_ROW_NOT_FOUND;

private:
   char* text;
};

#endif // DATABASE_EXCEPTION_H
