#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include "logic/answer.h"
#include "logic/database.h"
#include <logic/database_exception.h>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	Answer ans("sda",0);

    ans.getIdDb();

    //create db
    DbManager db = DbManager::getInstance("db_test.db");

    //add user test
    try{
    db.addUser("Olson");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }


    if(db.isUserExists(1))
    qDebug() << "User exists";

    db.removeUser("Kamil");
            qDebug() << "User deleted";


    try{
    //add user test
    unsigned int id = db.addUser("Kamil");
    qDebug() << "Added user with id: ";
    qDebug() << QString::number(id);
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }

    try{
    //add user test
    db.addUser("");
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }

    /*/
    try{
    //get user test
    std::shared_ptr<User> us = db.getUser(1);
    qDebug() << "Name: ";
    qDebug() << *us->getName();
    qDebug() << "Time created: ";
    qDebug() << us->getTimeCreated()->toString();
    deq.push_back(us);
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
    }

    qDebug() << "Name: ";
    qDebug() << *deq.at(0)->getName();
    qDebug() << "Time created: ";
    qDebug() << deq.at(0)->getTimeCreated()->toString();
    /*/

    std::vector<std::shared_ptr<User>> vec = db.getAllUsers();
    for(unsigned int i = 0 ; i<vec.size() ; ++i)
    {
        qDebug() << "User: " << *vec.at(i)->getName();
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    window2 = new SecondWindow(this);
    window2->show();
    this->hide();
}
