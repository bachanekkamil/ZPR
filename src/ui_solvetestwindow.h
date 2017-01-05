/********************************************************************************
** Form generated from reading UI file 'solvetestwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLVETESTWINDOW_H
#define UI_SOLVETESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SolveTestWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_zakoncz_test;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SolveTestWindow)
    {
        if (SolveTestWindow->objectName().isEmpty())
            SolveTestWindow->setObjectName(QStringLiteral("SolveTestWindow"));
        SolveTestWindow->resize(400, 500);
        centralwidget = new QWidget(SolveTestWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_zakoncz_test = new QPushButton(centralwidget);
        pushButton_zakoncz_test->setObjectName(QStringLiteral("pushButton_zakoncz_test"));

        verticalLayout->addWidget(pushButton_zakoncz_test);

        SolveTestWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SolveTestWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        SolveTestWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SolveTestWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SolveTestWindow->setStatusBar(statusbar);

        retranslateUi(SolveTestWindow);

        QMetaObject::connectSlotsByName(SolveTestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SolveTestWindow)
    {
        SolveTestWindow->setWindowTitle(QApplication::translate("SolveTestWindow", "MainWindow", 0));
        label->setText(QApplication::translate("SolveTestWindow", "Pytanie:", 0));
        label_3->setText(QApplication::translate("SolveTestWindow", "Post\304\231p: ", 0));
        label_4->setText(QApplication::translate("SolveTestWindow", "1/10", 0));
        label_2->setText(QApplication::translate("SolveTestWindow", "Odpowied\305\272:", 0));
        pushButton->setText(QApplication::translate("SolveTestWindow", "Poka\305\274 odpowied\305\272", 0));
        pushButton_2->setText(QApplication::translate("SolveTestWindow", "Poprawnie", 0));
        pushButton_3->setText(QApplication::translate("SolveTestWindow", "Niepoprawnie", 0));
        pushButton_zakoncz_test->setText(QApplication::translate("SolveTestWindow", "Zako\305\204cz test", 0));
    } // retranslateUi

};

namespace Ui {
    class SolveTestWindow: public Ui_SolveTestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVETESTWINDOW_H
