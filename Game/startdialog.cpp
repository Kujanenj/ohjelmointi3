#include "startdialog.h"
#include "ui_startdialog.h"

startdialog::startdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startdialog)
{
    ui->setupUi(this);
}

startdialog::~startdialog()
{
    delete ui;
    QObject::connect(ui->buttonBox, &QDialogButtonBox::accepted, this,  &QDialog::accept);

}

void startdialog::on_mapsizeslider_sliderMoved(int position)
{
    x_=position;
    y_=position;


}

void startdialog::on_buttonBox_accepted()
{
    emit size(x_,y_);
}
