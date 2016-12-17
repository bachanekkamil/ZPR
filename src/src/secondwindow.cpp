#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    this->previous=previous;
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    solveTestWindow = new SolveTestWindow(this);
    solveTestWindow->show();
    this->hide();
}

void SecondWindow::on_actionLogout_triggered()
{
    previous->show();
    this->close();
}

void SecondWindow::on_pushButton_dodaj_test_clicked()
{
    newTestName = new NewTestName(this);
    newTestName->show();
    this->hide();
}

void SecondWindow::on_pushButton_edytuj_test_clicked()
{
    editTestWindow = new AddNewTestWindow(this);
    editTestWindow->show();
    this->hide();
}
