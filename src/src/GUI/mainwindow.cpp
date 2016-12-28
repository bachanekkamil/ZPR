#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include "logic/answer.h"
#include "logic/database.h"
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
    db.addUser("Kamil");

    db.getAllUsers();

    if(db.isUserExists(1))
    qDebug() << "User exists";

    if(db.removeUser("Kamil"))
            qDebug() << "User deleted";


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
