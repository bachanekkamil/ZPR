//!
/*!
  \brief Contains DatabaseException Class
  \author Kamil Bachanek
*/


#ifndef DATABASE_EXCEPTION_H
#define DATABASE_EXCEPTION_H

#include <QtSql/QSqlDatabase>
#include <exception>
#include <iostream>

//!  ErrorType Enum
/*!
  Enum for error types
*/
enum ErrorType
{
    PASSED_NULL_PARAMETER,
    PASSED_WRONG_ID,
    ROW_NOT_FOUND
};

//!  DatabaseException Class
/*!
  Class for DB exceptions
*/
class DatabaseException : public std::exception
{
public:
    //!  DatabaseException Constructor
    /*!
      \param error error text
    */
    DatabaseException(const char* error);

    //!  DatabaseException Constructor
    /*!
      \param error error type
    */
    DatabaseException(ErrorType err);

    //!  what method
    /*!
      \return error text
    */
    virtual const char *what() const noexcept override;


private:
   static char* TEXT_PASSED_NULL_PARAMETER;
   static char* TEXT_PASSED_WRONG_ID;
   static char* TEXT_ROW_NOT_FOUND;
   char* text;
};

#endif // DATABASE_EXCEPTION_H
