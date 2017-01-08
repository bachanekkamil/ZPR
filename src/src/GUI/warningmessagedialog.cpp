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
