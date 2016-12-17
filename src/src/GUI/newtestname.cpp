#include "GUI/newtestname.h"
#include "ui_newtestname.h"

NewTestName::NewTestName(QMainWindow *previous, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTestName)
{
    this->previous=previous;
    ui->setupUi(this);
}

NewTestName::~NewTestName()
{
    delete ui;
}

void NewTestName::on_buttonBox_accepted()
{
    addNewTestWindow = new AddNewTestWindow(previous);
    addNewTestWindow->show();
    this->close();
}

void NewTestName::on_buttonBox_rejected()
{
    previous->show();
    this->close();
}
