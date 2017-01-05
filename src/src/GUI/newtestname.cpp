#include "GUI/newtestname.h"
#include "ui_newtestname.h"

NewTestName::NewTestName(QMainWindow *previous, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTestName)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

NewTestName::~NewTestName()
{
    delete mAddNewTestWindow;
    delete ui;
}

void NewTestName::on_buttonBox_accepted()
{
    mAddNewTestWindow = new AddNewTestWindow(mPrevious);
    mAddNewTestWindow->show();
    this->close();
}

void NewTestName::on_buttonBox_rejected()
{
    mPrevious->show();
    this->close();
}
