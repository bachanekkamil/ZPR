//!
/*!
  \brief Class which represents creating new user
  \author Aleksandra Grzegorczyk
*/
#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

#include <QMainWindow>
#include <logic/mainclass.h>
#include <QCloseEvent>
#include "warningmessagedialog.h"

namespace Ui {
class AddNewUserWindow;
}

class AddNewUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! AddNewUserWindow constructor.
        /*!
      \param previous pointer to pevious window
      \param parent pointer to parent window
        */
    explicit AddNewUserWindow(QMainWindow *previous, QWidget *parent = 0);
    ~AddNewUserWindow();

signals:
    //!  newUserAdded() signal
    /*!
      Inform previous window that new user was added
    */
    void newUserAdded();

private slots:
    //!  on_pushButtonAddNewUser_clicked() slot
    /*!
      Adds new user
    */
    void on_pushButtonAddNewUser_clicked();

    //!  on_pushButtonCancel_clicked slot
    /*!
      Cancels adding new user
    */
    void on_pushButtonCancel_clicked();

private:
    void closeEvent(QCloseEvent *event);
    QMainWindow *mPrevious;
    WarningMessageDialog *mWarningMessageDialog;
    Ui::AddNewUserWindow *ui;
};

#endif // ADDNEWUSERWINDOW_H
