#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mSecondWindow;
    delete mAddNewUserWindow;
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    mSecondWindow = new SecondWindow(this);
    mSecondWindow->show();
    this->hide();
}

void MainWindow::on_pushButtonAddUser_clicked()
{
    mAddNewUserWindow = new AddNewUserWindow(this);
    mAddNewUserWindow->show();
    this->hide();
}
