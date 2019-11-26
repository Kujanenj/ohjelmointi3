#include "buildingdialog.h"
#include "ui_buildingdialog.h"
#include <QDebug>

buildingDialog::buildingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buildingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Buildings");
}

buildingDialog::~buildingDialog()
{
    delete ui;
}






void buildingDialog::on_MeleeAltarButton_clicked()
{
    emit buildingType("Melee");
    accept();
}

void buildingDialog::on_RangedAltarButton_clicked()
{
    emit buildingType("Ranged");
    accept();
}

void buildingDialog::on_MageAltarButton_clicked()
{
    emit buildingType("Mage");
    accept();
}

void buildingDialog::on_Quarry_clicked()
{
    emit buildingType("Quarry");
    accept();
}

void buildingDialog::on_Sawmill_clicked()
{
    emit buildingType("Sawmill");
    accept();
}

void buildingDialog::on_Lifepump_clicked()
{
    emit buildingType("Lifepump");
    accept();
}
