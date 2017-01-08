#ifndef MAINCLASSEXCEPTION_H
#define MAINCLASSEXCEPTION_H


#include <exception>
#include <iostream>

enum error_type_main_class
{
    MAIN_CLASS_EXCEPTION
};

class MainClassException : public std::exception
{
public:
    MainClassException(const char* error);


    MainClassException(error_type_main_class err);

    virtual const char *what() const noexcept override;


private:
   static char* TEXT_MAIN_CLASS_EXCEPTION;

private:
   char* text;
};


#endif // MAINCLASSEXCEPTION_H
