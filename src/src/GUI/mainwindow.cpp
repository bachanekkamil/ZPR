#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"
#include "logic/mainclass.h"
#include <QVBoxLayout>

#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainClass main_class=MainClass::getInstance();
    ui->comboBoxChooseUser->addItems(main_class.getAllUsers());
    ui->comboBoxChooseUser->setEditable(false);
}

MainWindow::~MainWindow()
{
    delete mSecondWindow;
    delete mAddNewUserWindow;
    delete ui;
}

void MainWindow::userListChanged(){
    ui->comboBoxChooseUser->clear();
    MainClass main_class=MainClass::getInstance();
    ui->comboBoxChooseUser->addItems(main_class.getAllUsers());
}

void MainWindow::on_pushButtonLogin_clicked()
{
    if(ui->comboBoxChooseUser->count()!=0 && ui->comboBoxChooseUser->currentIndex()!=-1){
        MainClass main_class=MainClass::getInstance();
        main_class.setUser(ui->comboBoxChooseUser->currentIndex());
        mSecondWindow = new SecondWindow(this);
        mSecondWindow->show();
        this->hide();
    }
}

void MainWindow::on_pushButtonDeleteUser_clicked()
{
    if(ui->comboBoxChooseUser->count()!=0 && ui->comboBoxChooseUser->currentIndex()!=-1){
        MainClass main_class=MainClass::getInstance();
        main_class.deleteUser(ui->comboBoxChooseUser->currentIndex());
        userListChanged();
    }
}

void MainWindow::on_pushButtonAddUser_clicked()
{
    mAddNewUserWindow = new AddNewUserWindow(this);
    QObject::connect(mAddNewUserWindow, SIGNAL(newUserAdded()), this, SLOT(userListChanged()));
    mAddNewUserWindow->show();
    this->hide();
}
