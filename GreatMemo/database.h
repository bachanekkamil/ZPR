#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>


class Database
{
public:
    Database();
    int openDatabase(const std::__cxx11::string &databaseName);
    int createTable(const std::__cxx11::string &, const std::__cxx11::string &databaseName);
    int insertValue(const std::__cxx11::string& databaseName, const std::__cxx11::string& tableName,
                    const std::__cxx11::string& value1, const std::__cxx11::string& value2);
    int displayTable(const std::__cxx11::string& databaseName, const std::__cxx11::string& tableName);

private:
    sqlite3 *db;
    int rc;

};

#endif // DATABASE_H


