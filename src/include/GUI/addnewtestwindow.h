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
    explicit AddNewTestWindow(QMainWindow *previous, QWidget *parent = 0);
    ~AddNewTestWindow();

private slots:
    void on_pushButtonEndTestEditing_clicked();
    void on_pushButtonNext_clicked();
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
