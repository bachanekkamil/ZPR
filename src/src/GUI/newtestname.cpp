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
    delete ui;
}

void NewTestName::on_buttonBox_accepted()
{
    emit newTestNameAccepted();
    this->close();
}

void NewTestName::on_buttonBox_rejected()
{
    this->close();
}
