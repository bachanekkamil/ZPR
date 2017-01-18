//!
/*!
  \brief Contains class method implementation used to creating new concreteTests
  \author Aleksandra Grzegorczyk
*/
#include "GUI/secondwindow.h"
#include "ui_secondwindow.h"
#include "logic/mainclass.h"
#include "logic/mainclassexception.h"
#include <QDebug>
#include <QDesktopWidget>

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
        ++i;
    }

    QStringList concrete_test_table_labels;
    concrete_test_table_labels << "Nazwa testu" << "Data następnej powtórki";

    ui->tableWidgetChooseMyTest->setColumnCount(2);
    ui->tableWidgetChooseMyTest->setHorizontalHeaderLabels(concrete_test_table_labels);

    concreteTestsListChanged();

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
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()- mAddNewTestWindow->width()) / 2;
    int y = (screenGeometry.height()- mAddNewTestWindow->height()) / 2;
    mAddNewTestWindow->move(x, y);
    mAddNewTestWindow->show();
    this->hide();
}

void SecondWindow::concreteTestsListChanged(){
    MainClass *main_class=MainClass::getInstance();
    QStringList concrete_tests_list=main_class->getAvailableConcreteTests();

    ui->tableWidgetChooseMyTest->setRowCount((concrete_tests_list.length()/2));

    QStringList::const_iterator it;
    int i=0;
    for (it = concrete_tests_list.constBegin(); it != concrete_tests_list.constEnd(); ++it){
        ui->tableWidgetChooseMyTest->setItem(i,0, new QTableWidgetItem((*it).toLocal8Bit().constData()));
        ++it;
        ui->tableWidgetChooseMyTest->setItem(i,1, new QTableWidgetItem((*it).toLocal8Bit().constData()));
        ++i;
    }
}

void SecondWindow::on_pushButtonTakeTest_clicked()
{
    QModelIndex index= ui->tableWidgetChooseMyTest->currentIndex();
    if(index.row()!=-1){
        try{
            MainClass *main_class=MainClass::getInstance();
            main_class->startConcreteTest(ui->tableWidgetChooseMyTest->item(index.row(),0)->text());
            mSolveTestWindow = new SolveTestWindow(this);
            QObject::connect(mSolveTestWindow, SIGNAL(testTaken()), this, SLOT(concreteTestsListChanged()));
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mSolveTestWindow->width()) / 2;
            int y = (screenGeometry.height()- mSolveTestWindow->height()) / 2;
            mSolveTestWindow->move(x, y);
            mSolveTestWindow->show();
            this->hide();
        }catch (MainClassException &e){
            qDebug() << "Exception " << e.what();
            mWarningMessageDialog = new WarningMessageDialog("Brak pytań na dziś dla wybranego testu!");
            mWarningMessageDialog->show();
        }
    }else{
        mWarningMessageDialog = new WarningMessageDialog("Nie wybrano testu do rozwiązania!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }
}

void SecondWindow::on_pushButtonDeleteTest_clicked(){
    QModelIndex index= ui->tableWidgetChooseMyTest->currentIndex();
    if(index.row()!=-1){
        MainClass *main_class=MainClass::getInstance();
        try{
            main_class->deleteConcreteTest(ui->tableWidgetChooseMyTest->item(index.row(),0)->text());
            concreteTestsListChanged();
        }catch(MainClassException &e){
            qDebug() << "Exception " << e.what();
            mWarningMessageDialog= new WarningMessageDialog("Nie udało się usunąć testu!");
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
            int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
            mWarningMessageDialog->move(x, y);
            mWarningMessageDialog->show();
        }


    }else{
        mWarningMessageDialog = new WarningMessageDialog("Nie wybrano testu do usunięcia!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }
}

void SecondWindow::on_pushButtonTakeNewTest_clicked()
{
    QModelIndex index= ui->tableWidgetChooseAvaliableTest->currentIndex();
    if(index.row()!=-1){
        try{
            MainClass *main_class=MainClass::getInstance();
            try{
                main_class->addNewConcreteTest(ui->tableWidgetChooseAvaliableTest->item(index.row(),0)->text());
                concreteTestsListChanged();
                mSolveTestWindow = new SolveTestWindow(this);
                QObject::connect(mSolveTestWindow, SIGNAL(testTaken()), this, SLOT(concreteTestsListChanged()));
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mSolveTestWindow->width()) / 2;
                int y = (screenGeometry.height()- mSolveTestWindow->height()) / 2;
                mSolveTestWindow->move(x, y);
                mSolveTestWindow->show();
                this->hide();
            }catch(MainClassException &e){
                qDebug() << "Exception " << e.what();
                mWarningMessageDialog= new WarningMessageDialog("Nie udało się stworzyć testu dla użytkownika!");
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                mWarningMessageDialog->move(x, y);
                mWarningMessageDialog->show();
            }

        }catch(MainClassException &e){
            qDebug() << "Exception " << e.what();
            mWarningMessageDialog = new WarningMessageDialog(e.what());
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
            int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
            mWarningMessageDialog->move(x, y);
            mWarningMessageDialog->show();
        }


    }else{
        mWarningMessageDialog = new WarningMessageDialog("Nie wybrano testu do rozwiązania!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }
}

void SecondWindow::on_actionLogout_triggered()
{
    MainClass *main_class=MainClass::getInstance();
    main_class->logoutUser();
    ui->tableWidgetChooseMyTest->clear();
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
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mEditTestWindow->width()) / 2;
        int y = (screenGeometry.height()- mEditTestWindow->height()) / 2;
        mEditTestWindow->move(x, y);
        mEditTestWindow->show();
        this->hide();
    }else{
        mWarningMessageDialog = new WarningMessageDialog("Nie wybrano testu do edycji!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }
}

void SecondWindow::closeEvent (QCloseEvent *event){
    emit exit();
}
