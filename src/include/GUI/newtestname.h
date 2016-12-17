#ifndef NEWTESTNAME_H
#define NEWTESTNAME_H

#include <QDialog>
#include "addnewtestwindow.h"

namespace Ui {
class NewTestName;
}

class NewTestName : public QDialog
{
    Q_OBJECT

public:
    explicit NewTestName(QMainWindow *previous, QWidget *parent = 0);
    ~NewTestName();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    QMainWindow *previous;
    AddNewTestWindow *addNewTestWindow;
    Ui::NewTestName *ui;
};

#endif // NEWTESTNAME_H
