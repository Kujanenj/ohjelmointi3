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
    void buildingType(std::string);
private slots:


    void on_MeleeAltarButton_clicked();

    void on_RangedAltarButton_clicked();

    void on_MageAltarButton_clicked();

    void on_Quarry_clicked();

    void on_Sawmill_clicked();

    void on_Lifepump_clicked();

private:
    Ui::buildingDialog *ui;
    QGraphicsScene* scene;

};

#endif // BUILDINGDIALOG_H
