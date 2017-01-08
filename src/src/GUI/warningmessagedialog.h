#ifndef WARNINGMESSAGEDIALOG_H
#define WARNINGMESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class WarningMessageDialog;
}

class WarningMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarningMessageDialog(QWidget *parent = 0);
    ~WarningMessageDialog();

private:
    Ui::WarningMessageDialog *ui;
};

#endif // WARNINGMESSAGEDIALOG_H
