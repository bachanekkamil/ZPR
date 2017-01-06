#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"

AddNewUserWindow::AddNewUserWindow(QMainWindow *previous, const MainClass& main_class, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewUserWindow)
{
    mPrevious=previous;
    mMainClass=main_class;
    ui->setupUi(this);
}

AddNewUserWindow::~AddNewUserWindow()
{
    delete ui;
}

void AddNewUserWindow::on_pushButtonAddNewUser_clicked()
{
    if(!ui->lineEditLogin->text().isEmpty()){
    mMainClass->addNewUser(ui->lineEditLogin->text());
    mPrevious->show();
    this->close();
    }
}
