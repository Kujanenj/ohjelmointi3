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
signals:
    void size(int, int);
private slots:

    void on_mapsizeslider_sliderMoved(int position);

    void on_buttonBox_accepted();

private:
    Ui::startdialog *ui;
    int x_=10;
    int y_=10;
};

#endif // STARTDIALOG_H
