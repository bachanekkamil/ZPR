//!
/*!
  \brief Class which represents window where user can choose test to resolve and browse existing tests
  \author Aleksandra Grzegorczyk
*/
#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "solvetestwindow.h"
#include "addnewtestwindow.h"
#include "newtestname.h"
#include "warningmessagedialog.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! SecondWindow constructor.
        /*!
      \param previous pointer to pevious window
      \param parent pointer to parent window
        */
    explicit SecondWindow(QMainWindow *previous, QWidget *parent = 0);
    ~SecondWindow();

signals:
    //!  exit() signal
    /*!
      Informs previous window that exit was requested by user
    */
    void exit();

public slots:
    //!  newTestAdded() slot
    /*!
      Refreshes test list
    */
    void newTestAdded();

    //!  concreteTestsListChanged slot
    /*!
      Refreshes concreteTest list
    */
    void concreteTestsListChanged();

private slots:
    //!  on_pushButtonTakeTest_clicked slot
    /*!
      Starts choosen concreteTest
    */
    void on_pushButtonTakeTest_clicked();

    //!  on_pushButtonDeleteTest_clicked slot
    /*!
      Deletes choosen concreteTest
    */
    void on_pushButtonDeleteTest_clicked();

    //!  on_pushButtonTakeNewTest_clicked slot
    /*!
      Starts new test for current user
    */
    void on_pushButtonTakeNewTest_clicked();

    //!  on_actionLogout_triggered slot
    /*!
      Logout user
    */
    void on_actionLogout_triggered();

    //!  on_pushButtonAddTest_clicked slot
    /*!
      Shows window for creating new test name
    */
    void on_pushButtonAddTest_clicked();

    //!  on_pushButtonEditTest_clicked( slot
    /*!
      Shows edit window for choosen test
    */
    void on_pushButtonEditTest_clicked();

private:
    void closeEvent(QCloseEvent *event);
    QMainWindow *mPrevious;
    SolveTestWindow *mSolveTestWindow;
    NewTestName *mNewTestName;
    AddNewTestWindow *mAddNewTestWindow;
    AddNewTestWindow *mEditTestWindow;
    WarningMessageDialog *mWarningMessageDialog;
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
