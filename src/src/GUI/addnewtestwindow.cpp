#include "GUI/addnewtestwindow.h"
#include "ui_addnewtestwindow.h"

AddNewTestWindow::AddNewTestWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewTestWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

AddNewTestWindow::~AddNewTestWindow()
{
    delete ui;
}

void AddNewTestWindow::on_pushButtonEndTestEditing_clicked()
{
    mPrevious->show();
    this->close();
}

void AddNewTestWindow::closeEvent (QCloseEvent *event){
    mPrevious->show();
}
