//!
/*!
  \brief Contains class method implementation which enables adding new questions
  \author Aleksandra Grzegorczyk
*/
#include "GUI/addnewtestwindow.h"
#include "ui_addnewtestwindow.h"
#include "logic/mainclass.h"
#include "mainclassexception.h"
#include <algorithm>
#include <QDesktopWidget>

AddNewTestWindow::AddNewTestWindow(QMainWindow *previous, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewTestWindow)
{
    this->mPrevious=previous;
    ui->setupUi(this);

    MainClass *main_class=MainClass::getInstance();

    ui->labelTestNameValue->setText(main_class->getCurrentlyEditedTest()->getTestName());

    mProgress=1;
    mInitialQuestionNumber=main_class->getCurrentlyEditedTest()->getNumberOfQuestions();
    unsigned int temp=1;
    QString progress_label= QString::number(mProgress) + "/" + QString::number(std::max(temp,mInitialQuestionNumber));
    ui->labelProgressValue->setText(progress_label);

    if(mInitialQuestionNumber!=0){
        ui->textEditQuestion->setText(main_class->getCurrentlyEditedTest()->getAllQuestions().front()->getText());
        ui->textEditAnswer->setText(main_class->getCurrentlyEditedTest()->getAllQuestions().front()->getCorrectAnswerText());
    }

    ui->pushButtonPrevious->hide();
}

AddNewTestWindow::~AddNewTestWindow()
{
    delete mWarningMessageDialog;
    delete ui;
}

