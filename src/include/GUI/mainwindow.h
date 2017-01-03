#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include "secondwindow.h"
#include <deque>
#include <memory>
#include <logic/mainclass.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

private:
    SecondWindow *window2;
    Ui::MainWindow *ui;
    MainClass mMainClass;
};

#endif // MAINWINDOW_H
