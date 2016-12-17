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

private slots:
    void on_pushButton_clicked();

    void on_actionLogout_triggered();

    void on_pushButton_dodaj_test_clicked();

    void on_pushButton_edytuj_test_clicked();

private:
    QMainWindow *previous;
    SolveTestWindow *solveTestWindow;
    NewTestName *newTestName;
    AddNewTestWindow *editTestWindow;
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
