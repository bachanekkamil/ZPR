#include "GUI/secondwindow.h"
#include "ui_secondwindow.h"

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
    delete mEditTestWindow;
    delete mEditUserWindow;
    delete ui;
}

void SecondWindow::on_pushButtonTakeTest_clicked()
{
    mSolveTestWindow = new SolveTestWindow(this);
    mSolveTestWindow->show();
    this->hide();
}

void SecondWindow::on_actionLogout_triggered()
{
    mPrevious->show();
    this->close();
}

void SecondWindow::on_actionEditUserInfo_triggered()
{
    mEditUserWindow = new EditUserWindow(this);
    mEditUserWindow->show();
    this->hide();
}

void SecondWindow::on_pushButtonAddTest_clicked()
{
    mNewTestName = new NewTestName(this);
    mNewTestName->show();
    this->hide();
}

void SecondWindow::on_pushButtonEditTest_clicked()
{
    mEditTestWindow = new AddNewTestWindow(this);
    mEditTestWindow->show();
    this->hide();
}
