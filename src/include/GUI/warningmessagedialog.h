//!
/*!
  \brief Class which represents warning messages
  \author Aleksandra Grzegorczyk
*/
#ifndef WARNINGMESSAGEDIALOG_H
#define WARNINGMESSAGEDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class WarningMessageDialog;
}

class WarningMessageDialog : public QDialog
{
    Q_OBJECT

public:
    //! WarningMessageDialog constructor.
        /*!
      \param message warning message content
      \param parent pointer to parent window
        */
    explicit WarningMessageDialog(QString message, QWidget *parent = 0);
    ~WarningMessageDialog();

private slots:
    //!  exit() signal
    /*!
      Close warning message dialog
    */
    void on_pushButtonOk_clicked();

private:
    Ui::WarningMessageDialog *ui;
};

#endif // WARNINGMESSAGEDIALOG_H
