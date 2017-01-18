//!
/*!
  \brief Class which represents solving test
  \author Aleksandra Grzegorczyk
*/


#ifndef SOLVETESTWINDOW_H
#define SOLVETESTWINDOW_H

#include <QMainWindow>
#include "warningmessagedialog.h"

namespace Ui {
class SolveTestWindow;
}

class SolveTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! SolveTestWindow constructor.
        /*!
      \param previous pointer to pevious window
      \param parent pointer to parent window
        */
    explicit SolveTestWindow(QMainWindow *previous, QWidget *parent = 0);
    ~SolveTestWindow();

signals:
    //!  newTestNameAccepted() signal
    /*!
      Informs previous window that user finished test
    */
    void testTaken();

private slots:
    //!  on_pushButtonEndTest_clicked slot
    /*!
      Ends test
    */
    void on_pushButtonEndTest_clicked();

    //!  on_pushButtonEvaluate_clicked slot
    /*!
      Saves user answer and show next question (if there is one)
    */
    void on_pushButtonEvaluate_clicked();

    //!  on_pushButtonShowAnswer_clicked slot
    /*!
      Shows correct answer
    */
    void on_pushButtonShowAnswer_clicked();

private:
    void closeEvent(QCloseEvent *event);
    QMainWindow *mPrevious;
    Ui::SolveTestWindow *ui;
    unsigned int mProgress;
    unsigned int mInitialQuestionNumber;
    WarningMessageDialog *mWarningMessageDialog;
};

#endif // SOLVETESTWINDOW_H
