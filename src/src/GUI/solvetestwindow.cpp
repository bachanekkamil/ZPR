//!
/*!
  \brief Contains class method implementation used to crrying out tests and saving users answers
  \author Aleksandra Grzegorczyk
*/
#include "GUI/solvetestwindow.h"
#include "ui_solvetestwindow.h"
#include "logic/mainclass.h"
#include "mainclassexception.h"
#include <QDesktopWidget>
#include <QDebug>

SolveTestWindow::SolveTestWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolveTestWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);

    MainClass *main_class=MainClass::getInstance();
    ui->labelTestName->setText(main_class->getCurrentConcreteTest()->getTestName());
    mProgress=1;
    mInitialQuestionNumber=main_class->getCurrentConcreteTest()->getQuestionsForToday().size();
    unsigned int temp=1;
    QString progress_label= QString::number(mProgress) + "/" + QString::number(std::max(temp,mInitialQuestionNumber));
    ui->labelProgressValue->setText(progress_label);

    QStringList marks;
    for(int i=1; i<6; i++){
        marks << QString::number(i);
    }
    ui->comboBoxMark->addItems(marks);

    ui->textEditQuestion->setText(main_class->getCurrentConcreteTest()->getQuestionsForToday()[0]->getText());

    ui->textEditAnswer->setReadOnly(true);
    ui->textEditQuestion->setReadOnly(true);
}

SolveTestWindow::~SolveTestWindow()
{
    delete mWarningMessageDialog;
    delete ui;
}

void SolveTestWindow::on_pushButtonEndTest_clicked()
{
    MainClass::getInstance()->generateNewScheduler();
    emit testTaken();
    mPrevious->show();
    this->close();
}

void SolveTestWindow::on_pushButtonEvaluate_clicked(){

    if(ui->textEditAnswer->toPlainText().size()>0){
        MainClass *main_class=MainClass::getInstance();
        if(mInitialQuestionNumber>mProgress){
            try{
                main_class->addAnswerToCurrentConcreteTest(mProgress-1, ui->comboBoxMark->currentText().toShort());
                qDebug() << "Dodanie oceny pytania do bazy";
                ui->textEditAnswer->clear();
                ui->textEditQuestion->setText(main_class->getCurrentConcreteTest()->getQuestionsForToday()[mProgress]->getText());
                ++mProgress;
                QString progress_label= QString::number(mProgress) + "/" + QString::number(mInitialQuestionNumber);
                ui->labelProgressValue->setText(progress_label);
            }catch(MainClassException &e){
                qDebug() << "Exception " << e.what();
                mWarningMessageDialog= new WarningMessageDialog("Nie udało się dodać oceny do odpowiedzi!");
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                mWarningMessageDialog->move(x, y);
                mWarningMessageDialog->show();
            }

        }else {
            main_class->addAnswerToCurrentConcreteTest(mProgress-1, ui->comboBoxMark->currentText().toShort());
            qDebug() << "Dodanie oceny pytania do bazy";
            on_pushButtonEndTest_clicked();
        }
    }else{
        mWarningMessageDialog= new WarningMessageDialog("Przed podaniem oceny zobacz poprawną odpowiedź!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }

}

void SolveTestWindow::on_pushButtonShowAnswer_clicked(){
    MainClass *main_class=MainClass::getInstance();
    ui->textEditAnswer->setText(main_class->getCurrentConcreteTest()->getQuestionsForToday()[mProgress-1]->getCorrectAnswerText());
}

void SolveTestWindow::closeEvent (QCloseEvent *event){
    mPrevious->show();
}
