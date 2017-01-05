/********************************************************************************
** Form generated from reading UI file 'addnewtestwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWTESTWINDOW_H
#define UI_ADDNEWTESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewTestWindow
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
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_zakoncz_edycje_testu;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddNewTestWindow)
    {
        if (AddNewTestWindow->objectName().isEmpty())
            AddNewTestWindow->setObjectName(QStringLiteral("AddNewTestWindow"));
        AddNewTestWindow->resize(400, 500);
        centralwidget = new QWidget(AddNewTestWindow);
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

        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout->addWidget(textEdit_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_zakoncz_edycje_testu = new QPushButton(centralwidget);
        pushButton_zakoncz_edycje_testu->setObjectName(QStringLiteral("pushButton_zakoncz_edycje_testu"));

        verticalLayout->addWidget(pushButton_zakoncz_edycje_testu);

        AddNewTestWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddNewTestWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        AddNewTestWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddNewTestWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddNewTestWindow->setStatusBar(statusbar);

        retranslateUi(AddNewTestWindow);

        QMetaObject::connectSlotsByName(AddNewTestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddNewTestWindow)
    {
        AddNewTestWindow->setWindowTitle(QApplication::translate("AddNewTestWindow", "MainWindow", 0));
        label->setText(QApplication::translate("AddNewTestWindow", "Pytanie:", 0));
        label_3->setText(QApplication::translate("AddNewTestWindow", "Post\304\231p:", 0));
        label_4->setText(QApplication::translate("AddNewTestWindow", "1/1", 0));
        label_2->setText(QApplication::translate("AddNewTestWindow", "Odpowied\305\272:", 0));
        pushButton->setText(QApplication::translate("AddNewTestWindow", "Poprzednie", 0));
        pushButton_2->setText(QApplication::translate("AddNewTestWindow", "Nast\304\231pne", 0));
        pushButton_zakoncz_edycje_testu->setText(QApplication::translate("AddNewTestWindow", "Zako\305\204cz edycje testu", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNewTestWindow: public Ui_AddNewTestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWTESTWINDOW_H
