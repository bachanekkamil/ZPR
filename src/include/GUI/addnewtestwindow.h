#ifndef ADDNEWTESTWINDOW_H
#define ADDNEWTESTWINDOW_H

#include <QMainWindow>

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

private:
    QMainWindow *mPrevious;
    Ui::AddNewTestWindow *ui;
};

#endif // ADDNEWTESTWINDOW_H
