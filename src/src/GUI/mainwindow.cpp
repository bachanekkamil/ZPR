#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include "logic/answer.h"
#include "logic/database.h"
#include <logic/database_exception.h>
#include <QDebug>
#include <logic/user.h>


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
    db.addUser("Kamil");

    db.getAllUsers();

    if(db.isUserExists(1))
    qDebug() << "User exists";

    if(db.removeUser("Kamil"))
            qDebug() << "User deleted";

    //add user test
    db.addUser("Kamil");

    try{
    //add user test
    db.addUser("Kamil");
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

    try{
    //get user test
    User us = db.getUser(1);
    qDebug() << "Name: ";
    qDebug() << *us.getName();
    }
    catch(DatabaseException& e)
    {
        qDebug() << "Database exception. Do sth";
        qDebug() << e.what();
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
