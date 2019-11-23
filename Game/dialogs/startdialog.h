#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include "dialogs/sizedialog.h"

namespace Ui {
class startdialog;
}

class startdialog : public QDialog
{
    Q_OBJECT

public:
    explicit startdialog(QWidget *parent = nullptr);
    ~startdialog();
public slots:
    void setXY(int xy);
signals:
    void size(int, int);
private slots:



    void on_startButton_clicked();

    void on_mapSizeButton_clicked();

    void on_QuitButton_clicked();

private:
    Ui::startdialog *ui;
    int x_=10;
    int y_=10;
    SizeDialog SizeDialog_;

};

#endif // STARTDIALOG_H
