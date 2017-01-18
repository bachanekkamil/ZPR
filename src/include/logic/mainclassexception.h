//!
/*!
  \brief Class for exceptions occuring in MainClass
  \author Aleksandra Grzegorczyk
*/

#ifndef MAINCLASSEXCEPTION_H
#define MAINCLASSEXCEPTION_H


#include <exception>
#include <iostream>
#include <cstring>

//! ErrorTypeMainClass enum
/*!
    Enum for error types
*/

enum ErrorTypeMainClass
{
    MAIN_CLASS_EXCEPTION
};

//!  MainClassException
/*!
  Class for MainClass exceptions
*/

class MainClassException : public std::exception
{
public:
    //! \brief MainClassException
    /*!
      \param error error text
    */
    MainClassException(const char* error);

    //!  MainClassException Constructor
    /*!
      \param error error type
    */
    MainClassException(ErrorTypeMainClass err);

    //!  what method
    /*!
      \return error text
    */
    virtual const char *what() const noexcept override;


private:
   static char* TEXT_MAIN_CLASS_EXCEPTION;

private:
   char* text;
};


#endif // MAINCLASSEXCEPTION_H
