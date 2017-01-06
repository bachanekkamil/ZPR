#include "GUI/solvetestwindow.h"
#include "ui_solvetestwindow.h"

SolveTestWindow::SolveTestWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolveTestWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);
}

SolveTestWindow::~SolveTestWindow()
{
    delete ui;
}

void SolveTestWindow::on_pushButtonEndTest_clicked()
{
    mPrevious->show();
    this->close();
}

void SolveTestWindow::closeEvent (QCloseEvent *event){
    mPrevious->show();
}
