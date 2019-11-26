#include "enddialog.h"
#include "ui_enddialog.h"

endDialog::endDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endDialog)
{
    ui->setupUi(this);
    setWindowTitle("GameOver");
}

endDialog::~endDialog()
{
    delete ui;
}

void endDialog::setEndText(std::string text)
{
    ui->EndLabel->setText(QString::fromStdString(text));
}

void endDialog::on_okButton_clicked()
{
    accept();
}
