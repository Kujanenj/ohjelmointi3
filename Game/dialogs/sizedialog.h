#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>

namespace Ui {
class SizeDialog;
}
/**
 * @brief The SizeDialog class Sets the mapSize
 */
class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QWidget *parent = nullptr);
    ~SizeDialog()override;
signals:
    void Msize(int);
private slots:
    void on_Small_clicked();

    void on_Medium_clicked();

    void on_Large_clicked();

private:
    Ui::SizeDialog *ui;
    int size_=10;
};

#endif // SIZEDIALOG_H
