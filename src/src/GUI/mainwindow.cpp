#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"
#include "logic/mainclass.h"
#include <QVBoxLayout>
#include <QDebug>
#include "logic/mainclassexception.h"
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainClass *main_class=MainClass::getInstance();
    main_class->Initialize();
    ui->comboBoxChooseUser->addItems(main_class->getAllUsers());
}

MainWindow::~MainWindow()
{
    delete mSecondWindow;
    delete mAddNewUserWindow;
    delete mWarningMessageDialog;
    delete ui;
}

void MainWindow::userListChanged(){
    ui->comboBoxChooseUser->clear();
    MainClass *main_class=MainClass::getInstance();
    ui->comboBoxChooseUser->addItems(main_class->getAllUsers());
}

void MainWindow::exitRequested(){
    this->close();
}

void MainWindow::on_pushButtonLogin_clicked()
{
    if(ui->comboBoxChooseUser->count()!=0 && ui->comboBoxChooseUser->currentIndex()!=-1){
        MainClass *main_class=MainClass::getInstance();
        main_class->setUser(ui->comboBoxChooseUser->currentText());
        mSecondWindow = new SecondWindow(this);
        QObject::connect(mSecondWindow, SIGNAL(exit()), this, SLOT(exitRequested()));
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mSecondWindow->width()) / 2;
        int y = (screenGeometry.height()- mSecondWindow->height()) / 2;
        mSecondWindow->move(x, y);
        mSecondWindow->show();
        this->hide();
    }
}

void MainWindow::on_pushButtonDeleteUser_clicked()
{
    if(ui->comboBoxChooseUser->count()!=0 && ui->comboBoxChooseUser->currentIndex()!=-1){
        MainClass *main_class=MainClass::getInstance();
        try{
            main_class->deleteUser(ui->comboBoxChooseUser->currentText());
            userListChanged();
        }catch(MainClassException &e){
            mWarningMessageDialog = new WarningMessageDialog("Nie udało się usunąć użytkownika z bazy.");
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
            int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
            mWarningMessageDialog->move(x, y);
            mWarningMessageDialog->show();
        }
    }
}

void MainWindow::on_pushButtonAddUser_clicked()
{
    mAddNewUserWindow = new AddNewUserWindow(this);
    QObject::connect(mAddNewUserWindow, SIGNAL(newUserAdded()), this, SLOT(userListChanged()));
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()- mAddNewUserWindow->width()) / 2;
    int y = (screenGeometry.height()- mAddNewUserWindow->height()) / 2;
    mAddNewUserWindow->move(x, y);
    mAddNewUserWindow->show();
    this->hide();
}
