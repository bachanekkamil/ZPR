#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include "secondwindow.h"
#include <deque>
#include <memory>
#include "addnewuserwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void userListChanged();
    void exitRequested();

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonDeleteUser_clicked();
    void on_pushButtonAddUser_clicked();

private:
    SecondWindow *mSecondWindow;
    AddNewUserWindow *mAddNewUserWindow;
    WarningMessageDialog *mWarningMessageDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
