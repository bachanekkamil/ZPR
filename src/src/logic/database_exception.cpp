#include "logic/database_exception.h"  

char* DatabaseException::TEXT_PASSED_NULL_PARAMETER = "Passed NULL parameter/s";
char* DatabaseException::TEXT_PASSED_WRONG_ID = "Passed wrong ID (<0)";
char* DatabaseException::TEXT_ROW_NOT_FOUND = "Row was not found";


DatabaseException::DatabaseException(const char* error)
{
     text = new char[strlen(error) + 1];
     strcpy(text, error);
}

DatabaseException::DatabaseException(error_type err)
{
     switch(err)
     {
        case PASSED_NULL_PARAMETER:
            text = TEXT_PASSED_NULL_PARAMETER;
            break;
        case PASSED_WRONG_ID:
            text = TEXT_PASSED_WRONG_ID;
            break;
        case ROW_NOT_FOUND:
            text = TEXT_ROW_NOT_FOUND;
            break;
        default:
            text = "Unkown error";
     }
}

const char* DatabaseException::what() const noexcept
{
       return text;
}

