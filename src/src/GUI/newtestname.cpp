#include "GUI/newtestname.h"
#include "ui_newtestname.h"
#include "logic/mainclass.h"
#include "logic/mainclassexception.h"


NewTestName::NewTestName(QMainWindow *previous, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTestName)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

NewTestName::~NewTestName()
{
    delete mWarningMessageDialog;
    delete ui;
}

void NewTestName::on_buttonBox_accepted()
{
    if(!ui->lineEditTestName->text().isEmpty()){
        MainClass *main_class=MainClass::getInstance();
        try{
            main_class->addNewTest(ui->lineEditTestName->text());
            emit newTestNameAccepted();
            this->close();
        }catch(MainClassException &e){
            mWarningMessageDialog = new WarningMessageDialog("Nie udało się dodać testu do bazy.");
            mWarningMessageDialog->show();
        }
    }
}

void NewTestName::on_buttonBox_rejected()
{
    this->close();
}
