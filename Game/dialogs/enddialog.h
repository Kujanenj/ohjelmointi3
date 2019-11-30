#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include <QDialog>

namespace Ui {
class endDialog;
}
/**
 * @brief The endDialog class Shows the end message
 */
class endDialog : public QDialog
{
    Q_OBJECT

public:
    explicit endDialog(QWidget *parent = nullptr);
    ~endDialog() override;
void setEndText(const std::string &text);
private slots:
void on_okButton_clicked();

private:
    Ui::endDialog *ui;
};

#endif // ENDDIALOG_H
