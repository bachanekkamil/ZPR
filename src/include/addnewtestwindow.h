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
    void on_pushButton_zakoncz_edycje_testu_clicked();

private:
    QMainWindow *previous;
    Ui::AddNewTestWindow *ui;
};

#endif // ADDNEWTESTWINDOW_H
