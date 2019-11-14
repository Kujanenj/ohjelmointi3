#ifndef BUILDINGDIALOG_H
#define BUILDINGDIALOG_H

#include <QDialog>

#include <QGraphicsScene>
namespace Ui {
class buildingDialog;
}

class buildingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit buildingDialog(QWidget *parent = nullptr);
    ~buildingDialog();

signals:
    void buildingType(int);
private slots:
    void on_farmButton_clicked();

    void on_headQuartersButton_clicked();

private:
    Ui::buildingDialog *ui;
    QGraphicsScene* scene;
    enum buildingtypes{farm, headquarters};
};

#endif // BUILDINGDIALOG_H
