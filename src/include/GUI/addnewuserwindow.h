#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddNewUserWindow;
}

class AddNewUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewUserWindow(QMainWindow *previous, QWidget *parent = 0);
    ~AddNewUserWindow();

private slots:
    void on_pushButtonAddNewUser_clicked();

private:
    QMainWindow *mPrevious;
    Ui::AddNewUserWindow *ui;
};

#endif // ADDNEWUSERWINDOW_H
