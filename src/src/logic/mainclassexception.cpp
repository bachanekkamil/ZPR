#include "logic/mainclassexception.h"

char* MainClassException::TEXT_MAIN_CLASS_EXCEPTION = "Main class exception";


MainClassException::MainClassException(const char* error)
{
     text = new char[strlen(error) + 1];
     strcpy_s(text, 1000, error);
}

MainClassException::MainClassException(ErrorTypeMainClass err)
{
     switch(err)
     {
        case MAIN_CLASS_EXCEPTION:
            text = TEXT_MAIN_CLASS_EXCEPTION;
            break;
        default:
            text = "Unkown error";
     }
}

const char* MainClassException::what() const noexcept
{
       return text;
}
