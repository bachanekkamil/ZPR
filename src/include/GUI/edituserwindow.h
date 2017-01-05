#ifndef EDITUSERWINDOW_H
#define EDITUSERWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditUserWindow;
}

class EditUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditUserWindow(QMainWindow *previous, QWidget *parent = 0);
    ~EditUserWindow();

private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonAccept_clicked();

private:
    QMainWindow *mPrevious;
    Ui::EditUserWindow *ui;
};

#endif // EDITUSERWINDOW_H
