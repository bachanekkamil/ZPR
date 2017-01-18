//!
/*!
  \brief Contains class method implementation which enables showing warnings messages
  \author Aleksandra Grzegorczyk
*/
#include "warningmessagedialog.h"
#include "ui_warningmessagedialog.h"

WarningMessageDialog::WarningMessageDialog(QString message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningMessageDialog)
{
    ui->setupUi(this);
    ui->labelWarningMessage->setText(message);
}

WarningMessageDialog::~WarningMessageDialog()
{
    delete ui;
}

void WarningMessageDialog::on_pushButtonOk_clicked(){
    this->close();
}
