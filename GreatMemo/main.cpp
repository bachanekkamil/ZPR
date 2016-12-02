#include "mainwindow.h"
#include "database.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    Database* db = new Database();
    db->createTable("oj", "database");
    db->insertValue("database","oj","dog","pies");
    db->displayTable("database","oj");
//    w.show();

    return a.exec();
}
