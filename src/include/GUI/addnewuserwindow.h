#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

#include <QMainWindow>
#include <logic/mainclass.h>
#include <QCloseEvent>

namespace Ui {
class AddNewUserWindow;
}

class AddNewUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewUserWindow(QMainWindow *previous, QWidget *parent = 0);
    ~AddNewUserWindow();

signals:
    void newUserAdded();

private slots:
    void on_pushButtonAddNewUser_clicked();
    void on_pushButtonCancel_clicked();

private:
    void closeEvent(QCloseEvent *event);
    QMainWindow *mPrevious;
    Ui::AddNewUserWindow *ui;
    MainClass *mMainClass;
};

#endif // ADDNEWUSERWINDOW_H
