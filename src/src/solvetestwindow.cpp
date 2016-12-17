#include "solvetestwindow.h"
#include "ui_solvetestwindow.h"

SolveTestWindow::SolveTestWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolveTestWindow)
{
    this->previous=previous;
    ui->setupUi(this);
}

SolveTestWindow::~SolveTestWindow()
{
    delete ui;
}

void SolveTestWindow::on_pushButton_zakoncz_test_clicked()
{
    previous->show();
    this->close();
}
