#include "GUI/secondwindow.h"
#include "ui_secondwindow.h"
#include "logic/mainclass.h"
#include <QDebug>


SecondWindow::SecondWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);
    MainClass *main_class=MainClass::getInstance();
    QStringList list=main_class->getAvailableTests();
    qDebug() << "Second window, list.length()" << list.length();
    qDebug() << "Second window, getAvailableTests()" << list;
    ui->tableWidgetChooseAvaliableTest->setRowCount(list.length());
    ui->tableWidgetChooseAvaliableTest->setColumnCount(1);
    QStringList labels;
    labels << "Nazwa testu";
    ui->tableWidgetChooseAvaliableTest->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetChooseAvaliableTest->setHorizontalHeaderLabels(labels);
    ui->tableWidgetChooseAvaliableTest->verticalHeader()->setVisible(false);
    ui->tableWidgetChooseAvaliableTest->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetChooseAvaliableTest->setSelectionMode(QAbstractItemView::SingleSelection);

    QStringList::const_iterator constIterator;
    int i=0;
    for (constIterator = list.constBegin(); constIterator != list.constEnd(); ++constIterator){
        ui->tableWidgetChooseAvaliableTest->setItem(i,0, new QTableWidgetItem((*constIterator).toLocal8Bit().constData()));
        ++i;
    }

}

SecondWindow::~SecondWindow()
{
    delete mSolveTestWindow;
    delete mNewTestName;
    delete mAddNewTestWindow;
    delete mEditTestWindow;
    delete mWarningMessageDialog;
    delete ui;
}

void SecondWindow::newTestAdded(){
    MainClass *main_class=MainClass::getInstance();
    QStringList list=main_class->getAvailableTests();
    ui->tableWidgetChooseAvaliableTest->setRowCount(0);
    ui->tableWidgetChooseAvaliableTest->setRowCount(list.length());
    QStringList::const_iterator constIterator;
    int i=0;
    for (constIterator = list.constBegin(); constIterator != list.constEnd(); ++constIterator){
        ui->tableWidgetChooseAvaliableTest->setItem(i,0, new QTableWidgetItem((*constIterator).toLocal8Bit().constData()));
        ++i;
    }

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
    QModelIndex index= ui->tableWidgetChooseAvaliableTest->currentIndex();
    if(index.row()!=-1){
        MainClass *main_class=MainClass::getInstance();
        main_class->editTest(ui->tableWidgetChooseAvaliableTest->item(index.row(),0)->text());
        mEditTestWindow = new AddNewTestWindow(this);
        mEditTestWindow->show();
        this->hide();
    }else{
        mWarningMessageDialog = new WarningMessageDialog("Nie wybrano testu do edycji!");
        mWarningMessageDialog->show();
    }
}

void SecondWindow::closeEvent (QCloseEvent *event){
    emit exit();
}
