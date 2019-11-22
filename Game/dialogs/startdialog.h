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



    void on_startButton_clicked();

    void on_mapSizeButton_clicked();

    void on_QuitButton_clicked();

private:
    Ui::startdialog *ui;
    int x_=10;
    int y_=10;
};

#endif // STARTDIALOG_H
