//!
/*!
  \brief Class which represents first window, where logging takes place
  \author Aleksandra Grzegorczyk
*/
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
    //! MainWindow constructor.
        /*!
      \param parent pointer to parent window
        */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //!  userListChanged() slot
    /*!
      Refresh user list
    */
    void userListChanged();

    //!  exitRequested() slot
    /*!
      Exit from appliction
    */
    void exitRequested();

private slots:
    //!  on_pushButtonLogin_clicked slot
    /*!
      Login user which was choosen from user list
    */
    void on_pushButtonLogin_clicked();

    //!  on_pushButtonDeleteUser_clicked slot
    /*!
      Deletes user
    */
    void on_pushButtonDeleteUser_clicked();

    //!  on_pushButtonAddUser_clicked slot
    /*!
      Creates new window for creating new user
    */
    void on_pushButtonAddUser_clicked();

private:
    SecondWindow *mSecondWindow;
    AddNewUserWindow *mAddNewUserWindow;
    WarningMessageDialog *mWarningMessageDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
