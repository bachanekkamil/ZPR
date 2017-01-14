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

    ui->tableWidgetChooseAvaliableTest->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetChooseAvaliableTest->verticalHeader()->setVisible(false);
    ui->tableWidgetChooseAvaliableTest->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetChooseAvaliableTest->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableWidgetChooseMyTest->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetChooseMyTest->verticalHeader()->setVisible(false);
    ui->tableWidgetChooseMyTest->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetChooseMyTest->setSelectionMode(QAbstractItemView::SingleSelection);

    MainClass *main_class=MainClass::getInstance();
    QStringList tests_list=main_class->getAvailableTests();

    qDebug() << "Second window, list.length()" << tests_list.length();
    qDebug() << "Second window, getAvailableTests()" << tests_list;
    ui->tableWidgetChooseAvaliableTest->setRowCount(tests_list.length());
    ui->tableWidgetChooseAvaliableTest->setColumnCount(1);
    QStringList test_table_labels;
    test_table_labels << "Nazwa testu";
    ui->tableWidgetChooseAvaliableTest->setHorizontalHeaderLabels(test_table_labels);

    QStringList::const_iterator it;
    int i=0;
    for (it = tests_list.constBegin(); it != tests_list.constEnd(); ++it){
        QTableWidgetItem *item= new QTableWidgetItem((*it).toLocal8Bit().constData());
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->tableWidgetChooseAvaliableTest->setItem(i,0, item);
        //ui->tableWidgetChooseAvaliableTest->setItem(i,0, new QTableWidgetItem((*it).toLocal8Bit().constData()));
        ++i;
    }


    QStringList concrete_tests_list=main_class->getAvailableConcreteTests();

    qDebug() << "Second window, concrete_tests_list.length()" << concrete_tests_list.length();
    qDebug() << "Second window, getAvailableConcreteTests()" << concrete_tests_list;
    ui->tableWidgetChooseMyTest->setRowCount((concrete_tests_list.length()/2));
    ui->tableWidgetChooseMyTest->setColumnCount(2);
    QStringList concrete_test_table_labels;
    concrete_test_table_labels << "Nazwa testu" << "Data utworzenia";
    ui->tableWidgetChooseMyTest->setHorizontalHeaderLabels(concrete_test_table_labels);

    i=0;
    for (it = concrete_tests_list.constBegin(); it != concrete_tests_list.constEnd(); ++it){
        ui->tableWidgetChooseMyTest->setItem(i,0, new QTableWidgetItem((*it).toLocal8Bit().constData()));
        ++it;
        ui->tableWidgetChooseMyTest->setItem(i,1, new QTableWidgetItem((*it).toLocal8Bit().constData()));
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
    QModelIndex index= ui->tableWidgetChooseAvaliableTest->currentIndex();
    if(index.row()!=-1){
        MainClass *main_class=MainClass::getInstance();
        main_class->addNewConcreteTest(ui->tableWidgetChooseAvaliableTest->item(index.row(),0)->text());

        QStringList concrete_tests_list=main_class->getAvailableConcreteTests();

        ui->tableWidgetChooseMyTest->setRowCount((concrete_tests_list.length()/2));
        ui->tableWidgetChooseMyTest->setColumnCount(2);

        QStringList::const_iterator it;
        int i=0;
        for (it = concrete_tests_list.constBegin(); it != concrete_tests_list.constEnd(); ++it){
            ui->tableWidgetChooseMyTest->setItem(i,0, new QTableWidgetItem((*it).toLocal8Bit().constData()));
            ++it;
            ui->tableWidgetChooseMyTest->setItem(i,1, new QTableWidgetItem((*it).toLocal8Bit().constData()));
            ++i;
        }

        mSolveTestWindow = new SolveTestWindow(this);
        mSolveTestWindow->show();
        this->hide();
    }else{
        mWarningMessageDialog = new WarningMessageDialog("Nie wybrano testu do rozwiązania!");
        mWarningMessageDialog->show();
    }
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
    this->hide();
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
