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


}





void startdialog::on_startButton_clicked()
{
    emit size(x_,y_);
    accept();
}

void startdialog::on_mapSizeButton_clicked()
{

}

void startdialog::on_QuitButton_clicked()
{

}
