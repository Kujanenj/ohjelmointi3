#include "buildingdialog.h"
#include "ui_buildingdialog.h"

buildingDialog::buildingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buildingDialog)
{
    ui->setupUi(this);
}

buildingDialog::~buildingDialog()
{
    delete ui;
}

void buildingDialog::on_farmButton_clicked()
{
    emit buildingType(farm);
    accept();
}

void buildingDialog::on_headQuartersButton_clicked()
{
   emit buildingType(headquarters);
    accept();
}
