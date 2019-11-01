#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class startdialog;
}

class startdialog : public QDialog
{
    Q_OBJECT

public:
    explicit startdialog(QWidget *parent = nullptr);
    ~startdialog();

private:
    Ui::startdialog *ui;
};

#endif // STARTDIALOG_H
