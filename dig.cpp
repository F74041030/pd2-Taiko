#include "dig.h"
#include "ui_dig.h"

dig::dig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dig)
{
    ui->setupUi(this);
    ui->pushButton->setText("start");
    ui->pushButton_2->setText("exit");
}

dig::~dig()
{
    delete ui;
}

void dig::on_pushButton_clicked()
{
    this -> hide();
    emit showmainwindow();
}

void dig::on_pushButton_2_clicked()
{

    this -> close();
    emit allclose();
}
void dig::receivelogout()
{
    dig *d = new dig;
    this->show();
}
