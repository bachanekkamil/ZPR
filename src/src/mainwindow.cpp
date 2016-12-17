#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include "answer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	Answer ans("sda",0);

    ans.getIdDb();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    window2 = new SecondWindow(this);
    window2->show();
    this->hide();
}
