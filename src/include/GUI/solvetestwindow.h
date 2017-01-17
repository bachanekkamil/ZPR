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
    explicit SolveTestWindow(QMainWindow *previous, QWidget *parent = 0);
    ~SolveTestWindow();

signals:
    void testTaken();

private slots:

    void on_pushButtonEndTest_clicked();
    void on_pushButtonEvaluate_clicked();
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
