#include "logic/mainclassexception.h"

char* MainClassException::TEXT_MAIN_CLASS_EXCEPTION = "Main class exception";


MainClassException::MainClassException(const char* error)
{
     text = new char[strlen(error) + 1];
     strcpy(text, error);
}

MainClassException::MainClassException(error_type_main_class err)
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
