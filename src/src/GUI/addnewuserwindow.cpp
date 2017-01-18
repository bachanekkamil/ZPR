//!
/*!
  \brief Contains class method implementation which enables adding new user
  \author Aleksandra Grzegorczyk
*/
#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"
#include "logic/mainclass.h"
#include "logic/mainclassexception.h"
#include <QDesktopWidget>
#include<QDebug>

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
    delete mWarningMessageDialog;
    delete ui;
}

void AddNewUserWindow::on_pushButtonAddNewUser_clicked()
{
    if(!ui->lineEditLogin->text().isEmpty()){
        MainClass *main_class=MainClass::getInstance();
        try{
            main_class->addNewUser(ui->lineEditLogin->text());
            emit newUserAdded();
            mPrevious->show();
            this->close();
        }catch(MainClassException &e){
            qDebug() << "Exception " << e.what();
            mWarningMessageDialog = new WarningMessageDialog("Nie udało się dodać użytkownika do bazy.");
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
            int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
            mWarningMessageDialog->move(x, y);
            mWarningMessageDialog->show();
        }
    }else{
        mWarningMessageDialog = new WarningMessageDialog("Puste pole login! Proszę podać login nowego użytkownika.");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
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
