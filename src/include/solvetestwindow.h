#ifndef SOLVETESTWINDOW_H
#define SOLVETESTWINDOW_H

#include <QMainWindow>

namespace Ui {
class SolveTestWindow;
}

class SolveTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SolveTestWindow(QMainWindow *previous, QWidget *parent = 0);
    ~SolveTestWindow();

private slots:

    void on_pushButton_zakoncz_test_clicked();

private:
    QMainWindow *previous;
    Ui::SolveTestWindow *ui;
};

#endif // SOLVETESTWINDOW_H
