#include "startdialog.h"
#include "ui_startdialog.h"

startdialog::startdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startdialog)
{
    ui->setupUi(this);
    connect(&SizeDialog_, SIGNAL(Msize(int)), this, SLOT(setXY(int)));
    QPixmap pic(":images/graphics/minion_blue.png");
    ui->pictureLabel->setScaledContents(true);
    ui->pictureLabel->setPixmap(pic);
    setWindowTitle("Bronze adventures");
}

startdialog::~startdialog()
{
    delete ui;


}

void startdialog::setXY(int xy)
{
    x_=xy;
    y_=xy;
}





void startdialog::on_startButton_clicked()
{
    emit size(x_,y_);
    accept();
}

void startdialog::on_mapSizeButton_clicked()
{
 SizeDialog_.exec();
}

void startdialog::on_QuitButton_clicked()
{
    reject();
    emit rejected();

}
