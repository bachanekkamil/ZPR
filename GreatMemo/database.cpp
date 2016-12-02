#include "database.h"
using namespace std;


Database::Database()
{

}

int Database::createTable(const std::string& tableName, const std::string& databaseName){

    openDatabase(databaseName);

    char *error;
    std::string sqlCreateTable = "CREATE TABLE " + std::string(tableName) + "(id INTEGER PRIMARY KEY,ang STRING, pol STRING);";

    const char *createTableChar = sqlCreateTable.c_str();
    rc = sqlite3_exec(db, createTableChar, NULL, NULL, &error);

    if (rc)
    {
       cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(db) << endl << endl;
       sqlite3_free(error);
    }
    else
    {
       cout << "Table "<<tableName<<" created"<< endl;
    }
    sqlite3_close(db);

}

int Database::openDatabase(const std::string& databaseName){
    rc = sqlite3_open(databaseName.c_str(), &db);
    if( rc ){
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       return(0);
    }
}


int Database::insertValue(const std::string& databaseName, const std::string& tableName, const std::string& value1, const std::string& value2){

    openDatabase(databaseName);
    char *error;
    std::string sqlInsert = "INSERT INTO " +tableName+" VALUES(NULL, '"+value1+"', '" + value2+"');";

    const char *sqlInsertChar = sqlInsert.c_str();
    fprintf(stderr,sqlInsertChar);

    rc = sqlite3_exec(db, sqlInsertChar, NULL, NULL, &error);
    if (rc)
    {
       cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(db) << endl << endl;
       sqlite3_free(error);
    }
    else
    {
       cout << "Inserted a value" << endl << endl;
    }

    sqlite3_close(db);

}

int Database::displayTable(const std::string& databaseName, const std::string& tableName){

    openDatabase(databaseName);
    char *error;

    std::string sqlSelect = "SELECT * FROM " + tableName+";";
    const char *sqlSelectChar = sqlSelect.c_str();
    char **results = NULL;
    int rows, columns;
    sqlite3_get_table(db, sqlSelectChar, &results, &rows, &columns, &error);
    if (rc)
    {
       cerr << "Error executing SQLite3 query: " << sqlite3_errmsg(db) << endl << endl;
       sqlite3_free(error);
    }
    else
    {
       // Display Table
       for (int rowCtr = 0; rowCtr <= rows; ++rowCtr)
       {
          for (int colCtr = 0; colCtr < columns; ++colCtr)
          {
             // Determine Cell Position
             int cellPosition = (rowCtr * columns) + colCtr;

             // Display Cell Value
             cout.width(12);
             cout.setf(ios::left);
             cout << results[cellPosition] << " ";
          }

          // End Line
          cout << endl;

          // Display Separator For Header
          if (0 == rowCtr)
          {
             for (int colCtr = 0; colCtr < columns; ++colCtr)
             {
                cout.width(12);
                cout.setf(ios::left);
                cout << "~~~~~~~~~~~~ ";
             }
             cout << endl;
          }
       }
    }
    sqlite3_free_table(results);

    sqlite3_close(db);

}
