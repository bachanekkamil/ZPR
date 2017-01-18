//!
/*!
  \brief Class which represents creating new test questions and also modifying already existing tests
  \author Aleksandra Grzegorczyk
*/
#ifndef ADDNEWTESTWINDOW_H
#define ADDNEWTESTWINDOW_H

#include <QMainWindow>
#include "warningmessagedialog.h"

namespace Ui {
class AddNewTestWindow;
}

class AddNewTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! AddNewTestWindow constructor.
        /*!
      \param previous pointer to pevious window
      \param parent pointer to parent window
        */
    explicit AddNewTestWindow(QMainWindow *previous, QWidget *parent = 0);
    ~AddNewTestWindow();

private slots:
    //!  on_pushButtonEndTestEditing_clicked() slot
    /*!
      Slot which saves changes to last edited question
    */
    void on_pushButtonEndTestEditing_clicked();

    //!  on_pushButtonNext_clicked slot
    /*!
      Slot which saves changes to last edited question and shows next one (if there is more questions)
    */
    void on_pushButtonNext_clicked();

    //!  on_pushButtonPrevious_clicked slot
    /*!
      Slot which saves chanches to last edited question and shows previous one (if last one wasn't first in the test)
    */
    void on_pushButtonPrevious_clicked();

private:
    void closeEvent(QCloseEvent *event);
    QMainWindow *mPrevious;
    WarningMessageDialog *mWarningMessageDialog;
    Ui::AddNewTestWindow *ui;
    unsigned int mProgress;
    unsigned int mInitialQuestionNumber;
};

#endif // ADDNEWTESTWINDOW_H
