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




void buildingDialog::on_nexus_Button_clicked()
{
    emit buildingType("Nexus");
    accept();
}

void buildingDialog::on_MeleeAltarButton_clicked()
{
    emit buildingType("Melee");
    accept();
}