void AddNewTestWindow::on_pushButtonEndTestEditing_clicked()
{
    MainClass *main_class=MainClass::getInstance();
    unsigned int current_number_of_question=main_class->getCurrentlyEditedTest()->getNumberOfQuestions();

    if(current_number_of_question>0){
        // if we are viewing existing question
        if(mProgress<=current_number_of_question){

            if(!ui->textEditQuestion->toPlainText().isEmpty() && !ui->textEditAnswer->toPlainText().isEmpty()){
                try{
                    main_class->modifyQuestion(mProgress-1, ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
                    mPrevious->show();
                    this->close();
                }catch(MainClassException &e){
                    mWarningMessageDialog= new WarningMessageDialog("Nie udało się zmodyfikować pytania!");
                    QRect screenGeometry = QApplication::desktop()->screenGeometry();
                    int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                    int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                    mWarningMessageDialog->move(x, y);
                    mWarningMessageDialog->show();
                }

            }else{
                mWarningMessageDialog= new WarningMessageDialog("Pytanie i odpowiedź nie mogą być puste!");
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                mWarningMessageDialog->move(x, y);
                mWarningMessageDialog->show();
            }

        }else{

            if(!ui->textEditQuestion->toPlainText().isEmpty() && !ui->textEditAnswer->toPlainText().isEmpty()){
                try{
                    main_class->addQuestion(ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
                    mPrevious->show();
                    this->close();
                }catch(MainClassException &e){
                    mWarningMessageDialog= new WarningMessageDialog("Nie udało się dodać pytania do bazy!");
                    QRect screenGeometry = QApplication::desktop()->screenGeometry();
                    int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                    int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                    mWarningMessageDialog->move(x, y);
                    mWarningMessageDialog->show();
                }

            }else{
                mPrevious->show();
                this->close();
            }
        }

    }else{
        mWarningMessageDialog= new WarningMessageDialog("Test nie może być pusty! Dodaj pytanie i odpowiedź!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }



}

void AddNewTestWindow::on_pushButtonNext_clicked()
{
    if(!ui->textEditQuestion->toPlainText().isEmpty() && !ui->textEditAnswer->toPlainText().isEmpty()){
        MainClass *main_class=MainClass::getInstance();
        unsigned int current_number_of_question=main_class->getCurrentlyEditedTest()->getNumberOfQuestions();
        // if current_number_of_question=0 it means user are creating new test's first question else it means user is editing existing question
        if(current_number_of_question==0){
            try{
                main_class->addQuestion(ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
            }catch(MainClassException &e){
                mWarningMessageDialog= new WarningMessageDialog("Nie udało się dodać pytania do bazy!");
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                mWarningMessageDialog->move(x, y);
                mWarningMessageDialog->show();
            }
        }else{
            if(mProgress>current_number_of_question){
                try{
                    main_class->addQuestion(ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
                }catch(MainClassException &e){
                    mWarningMessageDialog= new WarningMessageDialog("Nie udało się dodać pytania do bazy!");
                    QRect screenGeometry = QApplication::desktop()->screenGeometry();
                    int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                    int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                    mWarningMessageDialog->move(x, y);
                    mWarningMessageDialog->show();
                }
            }else{
                try{
                    main_class->modifyQuestion(mProgress-1, ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
                }catch(MainClassException &e){
                    mWarningMessageDialog= new WarningMessageDialog("Nie udało się zmodyfikować pytania!");
                    QRect screenGeometry = QApplication::desktop()->screenGeometry();
                    int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                    int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                    mWarningMessageDialog->move(x, y);
                    mWarningMessageDialog->show();
                }
\
            }
        }

        ui->textEditQuestion->clear();
        ui->textEditAnswer->clear();

        ++mProgress;

        // if we edited question and there are next to show
        if(mProgress<=current_number_of_question){
            ui->textEditQuestion->setText(main_class->getCurrentlyEditedTest()->getAllQuestions().at(mProgress-1)->getText());
            ui->textEditAnswer->setText(main_class->getCurrentlyEditedTest()->getAllQuestions().at(mProgress-1)->getCorrectAnswerText());
            QString progress_label= QString::number(mProgress) + "/" + QString::number(main_class->getCurrentlyEditedTest()->getNumberOfQuestions());
            ui->labelProgressValue->setText(progress_label);
        }else{
            QString progress_label= QString::number(mProgress) + "/" + QString::number((main_class->getCurrentlyEditedTest()->getNumberOfQuestions())+1);
            ui->labelProgressValue->setText(progress_label);
        }
        ui->pushButtonPrevious->show();

    }else{
        mWarningMessageDialog = new WarningMessageDialog("Pytanie i odpowiedź nie mogą być puste!");
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
        int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
        mWarningMessageDialog->move(x, y);
        mWarningMessageDialog->show();
    }

}

void AddNewTestWindow::on_pushButtonPrevious_clicked()
{
    MainClass *main_class=MainClass::getInstance();
    unsigned int current_number_of_question=main_class->getCurrentlyEditedTest()->getNumberOfQuestions();

    bool warning=false;

    if(!ui->textEditQuestion->toPlainText().isEmpty() && !ui->textEditAnswer->toPlainText().isEmpty()){
        // if we are viewing an existing question
        if(mProgress<=current_number_of_question){
            try{
                main_class->modifyQuestion(mProgress-1, ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
            }catch(MainClassException &e){
                mWarningMessageDialog= new WarningMessageDialog("Nie udało się zmodyfikować pytania!");
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                mWarningMessageDialog->move(x, y);
                mWarningMessageDialog->show();
            }

        }else{
            try{
                main_class->addQuestion(ui->textEditQuestion->toPlainText(), ui->textEditAnswer->toPlainText());
            }catch(MainClassException &e){
                mWarningMessageDialog= new WarningMessageDialog("Nie udało się dodać pytania do bazy!");
                QRect screenGeometry = QApplication::desktop()->screenGeometry();
                int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
                int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
                mWarningMessageDialog->move(x, y);
                mWarningMessageDialog->show();
            }
        }

    }else{
        // if we are viewing an existing question
        if(mProgress<=current_number_of_question){
            mWarningMessageDialog = new WarningMessageDialog("Pytanie i odpowiedź nie mogą być puste!");
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width()- mWarningMessageDialog->width()) / 2;
            int y = (screenGeometry.height()- mWarningMessageDialog->height()) / 2;
            mWarningMessageDialog->move(x, y);
            mWarningMessageDialog->show();
            warning=true;
        }
    }

    if(!warning){
        --mProgress;

        // show previous question

        ui->textEditQuestion->setText(main_class->getCurrentlyEditedTest()->getAllQuestions().at(mProgress-1)->getText());
        ui->textEditAnswer->setText(main_class->getCurrentlyEditedTest()->getAllQuestions().at(mProgress-1)->getCorrectAnswerText());

        QString progress_label= QString::number(mProgress) + "/" + QString::number(main_class->getCurrentlyEditedTest()->getNumberOfQuestions());
        ui->labelProgressValue->setText(progress_label);

        // hide previous button if we reached first question in the test

        if(mProgress==1){
            ui->pushButtonPrevious->hide();
        }
    }

}

void AddNewTestWindow::closeEvent (QCloseEvent *event){
    mPrevious->show();
}
