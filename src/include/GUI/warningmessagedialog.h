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
    explicit WarningMessageDialog(QString message, QWidget *parent = 0);
    ~WarningMessageDialog();

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::WarningMessageDialog *ui;
};

#endif // WARNINGMESSAGEDIALOG_H
