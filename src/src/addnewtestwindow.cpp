#include "addnewtestwindow.h"
#include "ui_addnewtestwindow.h"

AddNewTestWindow::AddNewTestWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewTestWindow)
{
    this->previous=previous;
    ui->setupUi(this);
}

AddNewTestWindow::~AddNewTestWindow()
{
    delete ui;
}

void AddNewTestWindow::on_pushButton_zakoncz_edycje_testu_clicked()
{
    previous->show();
    this->close();
}
