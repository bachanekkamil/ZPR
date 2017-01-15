#include "GUI/solvetestwindow.h"
#include "ui_solvetestwindow.h"
#include "logic/mainclass.h"

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
}

SolveTestWindow::~SolveTestWindow()
{
    delete mWarningMessageDialog;
    delete ui;
}

void SolveTestWindow::on_pushButtonEndTest_clicked()
{
    MainClass::getInstance()->generateNewScheduler();
    mPrevious->show();
    this->close();
}

void SolveTestWindow::on_pushButtonEvaluate_clicked(){

    if(ui->textEditAnswer->toPlainText().size()>1){
        if(mInitialQuestionNumber>mProgress){
            MainClass *main_class=MainClass::getInstance();
            main_class->addAnswerToCurrentConcreteTest(mProgress-1, ui->comboBoxMark->currentText().toShort());
            ui->textEditAnswer->clear();
            ui->textEditQuestion->setText(main_class->getCurrentConcreteTest()->getQuestionsForToday()[mProgress]->getText());
            ++mProgress;
            QString progress_label= QString::number(mProgress) + "/" + QString::number(mInitialQuestionNumber);
            ui->labelProgressValue->setText(progress_label);
        }else{
            on_pushButtonEndTest_clicked();
        }
    }else{
        mWarningMessageDialog= new WarningMessageDialog("Przed podaniem oceny zobacz poprawną odpowiedź!");
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
