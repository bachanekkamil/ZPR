#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "solvetestwindow.h"
#include "addnewtestwindow.h"
#include "newtestname.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QMainWindow *previous, QWidget *parent = 0);
    ~SecondWindow();

public slots:
    void newTestAdded();

private slots:
    void on_pushButtonTakeTest_clicked();

    void on_pushButtonTakeNewTest_clicked();

    void on_actionLogout_triggered();

    void on_pushButtonAddTest_clicked();

    void on_pushButtonEditTest_clicked();

private:
    QMainWindow *mPrevious;
    SolveTestWindow *mSolveTestWindow;
    NewTestName *mNewTestName;
    AddNewTestWindow *mAddNewTestWindow;
    AddNewTestWindow *mEditTestWindow;
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
