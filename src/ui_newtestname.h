/********************************************************************************
** Form generated from reading UI file 'newtestname.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTESTNAME_H
#define UI_NEWTESTNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewTestName
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewTestName)
    {
        if (NewTestName->objectName().isEmpty())
            NewTestName->setObjectName(QStringLiteral("NewTestName"));
        NewTestName->resize(400, 199);
        verticalLayout = new QVBoxLayout(NewTestName);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(NewTestName);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(NewTestName);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 36, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(NewTestName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewTestName);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewTestName, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewTestName, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewTestName);
    } // setupUi

    void retranslateUi(QDialog *NewTestName)
    {
        NewTestName->setWindowTitle(QApplication::translate("NewTestName", "Dialog", 0));
        label->setText(QApplication::translate("NewTestName", "Podaj nazw\304\231 nowego tekstu", 0));
    } // retranslateUi

};

namespace Ui {
    class NewTestName: public Ui_NewTestName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTESTNAME_H
