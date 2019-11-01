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
