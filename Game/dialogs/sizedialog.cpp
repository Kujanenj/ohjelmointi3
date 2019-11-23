#include "sizedialog.h"
#include "ui_sizedialog.h"

SizeDialog::SizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeDialog)
{
    ui->setupUi(this);
}

SizeDialog::~SizeDialog()
{
    delete ui;
}

void SizeDialog::on_Small_clicked()
{
    size_=10;
    emit Msize(size_);
    accept();
}

void SizeDialog::on_Medium_clicked()
{
   size_=15;
   emit Msize(size_);
   accept();
}

void SizeDialog::on_Large_clicked()
{
    size_=20;
    emit Msize(size_);
    accept();
}
