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

private:
    Ui::buildingDialog *ui;
    QGraphicsScene* scene;
};

#endif // BUILDINGDIALOG_H
