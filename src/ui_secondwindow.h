/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QAction *actionLogout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_edytuj_test;
    QPushButton *pushButton_dodaj_test;
    QMenuBar *menubar;
    QMenu *menuOpcje;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QStringLiteral("SecondWindow"));
        SecondWindow->resize(400, 500);
        actionLogout = new QAction(SecondWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        centralwidget = new QWidget(SecondWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        font.setStrikeOut(false);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(centralwidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_edytuj_test = new QPushButton(centralwidget);
        pushButton_edytuj_test->setObjectName(QStringLiteral("pushButton_edytuj_test"));

        verticalLayout->addWidget(pushButton_edytuj_test);

        pushButton_dodaj_test = new QPushButton(centralwidget);
        pushButton_dodaj_test->setObjectName(QStringLiteral("pushButton_dodaj_test"));

        verticalLayout->addWidget(pushButton_dodaj_test);

        SecondWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecondWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        menuOpcje = new QMenu(menubar);
        menuOpcje->setObjectName(QStringLiteral("menuOpcje"));
        SecondWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SecondWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SecondWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpcje->menuAction());
        menuOpcje->addAction(actionLogout);

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "MainWindow", 0));
        actionLogout->setText(QApplication::translate("SecondWindow", "Logout", 0));
        label->setText(QApplication::translate("SecondWindow", "Wyb\303\263r testu", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SecondWindow", "Test1", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("SecondWindow", "Test2", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("SecondWindow", "Rozwi\304\205\305\274", 0));
        pushButton_edytuj_test->setText(QApplication::translate("SecondWindow", "Edytuj test", 0));
        pushButton_dodaj_test->setText(QApplication::translate("SecondWindow", "Dodaj test", 0));
        menuOpcje->setTitle(QApplication::translate("SecondWindow", "Opcje", 0));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
