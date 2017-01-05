#include "edituserwindow.h"
#include "ui_edituserwindow.h"

EditUserWindow::EditUserWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditUserWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

EditUserWindow::~EditUserWindow()
{
    delete ui;
}

void EditUserWindow::on_pushButtonCancel_clicked()
{
    mPrevious->show();
    this->close();
}

void EditUserWindow::on_pushButtonAccept_clicked()
{
    mPrevious->show();
    this->close();
}
