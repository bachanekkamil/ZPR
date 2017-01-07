#include "GUI/secondwindow.h"
#include "ui_secondwindow.h"
#include "logic/mainclass.h"

SecondWindow::SecondWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete mSolveTestWindow;
    delete mNewTestName;
    delete mAddNewTestWindow;
    delete mEditTestWindow;
    delete ui;
}

void SecondWindow::newTestAdded(){
    mAddNewTestWindow = new AddNewTestWindow(this);
    mAddNewTestWindow->show();
    this->hide();
}

void SecondWindow::on_pushButtonTakeTest_clicked()
{
    mSolveTestWindow = new SolveTestWindow(this);
    mSolveTestWindow->show();
    this->hide();
}

void SecondWindow::on_pushButtonTakeNewTest_clicked()
{
    on_pushButtonTakeTest_clicked();
}

void SecondWindow::on_actionLogout_triggered()
{
    MainClass *main_class=MainClass::getInstance();
    main_class->logoutUser();
    mPrevious->show();
    this->close();
}

void SecondWindow::on_pushButtonAddTest_clicked()
{
    mNewTestName = new NewTestName(this);
    QObject::connect(mNewTestName, SIGNAL(newTestNameAccepted()), this, SLOT(newTestAdded()));
    mNewTestName->show();
}

void SecondWindow::on_pushButtonEditTest_clicked()
{
    mEditTestWindow = new AddNewTestWindow(this);
    mEditTestWindow->show();
    this->hide();
}
