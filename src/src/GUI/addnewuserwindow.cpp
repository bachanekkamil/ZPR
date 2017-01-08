#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"
#include "logic/mainclass.h"

AddNewUserWindow::AddNewUserWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewUserWindow)
{
    mPrevious=previous;
    ui->setupUi(this);
}

AddNewUserWindow::~AddNewUserWindow()
{
    mPrevious->show();
    delete ui;
}

void AddNewUserWindow::on_pushButtonAddNewUser_clicked()
{
    if(!ui->lineEditLogin->text().isEmpty()){
        MainClass *main_class=MainClass::getInstance();
        main_class->addNewUser(ui->lineEditLogin->text());
        emit newUserAdded();
        mPrevious->show();
        this->close();
    }
}

void AddNewUserWindow::on_pushButtonCancel_clicked()
{
    mPrevious->show();
    this->close();
}

void AddNewUserWindow::closeEvent (QCloseEvent *event){
    mPrevious->show();
}
