#include "GUI/newtestname.h"
#include "ui_newtestname.h"
#include "logic/mainclass.h"
#include "logic/mainclassexception.h"
#include <QDesktopWidget>

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
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
            int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
            mWarningMessageDialog->move(x, y);
            mWarningMessageDialog->show();
        }
    }
}

void NewTestName::on_buttonBox_rejected()
{
    this->close();
}
