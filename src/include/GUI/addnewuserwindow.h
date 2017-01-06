#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

#include <QMainWindow>
#include <logic/mainclass.h>

namespace Ui {
class AddNewUserWindow;
}

class AddNewUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewUserWindow(QMainWindow *previous, const MainClass& main_class, QWidget *parent = 0);
    ~AddNewUserWindow();

private slots:
    void on_pushButtonAddNewUser_clicked();

private:
    QMainWindow *mPrevious;
    Ui::AddNewUserWindow *ui;
    MainClass mMainClass;
};

#endif // ADDNEWUSERWINDOW_H
