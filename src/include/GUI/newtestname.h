//!
/*!
  \brief Class which represents creating new test
  \author Aleksandra Grzegorczyk
*/

#ifndef NEWTESTNAME_H
#define NEWTESTNAME_H

#include <QDialog>
#include "addnewtestwindow.h"
#include "warningmessagedialog.h"

namespace Ui {
class NewTestName;
}

class NewTestName : public QDialog
{
    Q_OBJECT

public:
    //! NewTestName constructor.
        /*!
      \param previous pointer to pevious window
      \param parent pointer to parent window
        */
    explicit NewTestName(QMainWindow *previous, QWidget *parent = 0);
    ~NewTestName();

signals:
    //!  newTestNameAccepted() signal
    /*!
      Informs previous window that new test was created
    */
    void newTestNameAccepted();

private slots:
    //!  on_buttonBox_accepted slot
    /*!
      Add new test
    */
    void on_buttonBox_accepted();

    //!  on_buttonBox_rejected() slot
    /*!
      Cancel adding new test
    */
    void on_buttonBox_rejected();

private:
    QMainWindow *mPrevious;
    WarningMessageDialog *mWarningMessageDialog;
    Ui::NewTestName *ui;
};

#endif // NEWTESTNAME_H
