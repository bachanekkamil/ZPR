#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"

AddNewUserWindow::AddNewUserWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewUserWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

AddNewUserWindow::~AddNewUserWindow()
{
    delete ui;
}

void AddNewUserWindow::on_pushButtonAddNewUser_clicked()
{
    mPrevious->show();
    this->close();
}
